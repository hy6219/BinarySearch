#include <stdio.h>
#include <stdlib.h>

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

int compare(const void* _e1, const void* _e2)
{
	student* e1 = (student*)_e1;
	student* e2 = (student*)_e2;

	if (e1->score > e2->score)
	{
		return 1;
	}
	else if (e1->score < e2->score)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int len = 0;

	len = sizeof(data) / sizeof(data[0]);

	int i = 0;
	student target;
	student* check = NULL;

	//정렬
	qsort((void*)data,len, sizeof(student), compare);

	//찾기
	target.num = 0;
	target.score = 671.78;

	check = bsearch((void*)&target, (void*)&data, len, sizeof(data[0]), compare);
	if (check!= NULL)
	{
		printf("%d번\n", check->num);
	}
	else
	{
		printf("존재하지 않습니다\n");
	}
	for (int j = 0; j< len; j++)
	{
		printf("arr[%d]=%d %f\n", j, data[j].num, data[j].score);
	}
}
