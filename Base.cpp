#include <stdio.h>
#include <locale.h>


int getStickN(int playern, int stickcount) {
    int n ;
 
    while (1) {
        printf("������� ����� ������, ������� �� ������:>",playern) ;
        
        fflush(stdin) ;
      
        scanf("%d",&n) ;
      
        fflush(stdin) ;

        return n ;
    }
}
