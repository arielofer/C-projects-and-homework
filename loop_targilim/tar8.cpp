#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int prime(int num) {
	//prime = 1
	if (num == 2) {
		return 1;//return prime
	}
	if (num > 2) {
		for (int i = 2; i < num/*&&prime*/; i++) {//i <= sqrt(num)&&prime
			if (num % i == 0) {
				return 0;// return prime
			}
		}
		return 1;//prime
	}
	else
		return 0;//prime
}


//int main() {
//	int num;
//	printf("enter a number\n");
//	scanf("%d", &num);
//	int ok = prime(num);
//	printf("%s", (ok ? "prime" : "not prime"));
//}