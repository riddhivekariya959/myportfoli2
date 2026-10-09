
#include<stdio.h>
#include<conio.h>
void main(){
clrscr();
int a[3][3]={{2,7,1},{3,4,5},{8,9,6}};
int largest=a[0][0];
for(int i=0; i<=2; i++){
    for(int j=0; j<=2; j++){
	if(a[i][j]>largest) {
	largest=a[i][j];
	}
    }
}

   printf("\n largest number is=%d",largest);


  getch();









}