#include <stdlib.h>
#include <stdio.h>
#include "StrList.h"
#include <string.h>
#include <sys/cdefs.h>



typedef struct _string{
    char* _data;
    struct _string * _nextString
} String;

struct _StrList{
    String* _head;
    size_t _size;
};



///////////////////////////////////////////////////////////////////////////

String* String_alloc(char* data, String* next){
    String* p = (String*)malloc(sizeof(String));
    p->_data = data;
    p->_nextString = next;
    return p;
}

void String_free(String* string){
    free(string);
}



StrList* StrList_alloc(){
    StrList* p = (StrList*)malloc(sizeof(StrList));
    p->_head = NULL;
    p->_size = 0;
    return p;
}


void StrList_free(StrList* StrList){
    if(StrList == NULL)return;
    String* p = StrList->_head;
    String* p2;
    while(p){
        p2 = p;
        p = p->_nextString;
        String_free(p2);
    }
}


size_t StrList_size(const StrList* StrList){
    return StrList->_size;
}




void StrList_insertLast(StrList* StrList, const char* data){
    String* plast = String_alloc(data, NULL);
    if(StrList == NULL){
        StrList->_head = plast;
        return;
    }
    String* p = StrList->_head;
    while(p){
        p = p->_nextString;
    }
    p = plast;
    StrList->_size += 1;
    return;
}


void StrList_insertAt(StrList* StrList, const char* data,int index){
    String* p = StrList->_head;
    int i;
    for(i=0; i<index; i++){
        if(i+1 == index){
            String* newString = String_alloc(data, p->_nextString);
            p->_nextString = newString;
            StrList->_size +=1;
            return;
        }   
        p = p->_nextString;
    }
}


char* StrList_firstData(const StrList* StrList){
    return StrList->_head->_data;
}


void StrList_print(const StrList* StrList){
    if(StrList == NULL) return;
    String* p = StrList->_head;
    while(p != NULL){
        int i;
        for(i=0; i<sizeof(p->_data); i++){
            printf("%c", p->_data[i]);
        }
        p = p->_nextString;
    }
}


void StrList_printAt(const StrList* Strlist,int index){
    String* p = Strlist->_head;
    int i=0;
    while(i<index){
        p = p->_nextString;
        i+=1;
    }
    int j;
    for(j=0; j<sizeof(p->_data); j++){
        printf("%c", p->_data[j]);
    }
}


int StrList_printLen(const StrList* Strlist){
    int ans=0;
    if(Strlist == NULL) return ans;
    String* p = Strlist->_head;
    while(p->_data != NULL){
        ans += strlen(p->_data);
        p = p->_nextString;
    }
    return ans;
}



int StrList_count(StrList* StrList, const char* data){
    int ans=0;
    if(StrList == NULL) return ans;
    String* p = StrList->_head;
    while(p != NULL){
        if(strcmp(p, data) == 0){
            ans+=1;
        }
        p = p->_nextString;
    }
    return ans;
}


void StrList_remove(StrList* StrList, const char* data){
    if(StrList_count(StrList, data) == 0) return;
    String* p = StrList->_head;
    String* phelper;
    while( p!=NULL){
        if(strcmp(p, data)==0){
        phelper = p;
        p = p->_nextString;
        String_free(phelper);
        StrList->_size -=1;
    }
    }
}


void StrList_removeAt(StrList* StrList, int index){
    if(StrList == NULL) return;
    String* p = StrList->_head;
    String* phelper;
    int i=0;
    while(i<index){
        p = p->_nextString;
        i+=1;
    }
    phelper = p;
    p = p->_nextString;
    String_free(phelper);
    StrList->_size -=1;
}



/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if(StrList1->_size != StrList2->_size)return 0;
    String* p1 = StrList1->_head;
    String* p2 = StrList2->_head;
    while(p1 != NULL){
        if(strcmp(p1, p2) != 0) return 0;
        p1 = p1->_nextString;
        p2 = p2->_nextString;
    }
    return 1; 
}


/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* StrList1){
    StrList* StrList2 = StrList_alloc();
    String* p1 = StrList1->_head;
    String* p2 = StrList2->_head;
    while(p1!=NULL){
        p2->_data = p1->_data;
        p1->_nextString;
        p2->_nextString;
    }
    return StrList2;
}


void StrList_reverse( StrList* StrList){
    if(StrList == NULL || sizeof(StrList)/sizeof(StrList[0]) == 1) return; 
    String* p = StrList->_head;
    String* phelplast = NULL;
    String* phelpnext;
    while(p != NULL){
        phelpnext = p;
        p = p->_nextString;
        phelpnext->_nextString = phelplast;
        phelplast = phelpnext;
    }
}


void StrList_sort(StrList* StrList){
    if(StrList == NULL || sizeof(StrList)/sizeof(StrList[0]) == 1) return; 
    String* p = StrList->_head;
    String* phelper;
    String* phelper2;
    while( p!=NULL){
        if(p->_nextString == NULL) return;
        phelper = p->_nextString;
        while(phelper!=NULL){
            if(strcmp(p, phelper) > 0){
                swap2Strings(p, phelper);
        }
        phelper = p->_nextString;
    }
    p->_nextString;
}
}


void swap2Strings(String* first, String* second){
    String* p;
    p = first;
    first = second;
    second = p;
}


int StrList_isSorted(StrList* StrList){
    if(StrList == NULL || sizeof(StrList)/sizeof(StrList[0]) == 1) return 1; 
    String* p = StrList->_head;
    String* phelper = StrList->_head->_nextString;
    while(phelper != NULL){
        if(strcmp(p, phelper) >0) return 0;
        p = p->_nextString;
        phelper = phelper->_nextString;
    }
    return 1;
}






