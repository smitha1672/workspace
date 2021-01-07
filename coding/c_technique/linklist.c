#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#define MEMBER_SIZE(type, member) sizeof(((type *)0)->member)
#define MEMBER_ARRAY_SIZE(type, member) (sizeof(((type *)0)->member)/sizeof(((type *)0)->member[0]))

#ifndef portmemalloc
#define portmemalloc malloc
#endif

#ifndef portmemfree
#define portmemfree free
#endif

#define STATE_AVAILABLE     1
#define STATE_UNAVAILABLE   0
#define IS_AVAILABLE(x) ((x > 0)? STATE_AVAILABLE: STATE_UNAVAILABLE)

#ifndef ALOGE
#define ALOGE   printf
#endif

#ifndef ALOGD
#define ALOGD   printf
#endif

typedef struct _node_t {
    void* data;
    struct _node_t* next;
} node_t;

typedef struct _ll_t {
    node_t* head;
    node_t* tail;
    node_t* current;
} ll_t;

typedef int(*fcompare)(void*, void*);
typedef int(*fgothrough)(void*);

void*
datalist_create(void)
{
    ll_t* list = (ll_t*)portmemalloc(sizeof(ll_t));
    if (list) {
        list->head = NULL;
        list->tail = NULL;
    }
    return ((list)? list: NULL);
}

int
datalist_addhead(void* ll, void* data)
{
    int iret = STATE_AVAILABLE;
    node_t* node = NULL;
    ll_t* list = NULL;
    if (!ll || !data) {
        iret = -1;
        goto exit;
    }
    list = (ll_t*)ll;
    node = (node_t*)portmemalloc(sizeof(node_t));
    if (!node) {
        iret = -2;
        goto exit;
    }
    node->data = data;
    if (list->head == NULL) {
        list->tail = node;
        node->next = NULL;
    } else
        node->next = list->head;
    list->head = node;
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return IS_AVAILABLE(iret);
}

int
datalist_addtail(void* ll, void* data)
{
    int iret = STATE_AVAILABLE;
    node_t* node = NULL;
    ll_t* list = NULL;
    if (!ll || !data) {
        iret = -1;
        goto exit;
    }
    list = (ll_t*)ll;
    node = (node_t*)portmemalloc(sizeof(node_t));
    if (!node) {
        iret = -2;
        goto exit;
    }
    node->data = data;
    node->next = NULL;
    if (list->head == NULL)
        list->head = node;
    else
        list->tail->next = node;
    list->tail = node;
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return IS_AVAILABLE(iret);
}

void*
datalist_getnode(void* ll, fcompare callback, void* data)
{
    int iret = STATE_AVAILABLE;
    ll_t* list = NULL;
    node_t* node = NULL;
    if (!ll || !callback || !data) {
        iret = -1;
        goto exit;
    }
    list = (ll_t*)ll;
    node = list->head;
    while (node != NULL) {
        if (callback(node->data, data))
            return node;
        node = node->next;
    }
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return NULL;
}

int
datalist_deletenode(void* ll, void* data)
{
    int iret = STATE_AVAILABLE;
    ll_t* list = NULL;
    node_t* node = NULL;
    if (!ll || !data) {
        iret = -1;
        goto exit;
    }
    list = (ll_t*)ll;
    node = (node_t*)data;
    if (node == list->head) {
        if (list->head->next == NULL)
            list->head = list->tail = NULL;
        else
            list->head = list->head->next;
    } else {
        node_t* nodetmp = list->head;
        while (nodetmp && nodetmp->next != node)
            nodetmp = nodetmp->next;
        if (nodetmp)
            nodetmp->next = node->next;
    }
    portmemfree(node);
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return IS_AVAILABLE(iret);
}

int
datalist_gothrough(void* ll, fgothrough callback)
{
    int iret = STATE_AVAILABLE;
    ll_t* list = NULL;
    node_t* current = NULL;
    if (!ll || !callback) {
        iret = -1;
        goto exit;
    }
    list = (ll_t*)ll;
    current = list->head;
    while (current) {
        callback(current->data);
        current = current->next;
    }
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return IS_AVAILABLE(iret);
}

typedef struct _attributenode {
    int tag_num;
    int (*fptr)(void*);
} attributenode_t;

int
test1(void* data)
{
    printf("%s\n", __FUNCTION__);
    return 0;
}

int
test2(void* data)
{
    printf("%s\n", __FUNCTION__);
    return 0;
}

int
test3(void* data)
{
    printf("%s\n", __FUNCTION__);
    return 0;
}

int
gothrough(void* data)
{
    int iret = STATE_AVAILABLE;
    attributenode_t* ptr = NULL;
    if (!data) {
        iret = -1;
        goto exit;
    }
    ptr = (attributenode_t*)data;
    ptr->fptr(NULL);
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return IS_AVAILABLE(iret);
}

int
compare_attribute(void* e1, void* e2)
{
    int iret = STATE_UNAVAILABLE;
    attributenode_t* ptr1 = NULL;
    attributenode_t* ptr2 = NULL;
    if (!e1 || !e2) {
        iret = -1;
        goto exit;
    }
    ptr1 = (attributenode_t*)e1;
    ptr2 = (attributenode_t*)e2;
    iret = (ptr1->tag_num == ptr2->tag_num)? STATE_AVAILABLE: STATE_UNAVAILABLE;
exit:
    return IS_AVAILABLE(iret);
}

void
main(void)
{
    void* list = datalist_create();
    void* node = NULL;
    attributenode_t* attri_1 = (attributenode_t*)portmemalloc(sizeof(attributenode_t));
    attributenode_t* attri_2 = (attributenode_t*)portmemalloc(sizeof(attributenode_t));
    attributenode_t* attri_3 = (attributenode_t*)portmemalloc(sizeof(attributenode_t));

    attri_1->tag_num = 1;
    attri_1->fptr = &test1;
    datalist_addhead(list, attri_1);

    attri_2->tag_num = 2;
    attri_2->fptr = &test2;
    datalist_addhead(list, attri_2);

    attri_3->tag_num = 3;
    attri_3->fptr = &test3;
    datalist_addhead(list, attri_3);

    ALOGD("gothroug 1\n");
    datalist_gothrough(list, gothrough);

    node = datalist_getnode(list, compare_attribute, attri_2);
    if (node)
        datalist_deletenode(list, node);

    ALOGD("gothroug 2\n");
    datalist_gothrough(list, gothrough);
}


