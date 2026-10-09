#include<stdio.h>
#include<conio.h>
void main()
{ clrscr();
 int  i,j,s;
 for(i=1; i<=5; i++)
 {
	  for(s=1; s<=5-i;s++) {
		printf(" ");
	  }

	  for(j=6-i; j<=5; j++) {
		  printf("%d",j);
	  }

	 for(j=4; j>5-i;j--) {
		  printf("%d",j);
	 }

	printf("\n");

 }


  getch();



}