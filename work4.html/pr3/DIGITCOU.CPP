// digit counter
#include<stdio.h>
#include<conio.h>
void main()
{
  clrscr();
  int no,counter=0;
  printf("\n enter any no");
  scanf("%d",&no);

  do{

    no=no/10;
    counter++;
    }while(no!=0);

    printf("\n total no of digits: %d",counter);
     getch();


}