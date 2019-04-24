#include "hw3_p1.h"

int intComparator(void* p, void* q) {
    return ((int)p - (int)q);
}

int strComparator(void* str1, void* str2) {
    while(*(char*)str1 && (*(char*)str1++ == *(char*)str2++))
        ;
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int idComparator(void *student1, void *student2){
	//Insert Code here
    return 2;
}	

int nameComparator(void *student1, void *student2){
	//Insert Code here
    return 2;
}

int totalHWComparator(void *student1, void *student2){
	//Insert Code here
    return 2;
}

int totalMidtermComparator(void *student1, void *student2){
	//Insert Code Here
    return 2;
}

int totalPtsComparator(void *student1, void *student2){
	//Insert Code Here
    return 2;
}


