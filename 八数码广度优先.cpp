#include<stdio.h>
struct node
{
	int xy[3][3];
	int dir;
};
struct node sh[102], end;
int count = 1;
void init()
{
	printf("������ʼ�ڵ��λ��:\n");
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &sh[0].xy[i][j]);
	sh[0].dir = -1;
	printf("����Ŀ��ڵ��λ��:\n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &sh[101].xy[i][j]);
	sh[101].dir = -1;
}
//�ҳ�0��λ��
int loction(int num)
{
	int i;
	for (i = 0; i < 9; i++)
		if (sh[num].xy[i / 3][i % 3] == 0) return i;
}
//���б��
long long sign(int num)
{
	long long  sum;
	sum = sh[num].xy[0][0]*100000000 + sh[num].xy[0][1]*10000000 + sh[num].xy[0][2]*1000000 + sh[num].xy[1][0]*100000 + sh[num].xy[1][1]*10000 + sh[num].xy[1][2]*1000 + sh[num].xy[2][0]*100 + sh[num].xy[2][1]*10 + sh[num].xy[2][2];
	return sum;
}
void mobile(int num)
{

	int temp;
	int loc;
	int up = 1, down = 1, left = 1, right = 1;
	loc = loction(num);
	int stand = sh[num].dir;
	//dir��0 1 2 3�ֱ������ �� �� ��
	if (loc / 3 != 0 && stand != 1)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3 - 1][loc % 3];
		sh[count].xy[loc / 3 - 1][loc % 3] = temp;
		sh[count].dir = 3;
		count++;
	};
	if (loc / 3 != 2 && stand != 3)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3 + 1][loc % 3];
		sh[count].xy[loc / 3 + 1][loc % 3] = temp;
		sh[count].dir = 1;
		count++;
	}
	if (loc % 3 != 0 && stand != 0)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3][loc % 3 - 1];
		sh[count].xy[loc / 3][loc % 3 - 1] = temp;
		sh[count].dir = 2;
		count++;
	}
	if (loc % 3 != 2 && stand != 2)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3][loc % 3 + 1];
		sh[count].xy[loc / 3][loc % 3 + 1] = temp;
		sh[count].dir = 0;
		count++;
	}

}
void display(int num)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d ", sh[num].xy[i][j]);
		printf("\n");
	}
}

int search()
{
	int i = 0;
	while (1)
	{
		printf("\n");
		display(i);
		printf("\n");
		if (i == 100)
		{
			printf("���������޴���\n");
			return 0;
		}
		if (sign(i) == sign(101))
		{
			printf("�ڵ�%d���ҵ���\n", i);
			display(i);
			return i;
		}
		mobile(i);
		i++;
	}
}

int main()
{
	init();
	search();
	return 0;
}