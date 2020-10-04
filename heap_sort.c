#include<stdio.h>
#include<stdlib.h>

int parent(int child)
{
    return (child-1)/2;
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int max(int a,int b)
{
    return (a >= b) ? a:b;
}


void insert(int arr[],int child)
{
    while(child > 0 && arr[parent(child)] < arr[child] )
    {
        swap(&arr[parent(child)],&arr[child]);
        child = parent(child);
    }
}

int child1(int p,int N)
{
    return (p*2 + 1 < N) ? p*2 + 1: -1;
}

int child2(int p, int N)
{
    return (p*2 +2 < N) ? p*2 + 2: -1;
}


void delete(int arr[], int N)
{
    int p = 0;
    if(N == 0)
        return;
    swap(&arr[p],&arr[N-1]);

    N--;

    while(p < N && arr[p] < max(arr[child1(p,N)],arr[child2(p,N)]))
    {
         
        if(arr[child1(p,N)] >= arr[child2(p,N)])
        {
            swap(&arr[p] , &arr[child1(p,N)]);
            p = child1(p,N);
        }
        else
        {
            swap(&arr[p] , &arr[child2(p,N)]);
            p = child2(p,N);
        }

    }

    printf("\n");
}

int main()
{
    int N;

    scanf("%d",&N);

    if(N < 1 || N > 10000)
    {
        printf("Size of array must be within [1,10000]");
        exit(0);
    }


    int arr[N];

    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);

        if(arr[i] < 1 || arr[i] > 1000000)
        {
            printf("Number must be within [1,1000000]");
            exit(0);
        }

        insert(arr,i);
    }
  
    int index = N;
    for(int i=N;i>0;i--)
    {
        delete(arr,i);
    }

    for(int i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }

}


