#include<stdio.h>
#include<conio.h>
   #include<stdio.h>
   void main()
   {
     int i,j,a,n,number[30];
     clrscr();
     printf("Enter the values of M \n");
     scanf("%d",&n);

     printf("Enter the numbers \n");
     for(i=0;i<n;++i)
	scanf("%d",&number[i]);

     for(i=0;i<n;++i)
     {
       for(j=i+1;j<n;++j)
       {
	 if(number[i]>number[j])
	 {
	   a=number[i];
	   number[i]=number[j];
	   number[j]=a;
	 }
       }
   }
   printf("The numbers arranged in assending order \n");
   for(i=0;i<n;++i)
     printf("%d\n",number[i]);
   getch();
   }

