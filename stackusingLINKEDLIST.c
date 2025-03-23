#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node *link ;
};

int isEmpty(struct node *ptr) ;
// int isFUILL(struct node *ptr) ;
struct node *push(struct node *ptr , int value) ;
struct node *initialize( int value) ;
struct node *pop(struct node *ptr) ;
void display(struct node *ptr) ;

int isEmpty(struct node *ptr) {
    if ( ptr == NULL)
    {
        return 1 ;
    }
    else{
        return 0 ;
    }
}

struct node *initialize( int value) {
    struct node *t = (struct node*)malloc(sizeof(struct node)) ;
    t -> data = value ;
    t -> link = NULL ;
    return t ;
}


struct node *push(struct node *ptr , int value) {
    if (isEmpty(ptr))
    {
        initialize(value) ;
    }
    else 
    {
        struct node *tmp = (struct node*)malloc(sizeof(struct node)) ;
        tmp -> data = value ;
        tmp -> link = ptr ;
        ptr = tmp ;
        return ptr ;
    }

}

void display(struct node *ptr) {
    struct node *m = ptr;
    printf("-------------elements---------------- \n");
    while (m != NULL) {  
        printf("%d--->", m->data);
        m = m->link;
    }
    printf("NULL\n");  
    printf("------------------------------------- \n");
}

struct node *pop(struct node *ptr) {
    if (isEmpty(ptr))
    {
        printf("empty stack !! \n") ;
        return ptr ;
    }
    else 
    {
        struct node *p = ptr ;
        ptr = ptr -> link ;
        free(p) ;
        return ptr ;
    }
}

int main () {
    struct node *top = NULL ;
    top = pop (top) ;
    top = push(top,10) ;
    top =push(top,20) ;
    top =push(top,30) ;
    top =push(top,40) ;
    display(top) ;
    top = pop (top) ;
    top = pop (top) ;
    display(top) ;

    return 0;

}

