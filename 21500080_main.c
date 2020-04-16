#include "21500080_manager.h"
#include <string.h>
#include <stdlib.h>

int selectMenu(){
    int menu;
    printf("\n*** 과자 관리 프로그램 ***\n");
    printf("1. 과자 조회\n");
    printf("2. 과자 추가\n");
    printf("3. 과자 수정\n");
    printf("4. 과자 삭제\n");
    printf("5. 파일 저장\n");
    printf("6. 과자 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int main(void){
    Snack *sp[100];
    int curcount=0;
    //새로 입력받는 정보 
    // Snack s;
    int count = 0, menu;
    
    //파일 불러오기
    count=loadData(sp);
    curcount=count;
    while (1){
        menu = selectMenu();
        fflush(stdin);

        if (menu == 0) break;
        if (menu == 1){
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            

	    if(count>0){ 
                listSnack(sp,curcount);
            }
            else printf("데이터가 없습니다.\n");
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            
        }
        else if (menu == 2){
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            
	    sp[curcount]=(Snack*)malloc(sizeof(Snack));
            count+=addSnack(sp[curcount++]);
            printf("==> 추가됨!\n");
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            
        }
        else if (menu == 3){
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            
            int no=selectDataNo(sp,curcount);

            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            int updateok;
            printf("정말로 수정하시겠습니까?(수정 : 1)");
            scanf("%d",&updateok);
            if(updateok==1){
                int flag=updateSnack(sp[no-1]);
                if(flag==1) printf("수정성공!\n");
            }
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            
        }
        else if (menu == 4){
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            
            int no=selectDataNo(sp,curcount);

            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 : 1)");

            scanf("%d",&deleteok);
            if(deleteok==1){
		if(sp[no-1]) free(sp[no-1]);
		sp[no-1]=NULL;
		count-=1;
      
                printf("==> 삭제됨\n");
            }
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            
        }
        else if (menu==5){
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            
            if(count==0) printf("데이터가 없습니다!\n");
            else saveData(sp,curcount);
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            
        }
        else if (menu==6){
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            
            search(sp, count);
#ifdef DEBUG
	printf("Debug : %s %s %s %d\n", __DATE__, __TIME__, __FILE__,__LINE__);
#endif            
        }
    }
    printf("종료됨!\n");
    return 0;
}
