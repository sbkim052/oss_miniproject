#include "21500080_product.h"
#include <string.h>
#include <stdlib.h>

int addSnack(Snack *s){
    printf("이름은? ");
    scanf("%s", s->name);
    fflush(stdin);
    printf("중량은(숫자)? ");
    scanf("%d",&s->gram);

    fflush(stdin);
    printf("가격은(숫자)? ");
    scanf("%d",&s->price);
    fflush(stdin);
    s->price_gram = s->price*10/s->gram;

    printf("별점수는(1~5)? ");
    scanf("%d",&s->star);
    fflush(stdin);
    return 1;
}

void readSnack(Snack s){
    if(s.price==-1) return;

    printf("  %s %4d %4d %4.0f  ",s.name,s.gram,s.price,s.price_gram);
    for (int i=0;i<s.star;i++){
        printf("*");
    }
    printf("\n");
}

int updateSnack(Snack *s){
    addSnack(s);
    return 1;
}

int deleteSnack(Snack *s){
    s->price=-1;

    return 1;
}

void saveData(Snack *s[], int count){
    FILE *fp;
    fp = fopen("snack.txt","wt");
    for(int i=0;i<count;i++){
        if(s[i]->price !=-1){

            fprintf(fp,"%s %d %d %f %d\n",s[i]->name, s[i]->gram, s[i]->price, s[i]->price_gram, s[i]->star);
        }
    }
    printf("저장됨");
}
int loadData(Snack* s[]){
    int count=0;
    FILE *fp;

    fp = fopen("snack.txt","r");
    if(fp==NULL){
        printf("=> 파일 없음\n");
        return 0;
    }
    
    for(;;count++){

        s[count] = (Snack*)malloc(sizeof(Snack));
        fscanf(fp,"%s %d %d %f %d\n", s[count]->name, &(s[count]->gram), &(s[count]->price), &(s[count]->price_gram), &(s[count]->star));
        printf("%d만큼 진행했습니다\n",count);
        if(feof(fp)) break;
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return count+1;
}

void search(Snack *s[], int count){
    int menu;
    printf("\n*** 검색 ***\n");
    printf("0. 취소\n");
    printf("1. 이름으로 검색\n");
    printf("2. 별점으로 검색\n");
    printf("3. 가격으로 검색\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    
    fflush(stdin);
    if(menu==1) search_Name(s, count);
    else if(menu==2) search_Star(s, count);
    else if(menu==3) search_Price(s, count);
    else  return;
}

void search_Name(Snack *s[], int count){
    int scount = 0;
    char search[20];

    printf("검색할 이름?");
    scanf("%s",search);

    printf("\nNo Name   (g)  (won)  (per)  star\n");
    printf("===============================\n");
    for(int i=0;i<count;i++){
        if(s[i]->price!=-1){
            if(strstr(s[i]->name, search)){
                printf("%2d", i+1);
                readSnack(*s[i]);
                scount++;
            }
        }
    }
    if(scount==0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void search_Star(Snack *s[], int count){
    int scount = 0;
    int star;

    printf("별점 입력(1 ~ 5)?");
    scanf("%d",&star);
    printf("%d 이상의 별점 검색...\n",star);
    
    printf("\nNo Name   (g)  (won)  (per)  star\n");
    printf("===============================\n");
    for(int i=0;i<count;i++){
        if(s[i]->price!=-1){
            if(s[i]->star>=star){
                printf("%2d", i+1);
                readSnack(*s[i]);
                scount++;
            }
        }
    }
    if(scount==0) printf("=> %d 이상의 별점으로 검색된 데이터 없음!", star);
    printf("\n");

}
void search_Price(Snack *s[], int count){
    int scount = 0;
    int price;

    printf("가격 범위?");
    scanf("%d",&price);
    printf("%d 이하의 가격 검색...\n",price);
    
    printf("\nNo Name   (g)  (won)  (per)  star\n");
    printf("===============================\n");
    for(int i=0;i<count;i++){
        if(s[i]->price!=-1){
            if(s[i]->price<=price){
                printf("%2d", i+1);
                readSnack(*s[i]);
                scount++;
            }
        }
    }
    if(scount==0) printf("=> %d 이하의 가격으로 검색된 데이터 없음!", price);
    printf("\n");
}


