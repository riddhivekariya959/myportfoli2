#include<stdio.h>
#include<conio.h>
int check(int n)
{
if (n%3==0 && n%5==0)
return 1;
else
return 0;
}
void main(){
clrscr();
int num,result;
printf("enter any number");
scanf("%d",&num);
result=check(num);

if(result==1)
printf("the given number is divisible by both 3 & 5");

else
printf("the given number is not divisible by both 3&5");




getch();
}