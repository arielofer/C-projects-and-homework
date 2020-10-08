#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Not_main_as_well() {
	int arr[] = { 6, 3, 5, 2, 4, 7, 1, 1 };
	const int len = sizeof(arr) / sizeof(arr[0]);
	int *sort;
	FILE *Nsort, *temp, *sorted;
	int num, min, count = 0, same_count = 0, flag;

	//place array in file
	Nsort = fopen("not_sorted.dat", "wb");
	fwrite(arr, sizeof(int), len, Nsort);
	fclose(Nsort);

	Nsort = fopen("not_sorted.dat", "rb");
	sorted = fopen("sorted.dat", "wb");
	while (count<len) //!feof(Nsort)
	{
		//place minimum in new file
		fread(&min, sizeof(int), 1, Nsort);
		while (!feof(Nsort)) {
			fread(&num, sizeof(int), 1, Nsort);
			if (min > num)
				min = num;
		}
		fclose(Nsort);

		//check if appears more then once
		temp = fopen("sorted.dat", "rb");
		flag = 0;
		fread(&num, sizeof(int), 1, temp);
		if (num == min && !feof(temp)) {
			same_count++;
			flag = 1;
		}
		while (!feof(temp))
		{
			fread(&num, sizeof(int), 1, temp);
			if (num == min) {
				same_count++;
				flag = 1;
				break;
			}
		}
		if(!flag)
			fwrite(&min, sizeof(int), 1, sorted);
		fclose(temp);

		//move all other ints except int to new file
		temp = fopen("temp.dat", "wb");
		Nsort = fopen("not_sorted.dat", "rb");
		while (!feof(Nsort))
		{
			fread(&num, sizeof(int), 1, Nsort);
			if (num != min)
				fwrite(&num, sizeof(int), 1, temp);
		}
		fclose(Nsort);
		fclose(temp);

		//write back to original file
		temp = fopen("temp.dat", "rb");
		Nsort = fopen("not_sorted.dat", "wb");
		while (!feof(temp))
		{
			fread(&num, sizeof(int), 1, temp);
			fwrite(&num, sizeof(int), 1, Nsort);
		}
		fclose(Nsort);
		fclose(temp);

		Nsort = fopen("not_sorted.dat", "rb");
		count++;
	}

	_fcloseall();

	//place sorted content to new array
	sorted = fopen("sorted.dat", "rb");
	sort = (int*)calloc(len - same_count, sizeof(int));
	fread(sort, sizeof(int), len-same_count, sorted);
	fclose(sorted);

	//print
	for (int i = 0; i < len-same_count; i++)
		printf("%d, ", sort[i]);

	return 0;
}