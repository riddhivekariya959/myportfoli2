// digit addition
#include<stdio.h>
#include<conio.h>
void main(){
clrscr();
   int no,f,l,sum;
   printf("\n enter any no");
   scanf("%d",&no);
   l=no%10;
   f=no;

   while(f>=10)
      {
       f=f/10;
      }
      sum=f+l;
      printf("first and last digit;%d",sum);


       getch();

}