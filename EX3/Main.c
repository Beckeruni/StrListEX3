#include <stdlib.h>
#include <stdio.h>
#include "StrList.h"
#include "StrList.c"
#include <string.h>
#include <sys/cdefs.h>

void main(){
    StrList* list = StrList_alloc();
    int fromUser;
    scanf("%d", &fromUser);
    if(fromUser == 1){    
        int numOfStrings;
        scanf("%d", &numOfStrings);
        int i;
        char* stringToAdd;
        for(i=0; i<numOfStrings; i++){
            scanf("%s ", stringToAdd);
            StrList_insertLast(list, stringToAdd);
        }
    }


    if(fromUser == 2){
        int index;
        char* stringToAdd;
        scanf("%d", &index);
        scanf("%s", &stringToAdd);
        StrList_insertAt(list, stringToAdd, index);
    }

    if(fromUser == 3){
        StrList_print(list);
    }

    if(fromUser == 4){
        printf("%d", list->_size);
    }

    if(fromUser == 5){
        int index;
        scanf("%d", &index);
        StrList_printAt(list, index);
    }


    if(fromUser == 6){
        StrList_printLen(list);
    }


    if(fromUser == 7){
        int ans;
        char* stringToCheck;
        scanf("%s", &stringToCheck);
        ans = StrList_count(list, stringToCheck);
        printf("%d", ans);
    }


    if(fromUser == 8){
        char* stringToErase;
        scanf("%s", &stringToErase);
        StrList_remove(list, stringToErase);
    }

    if(fromUser == 9){
        int index;
        scanf("%d", &index);
        StrList_removeAt(list, index);
    }

    if(fromUser == 10){
        StrList_reverse(list);
    }


    if(fromUser == 11){
        StrList_free(list);
    }

    if(fromUser == 12){
        StrList_sort(list);
    }

    if(fromUser == 13){
        int boolAns;
        boolAns = StrList_isSorted(list);
        printf("%d", boolAns);
    }

    if(fromUser == 0){
        return;
    }

}