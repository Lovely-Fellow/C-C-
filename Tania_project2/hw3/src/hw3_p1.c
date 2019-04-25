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
	return intComparator((Student *)student1->id, (Student *) studnet2->id);
}	

int nameComparator(void *student1, void *student2){
	//Insert Code here
	int result = strComparator((Student*)student1->name->lastNamme, (Student *)student2->name->lastName);
	if ((!result)
	{
		int result = strComparator((Student*)student1->name->firstName, (Student *)student2->name->firstName);
	}
	if ((!result)
	{
		int result = strComparator((Student*)student1->name->middleName, (Student *)student2->name->middleName);
	}
    return result;
}

int totalHWComparator(void *student1, void *student2){
	//Insert Code here

    return intComparator( (Student*)student1->hw_score[0] + (Student*)student1->hw_score[1] + (Student*)student1->hw_score[2],
		(Student*)student2->hw_score[0] + (Student*)student2->hw_score[1] + (Student*)student2->hw_score[2]);
}

int totalMidtermComparator(void *student1, void *student2){
	//Insert Code Here
    return intComparator( (Student*)student1->m_scores->m1_score + (Student*)student1->m_scores->m2_score,
		(Student*)student2->m_scores->m1_score + (Student*)student2->m_scores->m2_score);
}

int totalPtsComparator(void *student1, void *student2){
	//Insert Code Here
    return ((Student*)student1->hw_score[0] + (Student*)student1->hw_score[1] + (Student*)student1->hw_score[2] 
		+ (Student*)student1->m_scores->m1_score + (Student*)student1->m_scores->m2_score,
		(Student*)student2->hw_score[0] + (Student*)student2->hw_score[1] + (Student*)student2->hw_score[2] 
		+ (Student*)student2->m_scores->m2_score + (Student*)student2->m_scores->m2_score));
}

voip printCSVStudent(List_t* list){
	printList(list, STR_MODE);
	printf("\n");
}


