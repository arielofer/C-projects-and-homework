#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int base_convert() {
	int num, src_base = 2, dest_base = 10;
	printf("enter a nuber, its base and the base u want to convert to\n");
	scanf("%d %d %d", &num, &src_base, &dest_base);
	int temp = num, length = 0;
	while (temp) {
		if (temp % 10 >= src_base){
			printf("ERROR");
			return 0;
		}
		length++;
		temp /= 10;
	}

	int num_in_decimal = 0;
	for (int i = 0; i < length; i++) {
		num_in_decimal += (num % 10) * pow(src_base, i);
		num /= 10;
	}

	int num_to_return = 0, pow_count = 0;
	while (num_in_decimal) {
		num_to_return += (num_in_decimal % dest_base) * pow(10, pow_count);
		num_in_decimal /= dest_base;
		pow_count++;
	}

	printf("%d", num_to_return);
	return 0;
}


//int main() {
//	base_convert();
//
//	return 0;
//}