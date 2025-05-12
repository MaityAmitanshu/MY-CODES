#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node *left ;
    struct node *right ;
};
struct node *creatnode(int data) ;
struct node *insertINtree(struct node *tree , int value) ;
void printTree(struct node *tree) ;
struct node *deleteTree(struct node *tree , int data) ;
struct node *successor(struct node *tree) ;


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

struct node *successor(struct node *tree) {
    tree = tree -> right ;
    while (tree != NULL && tree -> left != NULL)
    {
        tree = tree -> left ;
    }
    return tree ;
}
struct node *deleteTree(struct node *tree , int data) {
    if (tree == NULL)
    {
        return tree ;
    }
    else if( data < tree -> data)
    {
        tree -> left = deleteTree( tree -> left , data) ;
    }
    else if( data > tree -> data)
    {
        tree -> right = deleteTree( tree -> right , data) ;
    }
    else
    {
        if ( tree -> left == NULL)
        {
            struct node *tmp = tree -> right ;
            free(tree) ;
            return tmp ;
        }
        else if ( tree -> right == NULL)
        {
            struct node *tmp = tree -> left ;
            free(tree) ;
            return tmp ;
        }
        else
        {
            struct node *tmp = successor(tree) ;
            tree -> data = tmp -> data ;
            tree -> right = deleteTree(tree -> right , tmp -> data) ;

        }
    }
    return tree ;
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
    printf("\n") ;
    p = deleteTree(p,90) ;
    p = deleteTree(p,40) ;
    printTree(p) ;

    return 0;

}
