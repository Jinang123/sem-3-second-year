#include<stdio.h>
#define SIZE 5

void accept(int arr[ ])
{
  int i;
  for(i=0;i<SIZE;i++)
  {
    printf("Enter element %d  ",i+1);
    scanf("%d",&arr[i]);

  }
}

void display(int arr[ ],int n)
{
  int i;
  printf("{");
  for(i=0;i<n;i++)
  {
    printf("%d",arr[i]);
  }
  printf("}");
}

int find_union(int array1[], int array2[], int union_array[])
{
    int i = 0, j = 0, k = 0;
    while ((i < SIZE) && (j < SIZE))
    {
        if (array1[i] < array2[j])
        {
            union_array[k] = array1[i];
            i++;
            k++;
        }
        else if (array1[i] > array2[j])
        {
            union_array[k] = array2[j];
            j++;
            k++;
        }
        else
        {
            union_array[k] = array1[i];
            i++;
            j++;
            k++;
        }
    }
    if (i == SIZE)
    {
        while (j < SIZE)
        {
            union_array[k] = array2[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i < SIZE)
        {
            union_array[k] = array1[i];
            i++;
            k++;
        }
    }
    return(k);
}

int find_intersection(int array1[], int array2[], int intersection_array[])
{
    int i = 0, j = 0, k = 0;
    while ((i < SIZE) && (j < SIZE))
    {
        if (array1[i] < array2[j])
        {
            i++;
        }
        else if (array1[i] > array2[j])
        {
            j++;
        }
        else
        {
            intersection_array[k] = array1[i];
            i++;
            j++;
            k++;
        }
    }
    return(k);
}

int find_difference(int array1[],int array2[],int difference_array[])

{
int i=0,j=0,k=0;
while(i<SIZE)
{
  j=0;
  while(j < SIZE)
  if(array1[i]==array2[j])
  {
    break;
  }
 j++;
}
if(j==SIZE)
{
difference_array[k]=array1[i];
k++;
}
i++;

return(k);
}
int find_symmetric_difference( int array1[ ], int array2[ ],int symmetric_difference_array[ ])
{
  int a[SIZE],b[SIZE],n1,n2,n,i;

  n1=find_difference(array1,array2,a);
  for(i=0;i<n1;i++)
  {
    printf("\n%d",a[i]);

  }
  n2=find_difference(array2,array1,b);
  n=find_union(a,b,symmetric_difference_array);
return n;
}

void main()
{
  int n,array1[SIZE],array2[SIZE],symmetric_difference_array[SIZE],union_array[SIZE*2],difference_array[SIZE*2],intersection_array[SIZE];

  printf("\nEnter the Element of First set:\n");
  accept(array1);
  display(array1,SIZE);
  printf("\n\nEnter elements of Second set:\n");
  accept(array2);
  display(array2,SIZE);

 n=find_union(array1,array2,union_array);
 printf("\n\nUnion :::::::");
 display(union_array,n);

 n=find_intersection(array1,array2,intersection_array);
 printf("\n\nIntersection  :::::::");
 display(intersection_array,n);

 n=find_difference(array1,array2,difference_array);
 printf("\n\nDifference :::");
 display(difference_array,n);

 n=find_symmetric_difference(array1,array2,symmetric_difference_array);
 printf("\n\nSymmetric Difference ::::");
}
