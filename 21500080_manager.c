#include "21500080_manager.h"

void listSnack(Snack *s[], int count){
    printf("\nNo Name   (g)  (won)  (per)  star\n");
    printf("==========================================\n");
    for(int i=0;i<count;i++){
        if(s[i]==NULL) continue;
        printf("%d",i+1);
        readSnack(*s[i]);
    }
    printf("\n");
}

int selectDataNo(Snack *s[], int count){
    int no;
    listSnack(s,count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
}
