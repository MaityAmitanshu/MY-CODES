#include<stdio.h>
#include<stdlib.h>
# define max 5
struct queue {
    int top ;
    int rear ;
    int arr[max] ;
} ;

int isFull(struct queue *ptr) ;
int isEmpty(struct queue *ptr) ;
void enqueue(struct queue *ptr , int value) ;
void dequeue(struct queue *ptr) ;
void printQueue (struct queue *ptr) ;
struct queue *initialize(struct queue *ptr) ;

int isFull(struct queue *ptr) {
    if (ptr->rear == max - 1 ) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *ptr) {
    if (ptr->top == -1 || ptr->top > ptr->rear)
    {
        return 1 ;
    }
    else
    {
        return 0;
    }
}

struct queue *initialize(struct queue *ptr) {
    ptr = (struct queue*)malloc(sizeof(struct queue)) ;
    ptr -> top = -1 ;
    ptr -> rear = -1 ;
    return ptr ;
}


void enqueue(struct queue *ptr , int value) {
    if(isFull(ptr))
    {
        printf(" your queue is already full") ;
    }
    else
    {
        if (ptr->top == -1)
        {
            ptr -> top ++ ;
            ptr -> rear ++ ;
            ptr -> arr[ptr->rear] = value ;
        }
        else
        {
            ptr -> rear ++ ;
            ptr -> arr[ptr->rear] = value ;
        }
    }
}

void dequeue(struct queue *ptr) {
    if (isEmpty(ptr))
    {
        printf("your queue is empty !!") ;
    }
    else 
    {
        ptr -> top ++ ;
    }
}

void printQueue (struct queue *ptr) {
    printf("---------------------------- \n") ;
    if (isEmpty(ptr))
    {
        printf("empty queue") ;
    }
    else
    {
    for ( int i = ptr -> top ; i<= ptr -> rear ; i++)
    {
        printf("%d--->",ptr->arr[i]) ;
    }
    }

    printf(" \n ---------------------------- \n") ;

}

int main() {
    struct queue *q = NULL ;
    q = initialize(q) ;
    printQueue(q) ;
    enqueue(q,10) ;
    enqueue(q,20) ;
    enqueue(q,30) ;
    enqueue(q,40) ;
    enqueue(q,50) ;
    enqueue(q,60) ;
    printQueue(q) ;
    dequeue(q) ;
    dequeue(q) ;
    printQueue(q) ;

    return 0;

}
