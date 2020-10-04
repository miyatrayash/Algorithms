#include<stdio.h>


void swap(int arr[],int a,int b){

    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

    int arr[]={5,2,8,4,1,9,5,6,8,10,45,63};

void quick_sort(int arr[],int start,int end){

    int P = arr[start];
    int lowerbound = start;
    int upperbound = end;
    
    while(start < end){

        while(arr[start] <= P)
            start++;
        
        while (arr[end] > P)
            end--;

        if(start < end)
            swap(arr,start,end);
        else
            break;

    }

    if(lowerbound < upperbound)
    {
    swap(arr,lowerbound,end);
    quick_sort(arr,lowerbound,end-1);
    quick_sort(arr,end+1,upperbound);
    }

}


int main(){

    int arr[]={5,2,8,4,1,9,5,6,8,10,45,63,28};

    quick_sort(arr,0,13-1);

    for(int i=0;i<13;i++)
    {
        printf("%d ",arr[i]);
    }
}