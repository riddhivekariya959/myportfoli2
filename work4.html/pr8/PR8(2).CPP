#include<stdio.h>
#include<conio.h>
void cube(int a[10][10],int r, int c){
int i,j;
printf("\n cube of all elements: \n");
for(i=0; i<r; i++){
for(j=0; j<c; j++){
printf("%d",(*(*(a+i)+j))* (*(*(a+i)+j))* (*(*(a+i)+j)) );
}
 printf("\n");
}
}


void main(){
clrscr();
int a[10][10],r,c,i,j;
printf("\n enter number of row:");
scanf("%d",&r);

printf("\n enter number of col:");
scanf("%d",&c);

printf("\n enter number of row&col:\n");
for(i=0; i<r; i++){
for(j=0; j<c; j++) {
scanf("\n %d",&a[i][j]);
}

}
 cube(a,r,c);
getch();
}