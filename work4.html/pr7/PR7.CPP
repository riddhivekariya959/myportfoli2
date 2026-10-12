#include<stdio.h>
#include<conio.h>
int  add(int a, int b){
return a+b;
}

int sub(int a, int b){
return a-b;
}

int multi(int a, int b){
return a*b;
}

int div(int a, int b){
return a/b;
}



int mod(int a, int b){
return a%b;
}
void  main(){
 clrscr();
int choise,a,b;
do{
printf("\n press 1 for +");
printf("\n press 2 for -");
printf("\n press 3 for *");
printf("\n press 4 for /");
printf("\n press 5 for %%");
printf("\n press 0 for exit");

printf("\n enter your choise:");
scanf("%d",&choise);


switch(choise){
case 1: printf("enter the frist number :");
scanf("%d",&a);

printf("enter the second number :");
scanf("%d",&b);

printf("addition of %d and %d is %d",a,b,add(a,b));
break;

case 2:
printf("enter the frist number :");
scanf("%d",&a);

printf("enter the second number :");
scanf("%d",&b);


printf("subtraction of %d and %d is %d",a,b, sub(a,b));
break;

case 3: printf("enter the frist number :");
scanf("%d",&a);

printf("enter the second number :");
scanf("%d",&b);

printf(" multiplication of %d and %d is %d",a,b, multi( a, b));
break;

case 4:   printf("enter the frist number :");
scanf("%d",&a);

printf("enter the second number :");
scanf("%d",&b);


 case 5:if(b!=0){
printf("\n  of %d and %d is %d",a,b div(a,b)); }
else
printf("\n cannot divide by zero");
break;



case 6:  printf("enter the frist number :");
scanf("%d",&a);

printf("enter the second number :");
scanf("%d",&b);



 case 7:if(b!=0){
printf("\n modulus of %d and %d is %d",a,b mod(a,b));
else
printf("\n cannot divide by zero");
break;

case 0:
printf("exit");
break;

default:printf("invalid choise");
}


while(choise!=0);

getch();
}