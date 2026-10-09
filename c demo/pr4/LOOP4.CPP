#include<stdio.h>
#include<conio.h>

void main(){

clrscr();

for( int r=5; r>=1; r--){
	for(int s=5 ;s>r;s--) {
	printf(" "); }

	for(int c=1; c<=r;c++){
	    if (c%2==1){
	       printf("1");
	    }
	    else{
	      printf("0");
	    }

	}
	  printf("\n");
}
       getch();
       }