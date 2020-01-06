#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

/*
학생이라는 구조체를 만들고
거기에 점수와 번호 필드를 만들어 두기
*/
typedef struct tag
{
	int num;
	double score;
}student;

student data[] =
{
	1,1000,
	2,671.78,
	3,555.90,
	4,800,
	5,900
};

void BubbleSort(student arr[], int size)
{
	int i = 0;
	int j = 0;
	double max = 0;
	double temp = 0;
	double temp_s = 0;

	for (i = 0; i < size - 1; i++)
	{
		//최댓값을 찾는 작업 한 단계 수행을 n-1 번 수행
		for (j = 0; j < size - (i + 1); j++)
		{
			/*j원소와 j+1원소 비교
			i=0; 0...size-2
			i=1;0...size-3
			i=2;0...size-4

			=====>j<size-(i+1)
			*/
			if (arr[j].score > arr[j + 1].score)
			{
				max = arr[j].score;
				temp = arr[j + 1].score;
				arr[j + 1].score = arr[j].score;
				arr[j].score = temp;

				temp_s = arr[j+1].num;
				arr[j + 1].num = arr[j].num;
				arr[j].num = temp_s;
			}
		}
	}
}
int binarySearch(student score[], int size, double target)
{
	int init = 0;
	int fin = 0;
	fin = size - 1;
	int mid = 0;

	while (init <= fin)
	{
		mid = (init + fin) / 2;
		if (target == (score[mid].score))
		{
			return score[mid].num;
		}
		else if (target < (score[mid].score))
		{
			fin = mid - 1;
		}
		else
		{
			init = mid + 1;
		}
	}

	return -1;
}
int main()
{
	int len = 0;

	len = sizeof(data) / sizeof(data[0]);
	BubbleSort(data, len);

	double finder = 0;
	int check = 0;

	while (true)
	{
		printf("탐색할 수: ");
		scanf("%lf%*c", &finder);

		check = binarySearch(data, len, finder);

		if (check != -1)
		{
			printf("번호 : %d\n", check);
			for (int i = 0; i < len; i++)
			{
				printf("arr[%d]=%d %f\n", i, data[i].num, data[i].score);
			}
		}
		else
		{
			printf("존재하지 않습니다\n");
			for (int i = 0; i < len; i++)
			{
				printf("arr[%d]=%d %f\n", i, data[i].num, data[i].score);
			}
		}
	}

}
