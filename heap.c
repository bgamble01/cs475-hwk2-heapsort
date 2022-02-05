/*
 * heapsort.c
 *
 *  Created on: Jan 4, 2022
 *      Author: David Chiu, Ben Gamble
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"


/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void heapSort(struct Employee *A, int n)
{
	buildHeap(&A[0],n);

	while(n>1){
		if(n==2){
		swap(&A[n-1],&A[0]);//since there is only 2 left, we dont need to heapify
		n--;
		}
		else{
			swap(&A[n-1],&A[0]);
			heapify(A,0,n-1);
			n--;
		}
	}
}
/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void buildHeap(struct Employee *A, int n)
{
	int i;
	for(i=n/2;i>=0;i--){
		heapify(A,i,n);
	}
}


/**
 * We want to start with A[i] and trickle it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the list
 */
void heapify(struct Employee *A, int i, int n)
{
	//calculating indexes
	int left = 2*(i+1)-1;
	int right = left+1;

	//determining smaller income
	struct Employee l = A[left];
	int lSal = l.salary;
	int rSal;
	int smaller;

	if (right>=n){
		smaller = left;
	}
	else{
		struct Employee r = A[right];
		rSal = r.salary;
		if(lSal<rSal){
			smaller = left;
		}
		else{
			smaller =right;
		}
	}

	struct Employee parent = A[i];
	int pSal = parent.salary;
	if(left==smaller){
		if(lSal<pSal){
			swap(&A[i],&A[left]);
			//make sure at least one child exists
			if(((2 * (left+1))-1)<n){ 
				heapify(A, left, n);
			}
		}
	}
	else{
		if(rSal<pSal){
			swap(&A[i],&A[right]);
			//make sure at least one child exists
			if(((2 * (right+1))-1)<n){
				heapify(A, right, n);
			}
		}
	}
	
}

/**
 * Gets the minimally paid employee. Assumes the given list is a min-heap.
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
struct Employee *getMinPaidEmployee(struct Employee *A, int n)
{
	
	return &A[0];
}


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(struct Employee *e1, struct Employee *e2)
{
	struct Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(struct Employee *A, int n)
{
	int i;
	for(i=0; i<n; i++){
		struct Employee temp = *(A+i);
		printf("[ID= %s, Salary= %d], ", temp.name,temp.salary);
	}
}

