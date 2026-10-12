#include<stdio.h>
#include<conio.h>

void main()

{
    clrscr();
   int mark;
   char grade,a ,b ,c,d,f;



   printf("\n enter your marks");
   scanf("%d",&mark);

   if(mark>=90)
   grade='a';

   else if(mark>=80)
   grade='b';

   else if(mark>=70)
   grade='c';

   else if(mark>=60)
   grade='d';

   else
   grade='f';

   printf("\n your grade is= %c",grade);


   switch(grade){

	 case 'a':
	 printf("\n excellent work");
	 break;

	 case 'b':
	 printf("\n well done");
	 break;

	 case 'c':
	 printf("\n good job");
	 break;

	 case 'd':
	 printf("\n you passed but you could do better");
	 break;

	 case 'f':
	 printf("\n sorry, you faild");
	 break;
	}

	if(grade=='a' || grade=='b' || grade=='c' || grade=='d')
	{
	  printf("\n you are elligible for next level");

	}
	else
	{
	     printf("\n try next time");

	}


   getch();



}