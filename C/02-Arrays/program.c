#include <stdio.h>
#include <math.h>


int main(void)
{
	float numbers[10];// = { 2.5, 3.3, 4.1, 0.5, 4.1, 2.3, 1.1, 2.2, 1.7, 2.1};
	int count = 10;
	printf("Input items\n");
	for (int i = 0; i < count; i++) 
	{
		printf("i=%i : ", i);
		scanf_s("%f", &numbers[i]);
	}

	int indexOfMax = 0;
	float max = numbers[0];
	float sum = 0;
	for (int i = 1; i < count; i++) 
	{
		if (numbers[i] > max) 
		{
			max = numbers[i];
			indexOfMax = i;
			sum = 0;
		}
		else 
		{
			sum += numbers[i];
		}
	}
	if (indexOfMax < count - 1) {
		float avg = sum / (count - indexOfMax - 1);
		printf("max = %f, index = %i avg = %f\n", max, indexOfMax, avg);
	}
	else {
		printf("The array doesn't have any items after max element");
	}

	/*if (indexOfMax < count - 1)
	{
		float sum = 0;
		for (int i = indexOfMax + 1; i < count; i++)
		{
			sum += numbers[i];
		}
		float avg = sum / (count - indexOfMax - 1);
		printf("avg = %f", avg);
	}
	else {
		printf("The array doesn't have any items after max element");
	}*/
}