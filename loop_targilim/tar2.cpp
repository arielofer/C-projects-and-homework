#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void trips() {
	int num1,num2,num3;
	int sum, avg_of_same_trips = 0, sum_avg_of_same_trips =0;
	float avg_of_trips = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d,%d,%d", &num1, &num2, &num3);
		sum = num1 + num2 + num3;
		printf("avg of currnet trip is %f", (float)(sum / 3));//current avg
		printf("%s", (num1 == sum / 3) ? "YES":"NO");//is first num = current avg
		avg_of_trips += (float)(sum / 3);//sum for avg
		if (num1 == num2 == num3) {
			avg_of_same_trips++;
			sum_avg_of_same_trips += num1 * 3;
		}
	}
	printf("average of all trips = %f", (float)(avg_of_trips / 5));
	if(avg_of_same_trips>0)
		printf("avg of same trips = %f", (float)(sum_avg_of_same_trips / avg_of_same_trips));
}


//int main() {
//	trips();
//
//	return 0;
//}