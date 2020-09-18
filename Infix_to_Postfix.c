#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct NODE
{
    char operator;
    struct NODE *next;
} NODE;

typedef struct STACK
{
    int size;
    NODE *TOP;
} STACK;

typedef struct precedence{
    int value;
    char operator;
} precedence;

void PUSH(STACK *s, char element)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->operator= element;
    newnode->next = NULL;

    s->size++;
    if (s->TOP == NULL)
    {
        s->TOP = newnode;
        return;
    }

    newnode->next = s->TOP;
    s->TOP = newnode;
}

char POP(STACK *s)
{
    s->size--;
    if (s->size < 0)
    {
        printf("STACK UnderFlow");
        exit(0);
    }

    NODE *temp = s->TOP;
    char value = temp->operator;
    s->TOP = s->TOP->next;
    free(temp);
    temp = NULL;

    return value;
}

short int is_higher(char a, char b)
{
}

int main()
{
    STACK *StackOfOperators;
    StackOfOperators->TOP = NULL;
    StackOfOperators->size = 0;

    int N;
    char c;
    scanf("%d", &N);
    char postF[N + 1];

    for (int i = 0, b = 0; i < N; i++)
    {
        c = getchar();

        if (isalnum(c))
        {
            postF[b] = c;
            b++;
        }
        else
        {
            if (StackOfOperators->TOP->operator== ')')
                POP(&StackOfOperators);

            while (StackOfOperators->TOP != NULL || StackOfOperators->TOP->operator!= '(' || !is_higher(c, StackOfOperators->TOP->operator))
            {
                postF[b] = POP(&StackOfOperators);
                b++;
            }
            if (StackOfOperators->TOP->operator== '(')
                POP(&StackOfOperators);
            if (StackOfOperators->TOP->operator!= ')')
                PUSH(&StackOfOperators, c);
        }
    }
}
