#include <stdio.h>
#include <locale.h>


int getStickN(int playern, int stickcount) {
    int n ;
    
    while (1) {
        printf("Игрок N%d, введите число спичек, которое вы берете:>",playern) ;
        fflush(stdin) ;
        scanf("%d",&n) ;
        fflush(stdin) ;
        
        if (n>stickcount)
            printf("Нельзя взять больше, чем сейчас на столе!\n") ;
        else
            
        if ((n<1)||(n>10))
            printf("Нужно ввести от 1 до 10!\n") ;
        else
        return n ;
    }
}

void goGame() {
    int stickcount = 100 ;
    int playern = 1 ;
    while (stickcount>0) {
       printf("Òåêóùåå ÷èñëî ñïè÷åê: %d\n",stickcount) ;
       int n = getStickN(playern,stickcount);
       stickcount-=n ;
       if (playern==1) playern=2 ;
       else playern=1 ;
    }
