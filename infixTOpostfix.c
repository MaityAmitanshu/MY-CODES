#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 100

struct stack
{
    int top;
    char arr[size];
};

// defining the functions
bool isFull(struct stack *ptr);
bool isEmpty(struct stack *ptr);
// void printStack(struct stack *ptr);
void push(struct stack *ptr, char value);
char popvalue(struct stack *ptr);
struct stack *initializedata(struct stack *ptr);
int checkvalue(char ch);
int priorityCheck(char a, char ch);
int priorityGive(char a);

struct stack *initializedata(struct stack *ptr)
{
    ptr = (struct stack*)malloc(sizeof(struct stack)) ;
    ptr->top = -1;
    return ptr;
}

bool isFull(struct stack *ptr)
{

    return (ptr->top == size - 1);
}

bool isEmpty(struct stack *ptr)
{
    return (ptr->top == -1);
}

// void printStack(struct stack *ptr)
// {
//     if (isEmpty(ptr))
//     {
//         printf("sorry !! your stack is already empty \n");
//     }
//     else
//     {

//         for (int i = 0; i < size; i++)
//         {
//             printf("stack[%c] element is : %d \n", i, ptr->arr[i]);
//         }
//     }
// }

void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("sorry !! your stack is already full \n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char popvalue(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("sorry !! your stack is already empty \n");
        return '\0' ;
    }
    else
    {
        char temp = ptr->arr[ptr->top];
        ptr->top--;
        return temp;
    }
}

int checkvalue(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) ;
    
    
}

int priorityCheck(char a, char ch)
{
    if (a <= ch)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int priorityGive(char a)
{
    if (a == '+')
    {
        return 1;
    }
    else if (a == '-')
    {
        return 1;
    }
    else if (a == '*')
    {
        return 2;
    }
    else if (a == '/')
    {
        return 2;
    }
    else if(a == '^')
    {
        return 3;
    }
    else
    {
        return 0 ;
    }
}


int main()
{
    struct stack *list = NULL;
    list = initializedata(list);

    char *input;
    char *output;
    int n, i = 0, j = 0;
    printf("enter your infix length ");
    scanf("%d", &n);
    input = (char *)malloc((n + 1) * sizeof(char));
    output = (char *)malloc((n + 1) * sizeof(char));
    printf("enter your infix : ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (checkvalue(input[i]))
        {
            output[j] = input[i];
            j++;
        }
        else
        {
            if (isEmpty(list))
            {
                push(list , input[i]) ;
            }
            else
            {
                 while (priorityGive(list->arr[list->top]) >= priorityGive(input[i]))
                    {
                        output[j] = popvalue(list);
                        j++;
                    }
                 push(list , input[i]) ;
                
            }
        }
    }

    while(!isEmpty(list))
    {
        output[j] = popvalue(list) ;
        j ++ ;
    }

    printf("output is : %s \n",output) ;

    free(input) ;
    free(output) ;
    
    return 0 ;
}

 
