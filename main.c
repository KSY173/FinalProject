//
//  main.c
//  infestPath
//
//  Created by Juyeop Kim on 2022/10/20.
//

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"

#define MENU_PATIENT        1
#define MENU_PLACE          2
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0

#define TIME_HIDE           2


int trackInfester(int patient_no, int *detected_time, int *place);
int main(int argc, const char * argv[]) {
    
    int menu_selection;
    void *ifct_element;
    FILE* fp;
    int pIndex, age, time;
    int placeHist[N_HISTORY];
    
    //------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    if (argc != 2)
    {
        printf("[ERROR] syntax : infestPath (file path).");
        return -1;
    }
    
    fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);
        return -1;
    }
    
    //1-2. loading each patient informations
    
	while(fscanf(fp, "%d &d &d", &pIndex, &age, &time)==3)
    {
    
    	int i;
    	
		for(i=0; i<5; i++)
    		fscanf(fp, "%d", &placeHist[i]);
    	
		//ifct_element = ifctele_genElement(pIndex, age, time, placeHist[N_HISTORY]);
		
		ifctdb_addTail(ifct_element);
		
		//ifctele_printElement(ifct_element);
		//age = ifctele_getage
	}
	
    //1-3. FILE pointer close
    
   fclose(fp);
    do {
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n"); //환자 번호 나이 감염 확인 일자 최근 5개 이동 장소                      //MENU_PATIENT
        printf("2. Print list of patients infected at a place.\n");        //MENU_PLACE 장소에서 발병 확인이 된 환자 모두의 정보 출력 
        printf("3. Print list of patients in a range of age.\n");          //MENU_AGE 최소 최대값 입력 받고 그 나이 환자 모두의 정보 출력 
        printf("4. Track the root of the infection\n");                     //MENU_TRACK 지정된 환자를 시작으로 전차자와 감염당한 시점 및 장소를 순차적 출력, 최초 전파자 최종 출력 
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("=============== ------------------------------------------------------- =============\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
        int Maxage, minage;
        
        switch(menu_selection)
        {
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                break;
                
            case MENU_PATIENT:
            	printf("patient number :");
            	scanf("%d\n", &pIndex);
            	
            	printf("patient number : %d\n", pIndex);
                printf("age : %i\n", ifctele_getAge(ifct_element)); 
                //printf("infected time : %d\n", ifctele_getinfestedTime(ifct_element));
                //printf("place history: %d -> %d -> %d -> %d -> %d", ifctele_getHistPlaceIndex(ifct_element, pIndex));
                
                break;
                
            case MENU_PLACE:
                
                break;
                
            case MENU_AGE:
            	
                printf("Max age: ");
                scanf("%d", &Maxage);
                printf("Min age: ");
                scanf("%d", &minage);
                
                break;
                
            case MENU_TRACK:
                    
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
        }
    
    } while(menu_selection != 0);
    
    
    return 0;
}
