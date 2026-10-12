#include<stdio.h>
#include<conio.h>
void main()
{clrscr();
int a[3][3]={{2,7,1},{3,5,4},{8,9,6}};

int i,j;
int rowno,colno;
int rowsum=0, colsum=0;

printf("enter row no");
scanf("%d",&rowno);
printf("element of row %d:",rowno);
for(j=0; j<3; j++){
printf("%d",a[rowno][j]);
rowsum=rowsum+a[rowno][j];
}
printf("\n the sum of row %d: %d",rowno,rowsum);



printf("\n enter column no");
scanf("%d",&colno);
printf("element of col %d:",colno);
for(i=0; i<3; i++){
printf("%d",a[i][colno]);
colsum=colsum+a[i][colno];
}
printf("\n the sum of column %d: %d",colno,colsum);






   getch();



}