#include<stdio.h>
#include<stdlib.h>
unsigned long long int  step=0;
typedef struct NODE{
    int value;
    struct NODE *next;
}NODE;

typedef struct STACK
{
    NODE *TOPptr;
    int size;
}STACK;

void PUSH(STACK *s,int element)
{
    NODE * newnode = (NODE*)malloc(sizeof(NODE));
    newnode->next=NULL;
    newnode->value= element;
    s->size++;
    if(s->TOPptr == NULL)
    {
        s->TOPptr=newnode;
        return;
    }  

    newnode->next= (s->TOPptr);
    s->TOPptr=newnode;
}
int POP(STACK *s)
{
    NODE *temp = s->TOPptr;
    s->size--;
    if(s->size < 0)
    {
        printf("Stack Underflow");
        exit(0);
    }
    s->TOPptr=s->TOPptr->next;
    int value = temp->value;
    free(temp);
    temp = NULL;
    return value;
}
void display(STACK *s)
{
    NODE *temp = (s->TOPptr);
    int i=0;
    while(temp != NULL)
    {
        printf("%d ",temp->value);
        temp=temp->next;
        i++;
    }
}
void HANOI(int N,STACK *from,STACK *to,STACK *aux)
{
    if(N == 1)
    {
        int val = POP(from);
        PUSH(to,val);
        step++;
        return;
    }
    HANOI(N-1,from,aux,to);
    int val = POP(from);
    PUSH(to,val);
    step++;
    HANOI(N-1,aux,to,from);
}

int main()
{
    STACK A,B,C;
    A.TOPptr = NULL;
    A.size=0;
    B.TOPptr = NULL;
    B.size=0;
    C.TOPptr = NULL;
    C.size=0;

    int N;
    scanf("%d",&N);
    for(int i=N;i>0;i--)
    {
        PUSH(&A,i);
    }
    HANOI(N,&A,&C,&B);
    printf("%llu\n",step);
    display(&C);
}