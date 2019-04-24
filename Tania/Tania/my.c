#include <stdio.h>
struct persion
{
	char netid[15];
	float gpa;
	char *major;
	int age;
} class[50];

//Assume class[50] is fully initialized.


/*Write a function whcic counts all the people in the class with thespecified major m, using only pointers an your strcompare function*/
int countMajor(struct persion *p, char *m, int sizeofClass)
{
	struct persion *pp;
	int i = 0;
	int count = 0;

	for (i = 0, pp = p; i < sizeofClass; i++, pp++)
	{
		if (strcompare(pp->major, m) == 1)
			count++;
	}
	return count;
}
/*Write a function whcic counts all the people in the class with netid starting with prefix, using only pointers an your submatch function*/
int countNetid(struct persion *p, char *prefix, int sizeofClass)
{
	struct persion *pp;
	int i = 0;
	int count = 0;

	char *ptr;
	int prefix_len = 0;
	while ((ptr = prefix) && (*ptr != '\0'))
	{
		prefix_len++;
		ptr++;
	}

	for (i = 0, pp = p; i < sizeofClass; i++, pp++)
	{
		if (submatch(p->netid, prefix, prefix_len, 0) == 1)
			count++;
	}
	return count;
}
/*Write a function whcic counts all the people in the class with the gpa greater than g, using only pointers*/
int countGPA(struct persion *p, float g, int sizeofClass)
{
	struct persion *pp;
	int i = 0;
	int count = 0;

	for (i = 0, pp = p; i < sizeofClass; i++, pp++)
	{
		if (pp->gpa > g)
			count++;
	}

	return count;
}

typedef struct node {
	char c;
	struct node *next;
} Node;
/* Assume Node* Listhead points at a singly linked list of initialized nodes */

/* Write a fucntion to count the number of entries in the list which contain the same c charater as Node t, using ponters only*/
int countMatchList(Node *Listhead, Node t)
{
	int count = 0;
	Node *pList = NULL;
	
	pList = Listhead;
	while (pList)
	{
		if (pList->c == t.c)
			count++;
		pList = pList->next;
	}
	return count;
}

typedef struct node2 {
	char c;
	struct node2 *next;
	struct node2 *prev;
} Node2;
/* Assume Node2* Listhead points at a singly linked list of initialized nodes */


/* Write a fucntion to determine if the elements in the list form a palendrome, using pointers only. Return 1 if yes, 0 if no
Ex: [x,a,m,a,x] or [a,b,b,a]*/
int palendromeList(Node2 *Listhead)
{
	Node2 *ListTail;
	Node2 *ph, *pt;
	int len = 0, i , half_len;

	ph = Listhead;
	while (ph)
	{
		ph = ph->next;
		ListTail = ph;
		len++;
	}
	half_len = len / 2;

	for (ph = Listhead, pt = ListTail, i = 0; i < half_len; i++, ph = ph->next, pt=pt->prev)
	{
		if (ph->c != pt->c)
			return 0; /*No*/
	}

	return 1; /*yes*/
}

typedef struct node3 {
	char *string;
	struct node3 *next;

} Node3;
/* Assume Node3* Listhead points at a singly linked list of initialized nodes */
/* Write a function to print out strings in the list which have lenghth equal to len, using only pointers and your strlen */
void printStringByLen(Node *Listhead, int len)
{
	Node3 *pList = NULL;

	pList = Listhead;
	while (pList)
	{
		if (strlenD(pList->string, '\0') == len)
			printf(pList->string);
		pList = pList->next;
	}
}

/*Given a functionwith the following definition*/
void printThreeWords(char *sentence)
{
	char *firstWord = NULL, *secondWord = NULL, *lastWord = NULL;
	//your code here
	char *ps;
	int i = 0;

	firstWord = sentence;
	for (ps = sentence; *ps && *ps != ' '; ps++);
	if (!*ps)
	{ 
		*ps = '\0'; /*Null*/

		secondWord = ++ps;
		for ( ; *ps && *ps != ' '; ps++);
		
		if (!*ps)
		{
			*ps = '\0';/*Null*/

			lastWord = ++ps;
			for (; *ps && *ps != ' '; ps++);
			
			*ps = '\0';/*Null*/
		}
	}
	printf("%s, %s, %s\n", firstWord, secondWord, lastWord);
}
/* Assume that sentence is a c string that was allocated using malloc in the calling function . Assume all words are separated by a single ' ' (space) charater.
EX: char *sentence = malloc(sizeof(char) * 24);
sentence = "Computer Science Rules !"
printThreeWords(sentences); // prints "Computer, Science, Rules !"
*/

/*Write a program in C to compute the sum of delement in an array starting at an index to a second index using pointers only. Assume indexes are within range [0,size-1]*/
//sum of all elements array[begin_index] to array[end_index]
int rangeSum(int array[], int begin_index, int end_index, int size)
{
	int *p = array;
	int i = 0;
	int sum = 0;
	for (i = 0; i < size; i++, p++)
	{
		if (i >= begin_index & i <= end_index)
		{
			sum += *p;
		}
	}
	return sum;
}

/*Write a function , using only pointers, to check if the string end occurs at the end of string. Return 1 if yes, 0 if no */
int strend(char *string, char *end)
{
	char *p = string, *prev_p = 0;
	while (p)
	{
		prev_p = p;
		p++;
	}
	if (*prev_p == *end)
		return 1;
	return 0;
}

/*Write a fucntion to reverse a string in place(in same memory as given) using only pointers*/
void reverseStr(char *string)
{
	int len = 0;
	int half_len = 0;
	int i = 0;
	char *start_p = NULL;
	char *end_p = NULL;
	char temp;
	char *p = NULL;

	/* get length */
	p = string;
	while (p && (*p != '\0'))
	{
		len++;
		p++;
	}

	half_len = len / 2;
	
	for (i = 0, start_p = string, end_p = string + len - 1; i < half_len; i++, start_p++, end_p--)
	{
		temp = *start_p;
		*start_p = *end_p;
		*end_p = temp;
	}
	/* Here, string will be reversed */
}

/*Write a function to count all non-overlapping occurrences of a substring in string s using pointers only
ex: countSubString("aaaaaabaaccacd", "aa") return 4*/
int countSubString(char *s, char *substring)
{
	char *ps, *pps;
	char *psub;
	int count = 0;

	/* return 0 if s or substring is empty string */
	if (!*s || !*substring) 
		return 0;

	for (ps = s; *ps;)
	{
		pps = ps;
		for (psub = substring; *psub; psub++, pps++)
		{
			if (*ps != *psub)/* No match */
				break;
		}
		if (*psub == 0) /*substring match*/
		{
			count++;
			ps = pps;
		}
		else
			ps++;
	}

	return count;
}

/*Write a function to count all occurrences of each of the charaters in the symbol string within string s using only pointers
Ex: countSubString2("aa!aa!!bd$ccacd", "ab!") returns 8*/
int countSubString2(char *s, char *symbol)
{
	char *ps, *psymbol;
	int count = 0;

	for (ps = s; *ps;ps++)
		for (psymbol = symbol; *psymbol; psymbol++)
			if (*ps == *psymbol)
				count++;

	return count;
}

/*Write a case-sensitive string compare function, 1:full match, 0: string don't match but are the same lenght, -1: don't mathc and are different lenghts*/
int strcompare(char *s, char *t)
{
	char *ps, *pt;
	int flag_same = 1;

	for (ps = s, pt = t; *ps && *pt; ps++, pt++)
	{
		if (*ps != *pt)
			flag_same = 0;
	}
	if (*ps == 0 && *pt == 0) /*same length */
		return flag_same;

	return -1;  /*different length */

}
/* Write a fucntion using only pointers, to find the length of string where the end of string is defined as either\0' or any character in the delimiterstring(whic is null-terminated)*/
int strlenD(char *string, char *delimiter)
{
	char *p;
	int len = 0;

	p = string;
	while (p && (*p != *delimiter))
	{
		len++;
		p++;
	}

	return len;
}
/* Write a string compare function which return 1 if the strings match of n characters startin at offset m, 0 if the strings don't match, You must check if m is within the length of both s and t.*/
int submatch(char *s, char *t, int n, int m)
{
	char *ps;
	char *pt;
	int i;
	int k;

	for (i = 0, ps = s; i < n && *ps; i++, ps++);
	
	if (i < n) /* n is bigger than length of s*/
		return 0;

	for (k = 0, pt = t; k < m && *ps && *pt; k++, ps++, pt++);

	if (k == m) /* match*/
		return 1;

	return 0;

}

/* Write a function that substitues all the occurences of the from charatoer with the to character in str using pointers only*/
char *substitue(char *str, char from, char to)
{
	char *ps;
	for (ps = str; *ps; ps++)
	{
		if (*ps == from)
			*ps|= to;
	}
	return str;
}
int main()

{
	 printThreeWords("I am a student");
}