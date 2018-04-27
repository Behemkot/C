#include<stdio.h>

void read(int c[],int i)
{
    int j;
    for(j=0;j<i;j++)
        scanf("%d",&c[j]);
    fflush(stdin);
}

void display(int d[],int i)
{
    int j;
    for(j=0;j<i;j++)
        printf("%d ",d[j]);
    printf("\n");
}
   
  
int main()
{
    int a[5];
    printf("Wprowadź 5 elementów listy \n");
    read(a,5);
    printf("Elementami listy są : \n");
    display(a,5);
    return 0;
}
