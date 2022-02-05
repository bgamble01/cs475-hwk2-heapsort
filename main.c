#include <stdio.h>
#include "employee.h"
#include "heap.h"
#include <string.h>


#define MAX_EMPLOYEES 5

int main()
{
	struct Employee arr[MAX_EMPLOYEES]={};
	int i;
	char input[MAX_NAME_LEN];
	int b;


	for(i=0;i<MAX_EMPLOYEES;i++){
		b =0;
		printf("Name: ");
		fgets(input, MAX_NAME_LEN-1,stdin);
		input[strcspn(input,"\n")]=0;//gets rid of lagging newline character
		printf("Salary: ");
		scanf("%d",&b);
		struct Employee temp = {" ",b};
		strcpy(temp.name,input); //copies the input string into the assigned name
		printf("\n");
		arr[i]=temp; 
		int c;
		//I was having trouble with input being left over from other scans, so this ensures it is a clean slte
    	while((c = getchar()) != '\n' && c != EOF){};
		
	}
	printf("\noriginal list\n");
	printList(&arr[0],MAX_EMPLOYEES);
	printf("\n\nafter sorting\n");
	heapSort(&arr[0],MAX_EMPLOYEES);
	printList(&arr[0],MAX_EMPLOYEES);

	return 0;
}
