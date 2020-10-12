#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//tar1
/* shuffles both stings together to 1 string (bridge shuffle)*/

//tar2
/*
(1) n1 == n2
(2) what(n1, n2 / 10)
(3) what(n1 / 10, n2)
(4) what(n1 / 10, n2 / 10)
*/

//tar3
float arr_avg(float vec[], int n)
{
	if (n == 1) return vec[0];
	return (arr_avg(vec + 1, n - 1) * (n-1) + vec[0]) / n;
}

//tar4
long dec_to_bin(int num)
{
	if (num == 1) return 1;
	if (num == 0) return 0;

	int dig = num % 2;

	return dig + dec_to_bin(num / 2) * 10;
}

//tar5
char* dec_to_hex(int num, char *str, int n)
{
	str = (char*)realloc(str, (n + 1) * sizeof(char));
	if (num < 10)
	{
		str[n-1] = num + 48;
		str[n] = '\0';
		return str;
	}

	int dig = num % 16;
	
	if (dig < 10)
		str[n - 1] = num + 48;
	else
		str[n - 1] = num + 55;
	
	str[n] = '\0';
	dec_to_hex(num / 16, str, n + 1);
}

//tar6
int trisearch(int arr[], int len, int num)
{
	if (len == 1 && arr[0] != num) return -1;

	int mid1 = len / 3 - 1;
	int mid2 = len * 2 / 3 - 1;
	
	if (arr[mid2 + 1] == num) return mid2 + 1;
	
	if (arr[mid2 + 1] < num)
		trisearch(arr + mid2, len / 3, num);

	if (arr[mid1 + 1] == num) return mid1 + 1;

	if(arr[mid1 + 1] < num)
		trisearch(arr + mid1 , len / 3, num);

	trisearch(arr, len / 3, num);
}

//tar7
/*
(1) matrixp[row][col].visit != false
(2) Insert_End_List(L, temp)
(3) col+1
(4) col
(5) row + 1
*/

//tar8
void bin(int* word, int n, int index)
{
	if (n == index)
	{
		for (int i = 0; i < n; i++)
			printf("%d", word[i]);
		printf("\n");
		return;
	}

	word[index] = 0;
	bin(word, n, index + 1);
	word[index] = 1;
	bin(word, n, index + 1);
}

void bin(int n)
{
	int* arr = (int*)malloc((int)pow(2, n) * sizeof(int));
	bin(arr, n, 0);
}

int main()
{
	//tar3
	float vec[] = { 1, 2, 3};
	printf("avg is: %.2f\n", arr_avg(vec, sizeof(vec) / sizeof(vec[0])));
	//tar4
	int dec = 10;
	printf("decimal: %d, binary: %d\n", dec, dec_to_bin(dec));
	//tar5
	char* str = NULL;
	str = dec_to_hex(dec, str, 1);
	printf("dec: %d, hex: %s\n", dec, str);
	free(str);
	//tar6
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("location is: %d\n", trisearch(arr, 9, 10));
	//tar8
	bin(3);

	return 0;
}