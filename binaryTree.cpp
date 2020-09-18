#include<bits/stdc++.h>

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

class Tree{
    private:
        int *tree;
        int capacity;
        int len;
        
    public:
        Tree(){
            len=0;
            capacity=10;
            tree=(int*)malloc(sizeof(int)*capacity);
        }
        void print()
        {
            for(int i=0;i<len;i++)
            {
                printf("%d ",tree[i]);
            }
        }
        void add(int value){
            if(len+1 == capacity)
            {
                capacity*=2;
                tree = (int*)realloc(tree,sizeof(int)*capacity);
            }
            tree[len]=value;
            if(len!=1)
            {
                int i=len;
                while(tree[i]<tree[(i+1)/2] && i>0)
                {
                    swap(tree[i],tree[(i+1)/2]);
                    i=(i+1)/2;
                }
            }
            len++;
            this->print();

        }
};

int main()
{
    int i=0,k;
    Tree a;
    std::cin >> i;

    while(i != -1)
    {
        a.add(i);
        std::cin >> i;
    }
}