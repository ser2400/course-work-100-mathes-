#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>


int isInt(char * buf) {
    int i ;
    for (i=0; i<strlen(buf); i++)
        if ((buf[i]<'0')||(buf[i]>'9')) 
		return 0 ;
    	return 1 ;
}


int getStickN(int playern, int stickcount) {
    int n ;
    while (1) {
        printf("\n\n\n\n		Player N%d, enter the number of matches you take:>",playern) ;
       
        fflush(stdin) ;
        
        char buf[32] ;
        scanf("%s",buf) ;
        
        fflush(stdin) ;

        if (isInt(buf)==0)
            printf("\n		Incorrect input!\n") ;
        else {
        n = atoi(buf) ;
        if (n>stickcount) printf("\n		You can't have more than that on the table!\n") ;
		else
        if ((n<1)||(n>10)) printf("\n		You need to enter from 1 to 10!\n") ;
		else
        return n ;
        }
    }
}

void goGame() {
    int stickcount = 100 ;
    int playern = 1 ;

    while (stickcount>0) {
       printf("\n\n\n\n								Current number of matches: %d\n",stickcount) ;
       int n = getStickN(playern,stickcount);
       stickcount-=n ;
       if (playern==1) playern=2 ;
	   else playern=1 ;
    }

    printf("\n						All the matches are taken. Player N%d won!\n",playern) ;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    
printf("Full screen (back) alt+enter") ;
printf("\n\n\n\n		Game '100 matches'") ;

    while (1) {
        printf("\n\n		Main menu\n") ;
        printf("		1 - Regulation\n		2 - Play\n		0 - exit\n") ;
        int sel = 0 ;
        char buf[32] ;
        scanf("%s",buf) ;
        if (isInt(buf)==0) {
            printf("\n		Incorrect input!\n") ;
        }
        else {
        sel = atoi(buf) ;
        if (sel==0) 
			break ; 
		else 
        if (sel==1) {
            printf("	Rules of the game: 100 matches on the table. In turn, players will take from 1 to 10 matches. The one who takes the last match loses.\n") ;
        }
		else
        if (sel==2) goGame() ;
        else
          printf("\n		Incorrect input!\n") ;
        }
    }
    return 0 ;
}


