#include<stdio.h>
#include<stdlib.h>

struct node {
    int data ;
    struct node *link ;
} ;

struct node *front = NULL ;
struct node *rear = NULL ;

void enqueue(int data) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node)) ;
    if ( ptr == NULL)
    {
        printf("your device is out of storage !! \n") ;
    }
    else
    {
        ptr -> data = data ;
        ptr -> link = NULL ;

        if ( front == NULL)
        {
            front = rear = ptr ;
            ptr -> link = NULL ;
        }
        else
        {
            rear -> link = ptr ;
            rear = ptr ;
        }
    }
}

void dequeue() {
    struct node *ptr = front ;
    if (front == NULL)
    {
        printf("queue is empty") ;
    }
    else
    {
        front = front -> link ;
        free(ptr) ;
    }
}

void traverse() {
    struct node *ptr = front ;
    while ( ptr != NULL)
    {
        printf("%d-->",ptr->data) ;
        ptr = ptr -> link ;
    }
    printf("\n") ;
}

int main () {
    enqueue(5) ;
    enqueue(10) ;
    enqueue(20) ;
    enqueue(30) ;
    enqueue(40) ;
    traverse() ;
    dequeue() ;
    dequeue() ;
    traverse() ;

    return 0 ;
}
