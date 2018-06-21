/* File name: PolyAddList.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>

struct poly {
    int coef;   /* 多項式係數 */
    int exp;    /* 多項式指數 */
    struct poly *next;
};

struct poly *ptr, *eq_h1, *eq_h2, *ans_h;

void inputFunction(struct poly **eq_h)   /* 輸入函數 */
{
    struct poly *prev = NULL;
    char symbol = '+';
    do{
        ptr = (struct poly *) malloc(sizeof(struct poly));
        ptr->next = NULL;
        scanf("%dx^%d", &ptr->coef, &ptr->exp);
        if(*eq_h == NULL)
            *eq_h = ptr;
        else{
            if(symbol == '-') ptr->coef = -(ptr->coef);
            prev->next = ptr;
        }
        prev = ptr;
        scanf("%c", &symbol);
    }  while(symbol != '\n');
}

void poly_add(void)     /* 多項式相加函數 */
{
    struct poly *currentN1, *currentN2, *prev;
    currentN1 = eq_h1;
    currentN2 = eq_h2;
    prev = NULL;
    
    /* 當兩個多項式皆相加完畢則結束 */
    while(currentN1 != NULL || currentN2 != NULL){
        ptr = (struct poly *) malloc(sizeof(struct poly));
        ptr->next = NULL;
        /* 第一個多項式指數大於第二個多項式 */
        if(currentN1 != NULL &&
           (currentN2 == NULL || currentN1->exp > currentN2->exp)){
            ptr->coef = currentN1->coef;
            ptr->exp = currentN1->exp;
            currentN1 = currentN1->next;
        }
        else/* 第一個多項式指數小於第二個多項式 */
            if(currentN1 == NULL || currentN1->exp < currentN2->exp){
                ptr->coef = currentN2->coef;
                ptr->exp = currentN2->exp;
                currentN2 = currentN2->next;
            }
            else{  /* 兩個多項式指數相等，進行相加 */
                ptr->coef = currentN1->coef + currentN2->coef;
                ptr->exp = currentN1->exp;
                if(currentN1 != NULL) currentN1 = currentN1->next;
                if(currentN2 != NULL) currentN2 = currentN2->next;
            }
        if(ptr->coef != 0){  /* 當相加結果不等於0，則放入答案多項式中 */
            if(ans_h == NULL) ans_h = ptr;
            else prev->next = ptr;
            prev = ptr;
        }
        else free(ptr);
    }
}

void show_ans(void)	    /* 顯示多項式相加結果函數 */
{
    struct poly *currentN;
    currentN = ans_h;
    printf("The answer equation: ");
    while(currentN != NULL){
        printf("%dx^%d", currentN->coef, currentN->exp);
        if(currentN->next != NULL && currentN->next->coef >= 0)
            printf("+");
        currentN = currentN->next;
    }
    printf("\n");
}

int main()
{
    printf("****************************************\n");
    printf(" -- Polynomial add using format ax^b --\n");
    printf("****************************************\n");
    printf("Please enter the first equation: ");
    inputFunction(&eq_h1);
    printf("Please enter the second equation: ");
    inputFunction(&eq_h2);
    poly_add();
    show_ans();
    printf("\n");
    return 0;
}