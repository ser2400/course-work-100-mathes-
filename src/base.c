#include <stdio.h>
#include "functions.h"

int main()
{
	printf("Full screen (back) alt+enter\n\n\n\n\t\tGame '100 matches'") ;
    while (1) {
        printf("\n\n\t\tMain menu\n") ;
        printf("\t\t1 - Regulation\n\t\t2 - Play\n\t\t0 - exit\n") ;
        
        int sel = 0 ;{
        scanf("%d",&sel) ;
        }
        
        if (sel==0) {
            break ; 
        }
            
        if (sel==1) {
            printf("\tRules of the game: 100 matches on the table.\n") ;
			printf("\tIn turn, players will take from 1 to 10 matches.\n") ;
			printf("\tThe one who takes the last match loses.\n") ;
        }
        
        if (sel==2) {
			goGame() ;
		}
    }
    return 0 ;
}

