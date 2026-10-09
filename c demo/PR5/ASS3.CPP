

#include<stdio.h>
#include<conio.h>
void main(){
clrscr();
int a[3][3]={{2,4,1},{3,5,4},{8,2,6}};
int i,j;
printf("\n trabnspase matrix of an array:\n");
for( i=0; i<=2; i++){
    for( j=0; j<=2; j++){
     printf("%d",a[j][i]);
    }
     printf("\n");
    }

  getch();
}