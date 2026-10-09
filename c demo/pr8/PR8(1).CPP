#include<stdio.h>
#include<conio.h>
void main(){
clrscr();
char str[100];
char *p;
int length=0;
printf("\n enter a string:");
gets(str);
p=str;
while(*p!='\0'){
length++;
p++;
}
printf("length of string = %d",length);


getch();
}