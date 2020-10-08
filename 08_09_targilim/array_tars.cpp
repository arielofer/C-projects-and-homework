#include "array_tars.h"
#include <stdio.h>


//tar1
void add_arrays(int arr1[], int *size1, int arr2[], int size2) {
	for (int i = 0; i < size2; i++) {
		arr1[*size1 + i] = arr2[i];
	}
	*size1 += size2;
}
//tar2
void common_vals(int arr1[], int* size1, int arr2[], int size2, int new_arr[]){
	int new_size = 0;

	if (*size1 < size2) {
		for (int i = 0; i < *size1; i++) {
			for (int j = 0; j < size2; j++)
			{
				int ok = 1;
				for (int k = 0; k < new_size; k++) {
					if (arr1[i] == new_arr[k])
						ok = 0;
				}
				if (arr1[i] == arr2[j] && ok) {
					new_arr[new_size++] = arr1[i];
					break;
				}
			}
		}
	}
	else {
		for (int i = 0; i < size2; i++) {
			for (int j = 0; j < *size1; j++)
			{
				int ok = 1;
				for (int k = 0; k < new_size; k++) {
					if (arr2[i] == new_arr[k])
						ok = 0;
				}
				if (arr2[i] == arr1[j] && ok) {
					new_arr[new_size++] = arr2[i];
					break;
				}
			}
		}
	}
	*size1 = new_size;
}
//tar3
void fuse_and_sort(int A[], int sizeA, int B[], int sizeB, int C[]) {
	int i = 0, j = 0, k=0;
	while (i < sizeA || j < sizeB) {
		if (i < sizeA && j < sizeB) {
			if (A[i] < B[j]) {
				C[k++] = A[i++];
			}
			else
				C[k++] = B[j++];
		}
		else if (i == sizeA) {
			C[k++] = B[j++];
		}
		else
			C[k++] = A[i++];
	}
}
//tar4
void insert(int A[], int size, int num) {
	int i;
	if (A[0] > num)
		i = 0;
	if (A[0] == num) {
		i = 1;
	}
	else if (A[size-2] < num) {
		i = size-1;
	}
	else {
		for (i = 1; i < size-1; i++) {
			if (num > A[i - 1] && num < A[i])
				break;
		}
	}
	if (i == size -1)
		A[i] = num;
	else {
		for (int j = size-1; j > 1; j--) {
			A[j] = A[j - 1];
			if (j - 1 == i) {
				A[i] = num;
				break;
			}
		}
	}
}


void sort_by_insert(int arr[], int size, int sorted_arr[]) {
	for (int i = 0; i < size-1; i++) {
		insert(sorted_arr, i + 1, arr[i]);
	}
}

//tar5
void bubble_sort(int arr[],int start, int size) {
	int temp, count;
	for (int j = start; j < size - 1; j++) {
		count = 0;
		for (int i = start; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				count = 1;
			}
		}
		if (!count)
			break;
	}

}

//tar6
void sort_range(int arr[],int size, int i, int j) {
	if (j <= size - 1) {
		for (int w = i; w <= j; w++) {
			bubble_sort(arr, w, j+1);
		}
	}
	else {
		for (int w = i; w < size; w++) {
			bubble_sort(arr, w, size);
		}
	}
}


//tar7
void count_digs(int num, int dig_arr[]) {
	while (num) {
		for (int i = 0; i < 10; i++) {
			if (num % 10 == i) {
				dig_arr[i]++;
				num /= 10;
				break;
			}
		}
	}
}

//tar8
int biggest_rezef(int arr[], int size) {
	int current = 1;
	int max = current;
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] == arr[i + 1])
			current++;
		else {
			if (max < current)
				max = current;
			current = 1;
		}
	}
	if (max < current)
		max = current;

	return max;
}
//tar9
int all_diff(int arr[], int size) {
	for (int i = 0; i < size; i++)
		for (int j = 1; j < size; j++)
			if (i != j && arr[i] == arr[j])
				return 0;
	return 1;
}
//tar10
int count_appearence(int arr[], int size, int num) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == num)
			count++;
	}
	return count;
}
int is_contained(int arr1[], int size1, int arr2[], int size2) {
	int count = 0;
	if (size1 >= size2) {
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size2; j++) {
				if (count_appearence(arr2, size2, arr2[j]) <= count_appearence(arr1, size1, arr1[i]))
					count++;
			}
			if (count == size2)
				return 1;
		}
		return 0;
	}
	else
		return 0;
}

int is_rezef_contained(int A[], int sizeA, int B[], int sizeB) {
	int count;
	if (sizeA >= sizeB) {
		for (int j = 0; j < sizeA; j++) {
			count = 0;
			for (int i = 0; i < sizeB; i++) {
				if (B[i] == A[j]) {
					count++;
					j++;
				}
				else
					break;
			}
			if (count == sizeB)
				return 1;
		}
		return 0;
	}
	else
		return 0;
}