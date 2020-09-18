#include <iostream>
#include <cstring>

struct NODE
{
    long long int value;
    NODE *next;
};

void PUSH(NODE **Headptr, long long int element)
{
    NODE *newnode = new NODE, *temp = *Headptr;
    newnode->value = element;
    newnode->next = NULL;

    if (*Headptr == NULL || (*Headptr)->value >= newnode->value)
    {
        newnode->next = *Headptr;
        *Headptr = newnode;
        return;
    }
    while (temp->next != NULL && temp->next->value < element)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    return;
}
void print(NODE **Headptr)
{
    NODE *temp = *Headptr;
    while (temp != NULL)
    {
        std::cout << temp->value << ' ';
        temp = temp->next;
    }
}
int main()
{

    long long int N, result = 0, number;
    NODE *Headptr = NULL;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> number;
        PUSH(&Headptr, number);
    }

    print(&Headptr);
    return 0;
}