#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int no_of_nodes,weight,starting_node,i=0,j=0;
    scanf("%d",&no_of_nodes);
    int cost_matrix[no_of_nodes][no_of_nodes];
    for(i=0;i<no_of_nodes;i++)
    {
        for(j=0;j<no_of_nodes;j++)
        {
            scanf("%d",&weight);
            if(weight<0)
            {
                printf("Weight of the edge %d - %d can not be negative",i+1,j+1);
                exit (0);
            }
            if(i==j)
            {
                if(weight!=0)
                {
                    printf("Weight of the edge %d - %d must be 0",i+1,j+1);
                    exit(0);
                }
            }
             else
                {
                    cost_matrix[i][j]=weight;
                }
            if(i>j)
            {
                if(weight!=cost_matrix[j][i])
                {
                    printf("Weight of the edge %d - %d must be same as edge %d - %d",i+1,j+1,j+1,i+1);
                    exit(0);
                }
                else
                {
                    cost_matrix[i][j]=weight;
                }
            }
        }
    }
    scanf("%d",&starting_node);
    return 0;
}