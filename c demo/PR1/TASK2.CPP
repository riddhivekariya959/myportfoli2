#include<stdio.h>
#include<conio.h>

void main()

{
    clrscr();
    float basic_salary , hra, da ,ta,gross;
    printf("\n enter basic salary");
    scanf("%f",&basic_salary);

    hra= basic_salary* 10/100;
    da= basic_salary* 5/100;
    ta= basic_salary* 8/100;

    gross=basic_salary+ hra+da+ta;

    printf("\n basic_salary=%.2f",basic_salary);
    printf("\n hra=%.2f",hra);
    printf("\n da=%.2f",da);
    printf("\n ta=%.2f",ta);
    printf("\n gross=%.2f",gross);



    getch();



}