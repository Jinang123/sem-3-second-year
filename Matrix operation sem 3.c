#include<stdio.h>
void accept(int m[10][10],int r,int c)
 {
   int i,j;
   printf("\nEnter the Elements\n");
    for(i=0;i<r;i++)
     {
     	  for(j=0;j<c;j++)
      	  {
      	   scanf("%d",&m[i][j]); 
      	  }
     }
 }
void display(int m[10][10],int r,int c)
{
 int i,j;
  for(i=0;i<r;i++)
   {
    for(j=0;j<c;j++)
     {
    	 printf("%d ",m[i][j]);
     }printf("\n");
   }
}
void add(int (*a)[10],int (*b)[10],int (*c)[10],int r1,int c1,int r2,int c2)
{
int i,j;
if (r1!=r2 || c1!=c2)
   printf("\nAddition Not Possible\n");
else 
	for(i=0;i<r1;i++)
	{ 
			for(j=0;j<c1;j++)
		{
		              *(*(c+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
			}
   	}
} 
void trans(int (*a)[10],int r,int c)
{
int i,j;
for(i=0;i<r;i++)
{
        for(j=0;j<c;j++)
         {
	           printf(" %d ",*(*(a+j)+i));
         }printf("\n");
} 
} 
int saddle(int m[10][10],int r,int c) 
{
  int i,j,rmax[10],cmin[10],max,min;
  for(i=0;i<r;i++)  
   {
     rmax[i]=m[i][0];
     for(j=1;j<c;j++)
      {
       if(rmax[i]<m[i][j])
       rmax[i]=m[i][j];
      }
   }
  for(i=0;i<r;i++)  
   {
     cmin[i]=m[0][i];
     for(j=1;j<c;j++)
      {
       if(cmin[i]>m[j][i])
       cmin[i]=m[j][i];
      }
   }
  min=rmax[0];
  for(i=1;i<r;i++)
   if(min>rmax[i])
	     min=rmax[i];
  max=cmin[0];
  for(i=1;i<c;i++)
   if(max<cmin[i])
	     max=cmin[i];
  if(max==min)
   	 printf("  Saddle Pt Exists i.e. %d\n",max);
  else
    printf("  Saddle Pt Does Not Exists\n");
} 
void multi(int a[10][10],int b[10][10],int c[10][10],int r1,int c1,int r2,int c2)
{
 int i,j,k;
 if(r2!=c1)
 	printf("\nMultiplication Not Possible\n");
	else
	{
for(i=0;i<r2;i++)
{
for(j=0;j<c1;j++)
{
c[i][j]=0;
for(k=0;k<r2;k++)
{
	c[i][j]+=a[i][k]*b[k][j];
}
}
}
}
}
 void main()
{ 
 int a[10][10],b[10][10],c[10][10],r1,c1,r2,c2,ch;
 do
 { 
		printf("1. Enter Matrix 2. Display Matrix 3. Addition 4. Transpose 5.Saddle Point 6. 				Multiplication 7.exit\n");
  printf("Enter Your Choice :\t");
  scanf("%d",&ch);
  switch(ch)
  {
        case 1:	printf("Enter the no of Rows & Columns of A:");
  		scanf("%d%d",&r1,&c1);
  		printf("Enter the no of Rows & Columns of B:");
  		scanf("%d%d",&r2,&c2);
  		printf("Enter element of Matrix A: ");
  		accept(a,r1,c1); 
  		printf("Enter element of For Matrix B: ");
  		accept(b,r2,c2);
              	break;
      case 2:	printf("Matrix A:\n");
  		display(a,r1,c1);
  		printf("Matrix B:\n");
  		display(b,r2,c2);
             		break;
              
      case 3:	printf("Addition: \n");
  		add(a,b,c,r1,c1,r2,c2);
  		display(c,r1,c1);
              	break;
      case 4:	printf("Transpose of A: \n");
  		trans(a,r1,c1);
  		printf("Transpose of B: \n");
  		trans(b,r2,c2);
              	break;
      case 5:         printf("Saddle pt of A:");
  		saddle(a,r1,c1);
  		printf("Saddle pt of B:");
  		saddle(b,r2,c2);
 	        	break;
      case 6: 	printf("Multiplication AxB :\n");
		multi(a,b,c,r1,c1,r2,c2);
 	     	display(c,r2,c1);
 		break;
 }
 }while(ch<77); 
 }
