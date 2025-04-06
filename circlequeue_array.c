#include <stdio.h>
#include <stdlib.h>
#define max 5

struct node
{
    int front;
    int rear;
    int arr[max];
};

struct node *initialize(struct node *queue);
int isFULL(struct node *queue);
int isEMpty(struct node *queue);
struct node *enqueue(struct node *queue, int data);
struct node *dequeue(struct node *queue);
void printQueue(struct node *queue);

struct node *initialize(struct node *queue)
{
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFULL(struct node *queue)
{
    return (queue->front != -1 && (queue->rear + 1) % max == queue->front);
}

int isEMpty(struct node *queue)
{
    return (queue->front == -1);
}

struct node *enqueue(struct node *queue, int data)
{
    if (isFULL(queue))
    {
        printf(" queue already full !!! \n");
    }
    else
    {
        if (queue->front == -1)
        {
            queue->rear = (queue->rear + 1) % max;
            queue->front = (queue->front + 1) % max;
            queue->arr[queue->rear] = data;
        }
        else
        {
            queue->rear = (queue->rear + 1) % max;
            queue->arr[queue->rear] = data;
        }
    }

    return queue;
}

struct node *dequeue(struct node *queue)
{
    if (isEMpty(queue))
    {
        printf("there is nothing to delete !! \n");
    }
    else
    {
        if (queue->front == queue->rear)
        {
            queue->front = queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1) % max;
        }
    }

    return queue;
}

void printQueue(struct node *queue) {
    int i;
    // printf("---------------------------\n");
    if (isEMpty(queue)) {
        printf("EMPTY QUEUE !!\n");
    } else {
        i = queue->front;
        while (1) {
            printf("%d ---> ", queue->arr[i]);
            if (i == queue->rear)
                break;
            i = (i + 1) % max;
        }
        printf("\n");
    }
    // printf(" \n ---------------------------\n");
}

int main()
{
    struct node *queue = (struct node *)malloc(sizeof(struct node));
    queue = initialize(queue);
    queue = enqueue(queue, 10);
    queue = enqueue(queue, 20);
    queue = enqueue(queue, 30);
    queue = enqueue(queue, 40);
    queue = enqueue(queue, 50);
    queue = enqueue(queue, 60);
    printQueue(queue);

    queue = dequeue(queue);
    queue = dequeue(queue);
    printQueue(queue);
  

    queue = dequeue(queue);
    queue = dequeue(queue);
    queue = dequeue(queue);
    queue = dequeue(queue);
    printQueue(queue);
   

    queue = enqueue(queue, 60);
    printQueue(queue);
    


    free(queue) ;

    return 0;
}
