/* File name: Tbintree.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

/*	定義資料結構
 rbit = 1 , rchild為正常指標, rbit =0 , rchild為引線
 lbit = 1 , lchild為正常指標, lbit =0 , lchild為引線 */

struct tbintree {
    int number;
    int rbit;
    int lbit;
    struct tbintree *lchild;
    struct tbintree *rchild;
} *root, *ptr, *newnode;

struct tbintree *newtbintree();   /*配置記憶函數*/

void insert();
void deleteNode();
void inorderShow( struct tbintree *);
void insertRight( struct tbintree *, struct tbintree *);
void insertLeft(struct tbintree *, struct tbintree * );

struct tbintree * insucc( struct tbintree * );
struct tbintree * inpred( struct tbintree * );

int main()
{
    char *menuPrompt =
    "=== Thread Binary Search Program ==\n"
    "  1. Insert\n"
    "  2. Delete\n"
    "  3. Show\n"
    "  4. Quit\n"
    "Please input a number : ";
    char menusele;
    /* 初始化 */
    /* 引線二元樹根節點不放資料: root->number不放data */
    /* 右鏈結永遠指向本身 : rbit =1 */
    root = newtbintree();
    root->lchild = root;
    root->rchild = root;
    root->lbit = 0;
    root->rbit = 1;
    do{
        printf("\n%s", menuPrompt);
        menusele = toupper(getchar());
        
        puts("");
        switch ( menusele )	{
            case '1' :
                insert();
                while(getchar()!='\n') continue;
                break;
            case '2' :
                deleteNode();
                while(getchar()!='\n') continue;
                break;
            case '3' :
                inorderShow( root );
                break;
            case '4' :
                puts("Bye Bye ^_^");
                exit(1);
            default :
                puts("Invalid choice !!");
        }
    } while ( 1 );
    printf("\n");
    return 0;
}

/*插入節點函數*/
void insert()
{
    newnode = newtbintree();
    printf("Enter a number to insert : ");
    scanf("%d", &newnode->number);
    if ( root->lchild == root ){
        insertLeft( root, newnode );
        printf("Node %d has been inserted!\n", newnode->number);
    }
    else{
        ptr = root->lchild;
        while ( ptr->number != newnode->number ){
            /*  如新節點小於目前節點且lbit為0 (lchild為引線)
             則插入目前節點左方, 否則ptr往左搜尋  */
            if ( newnode->number < ptr->number ){
                if ( ptr->lbit == 0 ){
                    insertLeft( ptr, newnode);
                    break;
                }
                else
                    ptr = ptr->lchild;
            }
            /*  如新節點大於目前節點且rbit為0 (rchild為引線)
             則插入目前節點右方, 否則ptr往右搜尋  */
            else if ( newnode->number > ptr->number){
                if ( ptr->rbit == 0 ){
                    insertRight( ptr , newnode);
                    break;
                }
                else
                    ptr = ptr->rchild;
            }
        }
        if ( ptr->number == newnode->number )
        {
            puts("Number existed ...!");
            return;
        }
        else
            printf("Node %d has been inserted!\n", newnode->number);
    }
}

/*刪除節點函數*/
void deleteNode()
{
    struct tbintree *ptrParent;
    struct tbintree *ptrPred, *ptrSucc;
    int num;
    
    /*引線二元樹從root->lchild開始放資料*/
    if ( root->lchild == root ){
        puts("No Data!");
        return;
    }
    printf("Enter a number u want to delete : ");
    scanf("%d", &num);
    ptrParent = root;
    ptr = root->lchild;
    while ( ptr->number != num ){   /*搜尋二元樹直到找到節點*/
        ptrParent = ptr;
        if ( num < ptr->number ){ /*如num值小於目前節點且lbit為1*/
            if ( ptr->lbit == 1 ) /*(lchild為正常指標)則往左搜尋*/
                ptr = ptr->lchild;
            else /*否則(lchild為引線)即找不到節點*/
                break;
        }
        else if ( num > ptr->number){
            if ( ptr->rbit == 1 )
                ptr = ptr->rchild;
            else
                break;
        }
    }
    if ( ptr->number != num ){
        printf("Not found number %d!\n", num);
        return;
    }
    printf("Deleting number %d... OK!\n", ptr->number);
    
    /* 刪除樹葉節點*/
    if ( ptr->lbit == 0 && ptr->rbit == 0 ){
        if ( ptrParent == root ){    /*刪除第一個節點*/
            ptrParent->lchild = root;
            ptrParent->lbit = 0;
        }  /*刪除左節點*/
        else  if ( ptr->number < ptrParent->number ){
            ptrParent->lchild = ptr->lchild;
            ptrParent->lbit  = 0;
        }
        else{                   /*刪除右節點*/
            ptrParent->rchild = ptr->rchild;
            ptrParent->rbit = 0;
        }
        free(ptr);
    }
    
    /* 刪除有兩分支度節點，表示左右各有節點 */
    else if ( ptr->lbit == 1 && ptr->rbit == 1 ){
        /*求ptr的前行者節點, 將右子樹插入前行者右方*/
        ptrPred = inpred ( ptr);
        ptrPred->rchild = ptr->rchild;
        ptrPred->rbit = ptr->rbit;
        ptrParent->rchild = ptr->lchild;
        free(ptr);
    }
    else   /*刪除一分支度節點*/{
        if ( ptrParent == root ){ /*刪除第一節點*/
            if ( ptr->lbit == 1 ){
                ptrPred = inpred(ptr);
                root->lchild = ptr->lchild;
                ptrPred->rchild = root;
            }
            else{
                ptrSucc = insucc(ptr);
                root->lchild = ptr->rchild;
                ptrSucc->lchild = root;
            }
        }
        else{
            /* 當刪除的節點在ptrParent的左邊時 */
            if ( ptr->number < ptrParent->number ){
                /* 當ptr節點只有右邊的節點時 */
                if (ptr->rbit == 1 && ptr->lbit == 0) {
                    ptr->rchild->lchild = ptr->lchild;
                    ptr->rchild->lbit = ptr->lbit;
                    ptrParent->lchild = ptr->rchild;
                    ptrParent->lbit = ptr->rbit;
                }
                /* 當ptr節點只有左邊的節點時 */
                else if (ptr->rbit == 0 && ptr->lbit == 1){
                    ptr->lchild->rchild = ptr->rchild;
                    ptr->lchild->rbit = ptr->rchild->rbit;
                    ptrParent->lchild = ptr->lchild;
                    ptrParent->lbit = ptr->lbit;
                }
            }
            /* 當刪除的節點在ptrParent的右邊時 */
            else{
                /* 當ptr節點只有左邊的節點時 */
                if (ptr->lbit == 1 && ptr->rbit == 0) {
                    ptrParent->rchild = ptr->lchild;
                    ptrParent->rbit = ptr->lbit;
                    ptr->lchild->rchild = ptr->rchild;
                    ptr->lchild->rbit = ptr->rbit;
                }
                /* 當ptr節點只有右邊的節點時 */
                else if (ptr->lbit == 0 && ptr->rbit == 1){
                    ptrParent->rchild = ptr->rchild;
                    ptrParent->rbit = ptr->rbit;
                    ptr->rchild->lchild = ptrParent;
                    ptr->rchild->lbit = ptr->lbit;
                }
            }
            free(ptr);
        }
    }
}

/* 加入節點於右方函數 */
/* 傳入參數: */
/* 1. nodeParent 為新節點之父節點 */
/* 2. node 為欲新增之節點 */
void insertRight( struct tbintree *nodeParent, struct tbintree *node)
{
    struct tbintree *w;
    
    node->rchild = nodeParent->rchild;
    node->rbit = nodeParent->rbit;
    node->lchild = nodeParent;
    node->lbit = 0;
    nodeParent->rchild = node;
    nodeParent->rbit = 1;
    if ( node->rbit == 1 ){   /*node底下還有tree*/
        w = insucc( node );
        w->lchild = node;
    }
}

/* 加入節點於左方函數 */
/* 傳入參數: */
/* 1. nodeParent 為新節點之父節點 */
/* 2. node 為欲新增之節點 */
void insertLeft( struct tbintree *nodeParent, struct tbintree *node)
{
    struct tbintree *w;
    
    node->lchild = nodeParent->lchild;
    node->lbit = nodeParent->lbit;
    node->rchild = nodeParent;
    node->rbit = 0;
    nodeParent->lchild = node;
    nodeParent->lbit = 1;
    if ( node->lbit == 1 ){    /*node 底下還有tree*/
        w = inpred( node );
        w->rchild = node;
    }
}

/* 中序追蹤顯示節點函數 */
void	inorderShow( struct tbintree *node)
{
    if ( node->lchild == root ){
        puts("No Data!");
        return;
    }
    puts("Inorder Displaying Thread Binary Search Tree");
    ptr = root;
    do{
        ptr = insucc( ptr );
        if ( ptr != root )
            printf("%-5d", ptr->number);
    } while ( ptr != root );
    puts("\n--------------------------------------------");
}

/* 追蹤後繼者函數 */
struct tbintree * insucc( struct tbintree *node )
{
    struct tbintree *succ;
    
    succ = node->rchild;
    if ( node->rbit == 1 )
        while ( succ->lbit == 1 )
            succ = succ->lchild;
    return succ;
}

/* 追蹤前行者函數 */
struct tbintree *inpred( struct tbintree *node )
{
    struct tbintree *pred;
    
    pred = node->lchild;
    if ( node->rbit == 1 )
        while ( pred->rbit == 1 )
            pred = pred->rchild;
    return pred;
}

/* 配置記憶體函數 */
struct tbintree *newtbintree()
{
    struct tbintree *temp;
    
    temp = (struct tbintree *)malloc(sizeof(struct tbintree));
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}