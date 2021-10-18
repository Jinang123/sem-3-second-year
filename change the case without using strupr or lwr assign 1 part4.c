#include<stdio.h>
#include <string.h>


int main()
{
    char s[1000],*p;
    int i;

    printf("Enter  the string: ");
    scanf("%c",&s);
    p=s;

    i=0;
	while(*(p+i))
    {
        if(*(p+i)>=65 && *(p+i)<=90)
         *(p+i)+=32;
        else if(*(p+i)>=97 && *(p+i)<=122)
         *(p+i)-=32;

        i++;
 	}

    printf("string in changes case is as follows ='%s'\n",p);



}
