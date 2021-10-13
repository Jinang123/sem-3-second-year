#include <stdio.h>

int displayPrimeNumber (int x); //function prototype
int main ()
{
   int num1, num2, i, flag;

   printf("Enter two numbers: ");
   scanf("%d %d", &num1, &num2);

   printf("Prime numbers between %d and %d are:\n", num1, num2);
   // Displaying prime number between num1 and num2
   for (i = num1 + 1; i < num2; ++i)
   {
      flag = displayPrimeNumber(i);
      if (flag == 0) //if flag == 0, then display i
         printf("%d\t", i);
   }
   return 0;
}

int displayPrimeNumber(int x)
{
   int j, flag = 0;
   for (j = 2; j <= x/2; ++j)
   {
      if (x % j == 0)
      {
         flag = 1;
         break;
     }
   }
   return flag;
}
