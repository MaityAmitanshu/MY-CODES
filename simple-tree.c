#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node *left ;
    struct node *right ;
};

struct node *creatnode(int data) {
    struct node *p ;
    p = (struct node*)malloc(sizeof(struct node)) ;
    p -> data = data ;
    p -> left = NULL ;
    p -> right = NULL ;
    return p ;
}

struct node *insertINtree(struct node *tree , int value) {
    if ( tree == NULL)
    {
        return creatnode(value) ;
    }
    if ( tree -> data >= value )
    {
       tree -> left =  insertINtree(tree -> left , value) ;
    }
    else
    {
        tree -> right = insertINtree(tree -> right , value ) ;
    }

    return tree ;
}

void printTree(struct node *tree) {
    if ( tree != NULL )
    {
        printTree(tree -> left) ;
        printf("%d ||",tree -> data) ;
        printTree(tree -> right) ;

    }
}

int main ()
{
    struct node *p = NULL ;
    p = insertINtree(p,50) ;
    p = insertINtree(p,60) ;
    p = insertINtree(p,90) ;
    p = insertINtree(p,70) ;
    p = insertINtree(p,40) ;
    p = insertINtree(p,30) ;
    printTree(p) ;

    return 0;

}
