#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//tar1
int check_for_five(int num) 
{
	if (!num) return 0;
	if (num % 10 == 5) return 1;
	check_for_five(num / 10);
}

//tar2A
int dig_sum(long num)
{
	if (!num) return num;
	return (num % 10 + dig_sum(num / 10));
}

//tar2B
int even_dig_count(int num)
{
	if (num > 0)
	{
		int dig = num % 10;
		if ( dig % 2 != 0) return even_dig_count(num / 10);
		else return 1 + even_dig_count(num / 10);
	}

	return 0;
}

//tar3
int odd_dig_check(int num)
{
	if (num > 0)
	{
		int dig = num % 10;
		if (dig % 2 != 0) return 1;
		else return odd_dig_check(num / 10);
	}

	return 0;
}

//tar4
int is_num_sidra_ola(int num)
{
	if (num==0) return 1;

	if (num % 10 < (num / 10) % 10) return 0;
	else return is_num_sidra_ola(num / 10);
}

//tar5
void put_comma(long num)
{
	if (num > 1000)
	{
		int temp = num % 1000;
		put_comma(num / 1000);
		printf(",%d", temp);
	}
	else
		printf("%d", num);
}

//tar6
long sort_num(long num)
{
	if (num >= 10)
	{
		int dig = num % 10;
		num /= 10;
		num = sort_num(num);
		if (num % 10 < dig)
		{
			int dig2 = num % 10;
			num /= 10;
			num = num * 10 + dig;
			num = sort_num(num);
			num = num * 10 + dig2;
		}
		else
			num = num * 10 + dig;
	}

	return num;
}

//tar7
int add_and_sub_digs(long num)
{
	if (num < 10) return num;
	int dig = num % 10;
	return dig - add_and_sub_digs(num / 10);
}

int product_of_eleven(long num)
{
	if (!num) return 1;
	if (abs(num) >= 1 && abs(num) <= 10) return 0;
	int ans = add_and_sub_digs(num);
	if (abs(ans) >= 10) product_of_eleven(ans);
	else if (!ans) return 1;
	else return 0;
}

//tar8
long reverse(long num)
{
	if (num < 10) return num;
	int temp = num/10, len = 0;
	while (temp)
	{
		len++;
		temp /= 10;
	}
	
	return ((num % 10) * pow(10, len) + reverse(num / 10));
}

//tar9
int dig_count(long num)
{
	if (!(num / 10)) return 1;
	return 1 + dig_count(num / 10);
}

//tar10
int max_dig(long num)
{
	if (num < 10) return num;
	int max = max_dig(num / 10);
	int dig = num % 10;
	if (max < dig) return dig;
	else return max;
}

//tar11
int rev_dig_sum(long num)
{
	if (num < 10) return num;
	int dig1 = num % 10;
	int dig2 = (num / 10) % 10;
	int sum = dig1 + -1 * dig2;
	if (num < 100) return sum;
	else return sum + rev_dig_sum(num / 100);
}

//tar12
int sub_dig_amount(int num1, int num2) {
	if (!num1 && !num2) return 0;
	else
	{
		if (num1 / 10 && num2 / 10) return sub_dig_amount(num1 / 10, num2 / 10);
		else return 1 + sub_dig_amount(num1 / 10, num2 / 10);
	}
}

int func_test() 
{
	//tar1
	printf("tar1: %d\n", check_for_five(520)); //1
	//tar2A
	printf("tar2A: %d\n", dig_sum(1203)); //6
	//tar2B
	printf("tar2B: %d\n", even_dig_count(20)); //2
	//tar3
	printf("tar3: %d\n", odd_dig_check(3420)); //1
	//tar4
	printf("tar4: %d\n", is_num_sidra_ola(145)); //1
	//tar5
	put_comma(762); //762
	printf("\n");
	//tar6
	long num = 64891213;
	num = sort_num(num); //98643211
	printf("tar6: %ld\n", num);
	//tar7
	printf("tar7: %d\n", product_of_eleven(9182712)); //1
	//tar8
	printf("tar8: %ld\n", reverse(12034)); //4321
	//tar9
	printf("tar9: %d\n", dig_count(0)); //1
	//tar10
	printf("tar10: %d\n", max_dig(91243)); //9
	//tar11
	printf("tar11: %d\n", rev_dig_sum(123)); //2

	return 0;
}