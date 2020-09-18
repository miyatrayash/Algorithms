#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct NODE
{
    char symbol;
    int precedence, Rank;
    struct NODE *next;
} NODE;

NODE Operators[] = {{'+', 1, -1}, {'-', 1, -1}, {'*', 2, -1}, {'/', 2, -1}};

int ishigherprec(char a, char b)
{
    int aprec, bprac;
    for (int i = 0; i < 4; i++)
    {
        if (a == Operators[i].symbol)
            aprec = Operators[i].precedence;
        if (b == Operators[i].symbol)
            bprac = Operators[i].precedence;
    }

    if (aprec >= bprac)
    {
        return 1;
    }
    else
        return 0;
}
typedef struct STACK
{
    char *data;
    int top;
} STACK;

void PUSH(STACK *s, char symbol)
{

    s->data = (char *)realloc(s->data, sizeof(char) * (s->top + 1));
    s->data[s->top] = symbol;
    s->top++;
}
char POP(STACK *s)
{
    char temp = s->data[s->top - 1];
    s->data[s->top - 1] = '\0';
    s->top--;

    return temp;
}

void display(STACK *s)
{
    for (int i = 0; i < s->top; i++)
    {
        printf("%c", s->data[i]);
    }
    printf("\n");
}

int main()
{
    STACK S;
    int RANK = 0, len = 0, Plen = 0;
    char i, *infix, *postfix;
    NODE *next;
    S.data = NULL;
    S.top = 0;
    infix = (char *)malloc(sizeof(char) * 100);
    postfix = (char *)malloc(sizeof(char) * 100);

    scanf("%c", &i);
    while (i != '\n')
    {
        infix[len] = i;
        len++;

        scanf("%c", &i);
    }

    infix[len] = '\0';
    puts(infix);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(infix[i]))
        {
            postfix[Plen] = infix[i];
            Plen++;
            postfix[Plen] = '\0';
        }
        else
        {
            if (infix[i] == '(')
                PUSH(&S, infix[i]);
            else
            {
                if (infix[i] == ')')
                {
                    while (S.data[S.top - 1] != '(')
                    {
                        postfix[Plen++] = POP(&S);
                    }
                    POP(&S);
                }
                else
                {
                    while (S.top != 0 && ishigherprec(S.data[S.top - 1], infix[i]))
                    {
                        postfix[Plen] = S.data[S.top - 1];
                        Plen++;
                        postfix[Plen] = '\0';
                        //puts(postfix);
                        POP(&S);
                    }
                    PUSH(&S, infix[i]);
                }
            }
        }
    }
    for (int i = S.top - 1; i >= 0; i--)
    {
        postfix[Plen] = S.data[i];
        Plen++;
        POP(&S);
    }
    postfix[Plen] = '\0';

    puts(postfix);
}