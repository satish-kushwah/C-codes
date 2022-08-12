#include <stdio.h>

int main()
{
    int date,month,year,r,days,years,leap,normal_years,odd_days,century;
    
    printf("enter date in dd/mm/yyyy format to know day of week ");
    scanf("%d/%d/%d",&date,&month,&year);
    
    r=(year-1)%400;
    century=r/100;
    years=r-century*100;
    leap=years/4;
    normal_years=years-leap;
    odd_days=century*5+leap*2+normal_years;
    switch(month-1)
     {
         case 0:  days=0; break;
         case 1:  days=31; break;
         case 2:  days=31+28; break;
         case 3:  days=31+28+31;  break;
         case 4:  days=31+28+31+30; break;
         case 5:  days=31+28+31+30+31; break;
         case 6:  days=31+28+31+30+31+30; break;
         case 7:  days=31+28+31+30+31+30+31; break;
         case 8:  days=31+28+31+30+31+30+31+31; break;
         case 9:  days=31+28+31+30+31+30+31+31+30; break;
         case 10: days=31+28+31+30+31+30+31+31+30+31; break;
         case 11: days=31+28+31+30+31+30+31+31+30+31+30; break;
     }
     if((year%400==0||(year%4==0&&year%100!=0))&&month>2) days++;
     odd_days=odd_days+days+date;
     odd_days=odd_days%7;
     
     switch(odd_days)
      {
       case 0: printf("\nSunday"); break; 
       case 1: printf("\nMonday"); break; 
       case 2: printf("\nTuesday"); break; 
       case 3: printf("\nWednesday"); break; 
       case 4: printf("\nThursday"); break; 
       case 5: printf("\nFriday"); break; 
       case 6: printf("\nSaturday"); break; 
      }
    printf("\n");
    system("pause");
    return 0;
}
