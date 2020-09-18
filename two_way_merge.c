#include<stdio.h>
#include<stdlib.h>


void merge(int a[],int lb,int mid,int ub){
    int i=lb,j=mid+1,k=lb;
    int *b=malloc(sizeof(int)*(100));

    while(i<=mid && j <=ub)
    {
        if(a[i] <= a[j])
        {
            b[k]=a[i++];
        }
        else
            b[k]=a[j++];

        k++;
    }

    while(i<=mid)
    {
        b[k] = a[i];
        k++;i++;
    }

    while (j<=ub)
    {
        b[k] = a[j];
        k++;j++;
    }

    for(int i=lb;i<=ub;i++){
        a[i]=b[i];
    }
    
}



void merge_sort(int a[],int lb,int ub){
    if(lb < ub)
    {
        int mid = (ub+lb)/2;

        merge_sort(a,lb,mid);
        merge_sort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}


int main(){

    int a[] = {7,3,8,12,54,23,76,45};

    merge_sort(a,0,7);

    for(int i=0;i<8;i++)
    {   
        printf("%d ",a[i]);
    }
}