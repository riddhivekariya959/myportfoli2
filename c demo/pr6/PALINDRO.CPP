#include<stdio.h>
#include<conio.h>
void main(){
clrscr();
int i, length=0, flag=1;
char  string[100];

printf("enter any string:");
scanf("%s",&string);

//length
for(i=0; string[i]!='\0'; i++){
length++;
}

// comper frist and last char

for(i=0; i<length/2; i++){
if(string[i]!=string[length-1-i]){
flag=0;
break;
}
}

if(flag==1)
printf("\n the given string is a palindrome");
else
printf("\n the given string is not a palindrome");

getch();
}