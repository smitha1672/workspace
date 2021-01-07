#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <mqueue.h>
#include <pthread.h>
#include <unistd.h>

#include "common.h"

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_cond  = PTHREAD_COND_INITIALIZER;


static void *_msg_client(void *ptr)
{
    char buffer[MAX_SIZE];

    for (;;) {
        static int count = 0;
        mqd_t mq;
        pthread_mutex_lock(&condition_mutex);
        /* open the mail queue */
        mq = mq_open(QUEUE_NAME, O_WRONLY);
        CHECK((mqd_t)-1 != mq);
        sprintf(buffer, "%s, send, %d", __func__ ,++count);
        /* send the message */
        mq_send(mq, buffer, MAX_SIZE, 0);
        mq_close(mq);
        pthread_cond_signal(&condition_cond);
        pthread_mutex_unlock(&condition_mutex);
        sleep(1);
    }
}

static void *_msg_server( void *ptr )
{
    char *message;
    message = (char *) ptr;
    char buffer[MAX_SIZE + 1];

    for (;;) {
        static int counter = 0;
        ssize_t bytes_read;
        mqd_t mq;
        struct mq_attr attr;

        pthread_mutex_lock(&condition_mutex);
        pthread_cond_wait(&condition_cond, &condition_mutex);

        /* create the message queue */
        mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0644, &attr);
        CHECK((mqd_t)-1 != mq);
        mq_getattr (mq, &attr);
        if (attr.mq_curmsgs > 0)
            bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
        mq_close(mq);

        pthread_mutex_unlock(&condition_mutex);

        buffer[bytes_read] = '\0';
        printf("%s, %d, %zu, get, %s\n", __func__, ++counter, attr.mq_curmsgs, buffer);
    }
}


int main(int argc, char **argv)
{
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int  iret1, iret2;

    mqd_t mq;
    struct mq_attr attr;
    /* initialize the queue attributes */
    attr.mq_flags = O_NONBLOCK;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;

    mq_unlink (QUEUE_NAME);

    /* create the message queue */
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0644, &attr);
    CHECK((mqd_t)-1 != mq);

    /* Create independent threads each of which will execute function */
    iret1 = pthread_create( &thread1, NULL, _msg_client, (void*) message1);
    iret2 = pthread_create( &thread2, NULL, _msg_server, (void*) message2);

    pthread_join(thread2, NULL);
    pthread_join(thread1, NULL);

    printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);
    exit(0);
}

