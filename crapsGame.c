#include <stdio.h>
#include <stdlib.h>
#include<time.h> 

int main() {
    int count=0, dice1, dice2, sum;
	srand(time(0)); 
    while(1){
    	dice1=rand()%6+1; //random number between 1 and 6 for dice1
    	dice2=rand()%6+1; //random number between 1 and 6 for dice2
    	sum=dice1+dice2;

    	count++; //counting number of rolls
    	if(count==7){ //player loses if rolls 7th time
    		printf("Game finished, player LOSES\n");
    		break;
    	}

    	if(sum==7 || sum==11){
    		printf("Roll# %d, SUM = %d, Game finished, player WINS\n",count,sum);
    		break;
    	}
    	else if(sum==2 || sum==3 || sum==12){
    		printf("Roll# %d, SUM = %d, Game finished, player LOSES\n",count,sum);
    		break;
    	}
    	else{
    		printf("Roll# %d, SUM = %d, Game continues\n",count,sum);
    	}

    }
    printf("\n");
    system("pause");
    return 0;
}