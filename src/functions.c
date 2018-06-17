#include "functions.h"
#include <stdio.h>

int getStickN(int playern, int stickcount) {
    int n ;
    while (1) {
        printf("\n\n\n\n\t\tPlayer N%d, enter the number of matches you take:>",playern) ;
        fflush(stdin) ;
        
        scanf("%d",&n) ;
        fflush(stdin) ;

	        if (n>stickcount) {
				printf("\tYou can't have more than that on the table.!\n") ;
			}
	        else
		        if ((n<1)||(n>10)) {
		            printf("\t\tYou need to enter from 1 to 10!\n") ;
		        }
		        else
		        return n ;
    }
}

void goGame() {
    int stickcount = 100 ;
    int playern = 1 ;
    
    while (stickcount>0) {
       printf("\n\n\n\n\t\t\t\t\t\t\tCurrent number of matches: %d\n",stickcount) ;
       
       int n = getStickN(playern,stickcount);{
       stickcount-=n ;
		}
		
       if (playern==1) playern=2 ;
       else playern=1 ;
    }

    printf("\n\t\t\t\t\tAll the matches are taken. Player N%d won!\n",playern) ;
}
