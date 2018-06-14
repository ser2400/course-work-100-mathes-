#include <stdio.h>
#include <locale.h>

int getStickN(int playern, int stickcount) {
    int n ;
    while (1) {
        printf("\n\n\n\n		Èãðîê N%d, ââåäèòå ÷èñëî ñïè÷åê, êîòîðîå âû áåðåòå:>",playern) ;
        fflush(stdin) ;
        scanf("%d",&n) ;
        fflush(stdin) ;

        if (n>stickcount) printf("		Íåëüçÿ âçÿòü áîëüøå, ÷åì ñåé÷àñ íà ñòîëå!\n") ; else
        if ((n<1)||(n>10)) printf("		Íóæíî ââåñòè îò 1 äî 10!\n") ; else
        return n ;
    }
}

void goGame() {
    int stickcount = 100 ;
    int playern = 1 ;
    while (stickcount>0) {
       printf("\n\n\n\n								Òåêóùåå ÷èñëî ñïè÷åê: %d\n",stickcount) ;
       int n = getStickN(playern,stickcount);
       stickcount-=n ;
       if (playern==1) playern=2 ; else playern=1 ;
    }

    printf("\n						Âñå ñïè÷êè âçÿòû. Èãðîê N%d ïîáåäèë!\n",playern) ;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    
printf("Íà ïîëíûé ýêðàí(îáðàòíî) alt+enter") ;
printf("\n\n\n\n		Èãðà '100 ñïè÷åê'") ;
    while (1) {
        printf("\n\n		Ãëàâíîå ìåíþ\n") ;
        printf("		1 - ïðàâèëà\n		2 - èãðà\n		0 - âûõîä\n") ;
        int sel = 0 ;
        scanf("%d",&sel) ;
        if (sel==0) break ; 
        if (sel==1) {
            printf("	Ïðàâèëà èãðû: Íà ñòîëå 100 ñïè÷åê. Ïî î÷åðåäè èãðîêè áóäóò áðàòüñïè÷êè îò 1 äî 10. Ïðîèãðûâàåò òîò êòî âîçüì¸ò ïîñëåäíþþ ñïè÷êó.\n") ;
        }
        if (sel==2) goGame() ;
    }
    return 0 ;
}
