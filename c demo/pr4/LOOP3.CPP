#include<stdio.h>
#include<conio.h>
void main()
{
int r,c,s;
clrscr();

for(r=1 ; r<=5; r++){
for(s=5; s>r; s--){
     printf(" ");
}
 for(c=6-r; c<=5; c++){
 printf("%d",c);

 }
  printf("\n");
}




     getch();


}