#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDDC_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void calculator() {
	char action;
	int leave = 1;
	while (leave) {
		scanf(" %c", &action);
		float num;
		float num1, num2, power;
		int mul = 1, sum;
		switch (action) {
			case '+':
				sum = 0;
				scanf("%f", &num);
				while (num != 0) {
					sum += (int)num;
					scanf("%f", &num);
				}
				printf("sum is: %d\n", sum);
				break;

			case '*':
				mul = 1;
				scanf("%f", &num);
				while (num != 1) {
					mul *= (int)num;
					scanf("%f", &num);
				}
				printf("multiplication is: %d\n", mul);
				break;

			case '-':
				scanf("%f %f", &num1, &num2);
				printf("difference is %d\n", (int)num1 - (int)num2);
				break;

			case '/':
				scanf("%f %f", &num1, &num2);
				if (!(int)num1) {
					printf("ERROR\n");
				}
				else {
					printf("result is %d\n", (int)num2 / (int)num1);
					if ((int)num1) {
						if ((int)num2 % (int)num1 != 0)
							printf("leftover is %d\n",(int)num2 % (int)num1);
					}
				}
				break;

			case '^':
				scanf("%f %f", &num, &power);
				mul = (int)num;
				if (!(int)num&&(int)power<0) {
					printf("Error\n");
				}
				else {
					if ((int)power > 0 || (int)power < 0) {
						for (int i = 2; i <= abs((int)power); i++)
							mul = mul * (int)num;
						if ((int)power < 0) {
							float frac = 1.0 / mul;
							printf("product is %f\n", frac);
							break;
						}
					}
					else
						mul = 1;
					printf("product is %d\n", mul);
				}
				break;

			case '_':
				printf("bye\n");
				leave = 0;
				break;

			case '\n':
				break;
			default:
				printf("???\n");

		}
	}
}


int main() {
	calculator();
	return 0;
}