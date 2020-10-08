#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//a
int get_num_of_big(int arr[], int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] > 0)
			count++;
	}

	return count;
}

//b
void num_of_big(int arr[], int length, int* amount){
	*amount = get_num_of_big(arr, length);
}

//c
void copyOdd(int A[], int sizeA, int B[], int& sizeB){
	for (int i = 0; i < sizeA; i++) {
		if (A[i] % 2 != 0) {
			B[(sizeB)++] = A[i];
		}
	}
}

//d
void removeOdd(int A[], int* size) {
	int count = *size;
	for (int i = 0; i < count; i++) {
		if (A[i] % 2 != 0) {
			for (int j = i; j < count-1; j++) {
				A[j] = A[j + 1];
			}
			A[count-1] = NULL;
			count--;
		}
	}
	
	if (A[count-1] % 2 != 0)
		A[count-1] = NULL;
	
	*size = count;
}

//e
void splitParity(int A[], int size) {
	int temp;
	for (int i = 0; i < size; i++) {
		if (A[i] % 2 != 0 && i < size / 2) {
			for (int j = i+(size / 2); j < size; j++)
			{
				if (A[j] % 2 == 0) {
					temp = A[j];
					A[j] = A[i];
					A[i] = temp;
				}
			}
		}
	}
}


/*int main(){
	//a
	int amount;
	int arr[] = { 0, 22, 1, 45, 7, 0, 1 };
	int new_arr[sizeof(arr) / sizeof(int)];
	//b
	num_of_big(arr, sizeof(arr) / sizeof(int), &amount);
	printf("%d", amount);
	printf("\n");
	//c
	amount = 0;
	copyOdd(arr, sizeof(arr) / sizeof(int), new_arr, amount);
	for (int i = 0; i < amount; i++) {
		printf("%d ", new_arr[i]);
	}
	printf("\n");
	//d
	int size = sizeof(arr) / sizeof(int);
	removeOdd(arr, &size);
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	//e
	int arr2[] = { 45, 22, 1, 7, 0, 0, 1 };
	int size2 = sizeof(arr2) / sizeof(int);
	splitParity(arr2, size2);
	for (int i = 0; i < size2; i++) {
		printf("%d ", arr2[i]);
	}
	return 0;
}*/