#include<stdio.h>
#define SIZE 5

void accept(int *p);
void display(int *p,int n);
int union_fun(int array1[ ],int array2[ ],int union_array[ ]);


int main()
{
    int n,array1[SIZE],array2[SIZE],union_array[SIZE*2];
    printf("Enter first set : ");
    accept(array1);
    display(array1,SIZE);

     accept(array2);
    display(array2,SIZE);

   n=union_fun(array1,array2,union_array);
   display(union_array,n);


}
void accept(int*p)
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&p[i]);
    }
}

void display(int *p,int n)
{
    int i;
    printf("\n{");
    for(i=0;i<n;i++)
    {
        printf("%d",p[i]);
    }
    printf("}");
}

int union_fun(int array1[ ],int array2[ ],int union_array[ ])
{
    int i,j,k=0;
    for(i=0;i<SIZE;i++)
    {
        union_array[k]=array1[i];
        k++;

    }
    for(i=0;i<SIZE;i++)
    {
         for(j=0;j<SIZE;j++)
         {
             if(array1[j]==array2[i])
             {
                 break;
             }
         }
         if(j==SIZE)
         {
             union_array[k]=array2[i];
             k++;
         }
    }
    return k;
}
