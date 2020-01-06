#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

int binarySearch(int arr[],int size,int target)
{
	int mid = 0;

	int init = 0;
	int fin = size - 1;

	while (init <= fin)
	{
		//탐색범위가 0이 될때까지 반복
		mid = (init + fin) / 2;
		if (target == arr[mid])
		{
			return mid;//인덱스 반환
		}
		else if (target < arr[mid])
		{
			//목표값<중위값 --> 왼쪽을 대상으로 탐색
			fin = mid - 1;
		}
		else
		{
			//목표값>중위값-->오른쪽을 대상으로 탐색
			init = mid + 1;
		}

	
		
	}
	return -1;
}

int main()
{
	int arr[] = {100,101,102,103,104};

	int finder = 0;
	int check = 0;
	int len = 0;

	len = sizeof(arr) / sizeof(arr[0]);

	while (true)
	{
		printf("해당 수가 있나요?: ");
		scanf("%d%*c", &finder);

		check = binarySearch(arr, len, finder);

		if (check != -1)
		{
			printf("존재합니다\n");

			for (int i = 0; i < len; i++)
			{
				printf("arr[%d]=%d\n", i, arr[i]);
			}
		}
		else
		{
			printf("존재하지 않습니다\n");
		}
	}
}
