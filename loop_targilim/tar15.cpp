#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int prime_2(int num) {
	if (num == 2)
		return 1;
	if (num > 2) {
		for (int i = 2; i < num; i++) {
			if (num % i == 0)
				return 0;
		}
		return 1;
	}
	else
		return 0;
}

//void how_much_prime() {
//	int counter = 0, num;
//	for (int i = 0; i < 30; i++) {
//		scanf("%d", &num);
//		if (prime(num))
//			counter++;
//	}
//	printf("total of primes is %d", counter);
//}