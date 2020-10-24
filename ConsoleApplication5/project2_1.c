#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void F_main_map();   //���θ��Լ�
void F_mini_map();   // �̴ϸ� �Լ�
void woman_home();   //����̶� �� ��ġ �Լ�
void walk();         //��� �������� �����̴� �Լ�
void ptr();          //������ ����� �Լ�
void hand();       //Ű���޴��Լ�

void ptr_walk1();    //������ ����������
void ptr_walk2();
void ptr_walk3();
void ptr_walk4();

int x, y, x1, y1, i, j;     //���, ��, �ݺ��� ����
int again, finish;        // while���� ���� ����
int p1, p2;  //��������ġ����
int key = 0, a = 0, b = 0;
int map[12][12] =
{
	{ 9,9,9,9,1,1,2,2,2,2,2,9 },
	{ 1,1,1,1,1,1,2,9,2,9,2,9 },
	{ 1,1,9,9,9,9,2,9,2,9,2,9 },
	{ 1,1,1,1,1,1,2,9,2,9,2,9 },
	{ 1,9,9,9,9,1,2,9,2,2,2,9 },
	{ 1,1,1,1,1,1,2,2,2,2,2,9 },
	{ 3,9,9,9,9,3,4,4,4,4,4,4 },
	{ 3,3,3,3,3,3,4,9,9,9,9,4 },
	{ 3,9,9,9,3,3,4,4,4,4,4,4 },
	{ 3,9,3,3,3,3,4,9,9,9,9,4 },
	{ 3,9,3,3,9,9,4,4,4,4,4,4 },
	{ 3,3,3,3,3,3,4,4,9,9,9,9 }
};
int map_2[12][12] =
{
	{ 9,9,9,9,1,1,2,2,2,2,2,9 },
	{ 1,1,1,1,1,1,2,9,2,9,2,9 },
	{ 1,1,9,9,9,9,2,9,2,9,2,9 },
	{ 1,1,1,1,1,1,2,9,2,9,2,9 },
	{ 1,9,9,9,9,1,2,9,2,2,2,9 },
	{ 1,1,1,1,1,1,2,2,2,2,2,9 },
	{ 3,9,9,9,9,3,4,4,4,4,4,4 },
	{ 3,3,3,3,3,3,4,9,9,9,9,4 },
	{ 3,9,9,9,3,3,4,4,4,4,4,4 },
	{ 3,9,3,3,3,3,4,9,9,9,9,4 },
	{ 3,9,3,3,9,9,4,4,4,4,4,4 },
	{ 3,3,3,3,3,3,4,4,9,9,9,9 }
};

void main()   //--------------------�����Լ�
{
	srand(time(NULL));
	woman_home();
	F_main_map();

	printf("\n���� �����Ͽ����ϴ�.\n");
}

void woman_home()
{
	again = 1;
	while (again > 0)               //------------------------��� ��ġ ó�� ����
	{
		x = rand() % 12;
		y = rand() % 12;
		if (map[y][x] != 9) again = 0;
	}
	again = 1;
	while (again > 0)               //------------------------�� ��ġ ó�� ����
	{
		x1 = rand() % 12;
		y1 = rand() % 12;
		if (map[y1][x1] != 9 && map[y][x] == 1 && map[y1][x1] == 4) again = 0;   //��� 1�̸鼭  ���� 4�϶�
		if (map[y1][x1] != 9 && map[y][x] == 2 && map[y1][x1] == 3) again = 0;   //��� 2�̸鼭  ���� 3�϶�
		if (map[y1][x1] != 9 && map[y][x] == 3 && map[y1][x1] == 2)	again = 0;   //��� 3�̸鼭  ���� 2�϶�
		if (map[y1][x1] != 9 && map[y][x] == 4 && map[y1][x1] == 1) again = 0;   //��� 4�̸鼭  ���� 1�϶�
	}
	ptr();
}

void F_main_map()
{
	while (finish == 0)
	{
		if (y == y1 && x == x1) finish = 1;
		system("cls");
		map[y1][x1] = 100;         // ��
		map[p1][p2] = 98;
		map[y][x] = 99;          //���
		for (i = 0; i < 12; i++)
		{
			for (j = 0; j < 12; j++)
			{
				if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 0)  printf("��");   //��
				if (map[i][j] == 9)    printf("��");   //��
				if (map[i][j] == 98)   printf("Po");   // ������
				if (map[i][j] == 99)   printf("��");   //���
				if (map[i][j] == 100)  printf("��");   // ��
			}
			printf("\n");
		}
		Sleep(500);
		F_mini_map();
	}

}

void F_mini_map()     //----------------������ڱ� ���°� �ʱ�ȭ
{
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 12; j++)  map[i][j] = map_2[i][j];
	}
	b = map[y][x];    //------------------����� ������ ��
	if (a != b)     //--------------------�Ѿ �и��� �� �и�� �ٸ��� ����
	{
		for (i = 0; i < 12; i++)
		{
			for (j = 0; j < 12; j++)
			{
				if (map[i][j] == a)
				{
					map[i][j] = 0;
					map_2[i][j] = 0;
				}
			}
		}
		ptr();
	}
	if (map[y1][x1] == map[y][x])     //----���� ��� ��ġ ������ �ٸ� ��� �и� ����
	{
		for (i = 0; i < 12; i++)
		{
			for (j = 0; j < 12; j++)
			{
				if (map[i][j] != map[y1][x1] && map[i][j] != 9)
				{
					map[i][j] = 0;
				}
				map_2[i][j] = map[i][j];
			}
		}
	}
	walk();
}

void walk()       //---------------------�����ѻ�� 25%Ȯ�� ����
{
	a = map[y][x];  //------------------����� �����̱� ��
	if (x == p2 && y == p1)
	{
		hand();
	}
	if (x != p2 || y != p1)
	{
		key = rand() % 4;
		if (key == 0 && y > 0 && map[y - 1][x] != 9 && map[y - 1][x] != 0)  y = y - 1;
		if (key == 1 && y < 11 && map[y + 1][x] != 9 && map[y + 1][x] != 0) y = y + 1;
		if (key == 2 && x > 0 && map[y][x - 1] != 9 && map[y][x - 1] != 0)  x = x - 1;
		if (key == 3 && x < 11 && map[y][x + 1] != 9 && map[y][x + 1] != 0) x = x + 1;
		if (map[y][x] == 1) ptr_walk1();
		if (map[y][x] == 2) ptr_walk2();
		if (map[y][x] == 3) ptr_walk3();
		if (map[y][x] == 4) ptr_walk4();
	}
	F_main_map();
}
void ptr()    //-------��ġ �����Ͱ�
{
	again = 1;
	if (map[y][x] == 1)
	{
		while (again > 0)
		{
			p1 = rand() % 12;
			p2 = rand() % 12;
			if (map[p1][p2] != 9 && map[p1][p2] == 1) again = 0;
		}
	}
	if (map[y][x] == 2)
	{
		while (again > 0)
		{
			p1 = rand() % 12;
			p2 = rand() % 12;
			if (map[p1][p2] != 9 && map[p1][p2] == 2) again = 0;
		}
	}
	if (map[y][x] == 3)
	{
		while (again > 0)
		{
			p1 = rand() % 12;
			p2 = rand() % 12;
			if (map[p1][p2] != 9 && map[p1][p2] == 3) again = 0;
		}
	}
	if (map[y][x] == 4)
	{
		while (again > 0)
		{
			p1 = rand() % 12;
			p2 = rand() % 12;
			if (map[p1][p2] != 9 && map[p1][p2] == 4) again = 0;
		}
	}
}

void ptr_walk1()    //-----------------------------------1��и�
{
	key = rand() % 4;
	if (key == 0 && p1 > 0 && map[p1 - 1][p2] != 9)  p1 = p1 - 1;
	if (key == 1 && p1 < 5 && map[p1 + 1][p2] != 9)  p1 = p1 + 1;
	if (key == 2 && p2 > 0 && map[p1][p2 - 1] != 9)  p2 = p2 - 1;
	if (key == 3 && p2 < 5 && map[p1][p2 + 1] != 9)  p2 = p2 + 1;
}
void ptr_walk2()      //---------------------------------2��и�
{
	key = rand() % 4;
	if (key == 0 && p1 > 0 && map[p1 - 1][p2] != 9)  p1 = p1 - 1;
	if (key == 1 && p1 < 5 && map[p1 + 1][p2] != 9)  p1 = p1 + 1;
	if (key == 2 && p2 > 6 && map[p1][p2 - 1] != 9)  p2 = p2 - 1;
	if (key == 3 && p2 < 11 && map[p1][p2 + 1] != 9) p2 = p2 + 1;
}
void ptr_walk3()     //----------------------------------3��и�
{
	key = rand() % 4;
	if (key == 0 && p1 > 6 && map[p1 - 1][p2] != 9)  p1 = p1 - 1;
	if (key == 1 && p1 < 11 && map[p1 + 1][p2] != 9) p1 = p1 + 1;
	if (key == 2 && p2 > 0 && map[p1][p2 - 1] != 9)  p2 = p2 - 1;
	if (key == 3 && p2 < 5 && map[p1][p2 + 1] != 9)  p2 = p2 + 1;
}
void ptr_walk4()      //---------------------------------4��и�
{
	key = rand() % 4;
	if (key == 0 && p1 > 6 && map[p1 - 1][p2] != 9)  p1 = p1 - 1;
	if (key == 1 && p1 < 11 && map[p1 + 1][p2] != 9) p1 = p1 + 1;
	if (key == 2 && p2 > 6 && map[p1][p2 - 1] != 9)  p2 = p2 - 1;
	if (key == 3 && p2 < 11 && map[p1][p2 + 1] != 9) p2 = p2 + 1;
}

void hand()
{
	key = getch();
	if (key == 72 && map[y - 1][x] != 9 && map[y - 1][x] != 0 && y > 0 && map[p1 - 1][p2] != 9 && map[p1 - 1][p2] != 0 && p1 > 0)
	{
		y = y - 1;
		p1 = p1 - 1;
	}
	if (key == 80 && map[y + 1][x] != 9 && map[y + 1][x] != 0 && y < 11 && map[p1 + 1][p2] != 9 && map[p1 + 1][p2] != 0 && p1 < 11)
	{
		y = y + 1;
		p1 = p1 + 1;
	}
	if (key == 77 && map[y][x + 1] != 9 && map[y][x + 1] != 0 && x < 11 && map[p1][p2 + 1] != 9 && map[p1][p2 + 1] != 0 && p2 < 11)
	{
		x = x + 1;
		p2 = p2 + 1;
	}
	if (key == 75 && map[y][x - 1] != 9 && map[y][x - 1] != 0 && x > 0 && map[p1][p2 - 1] != 9 && map[p1][p2 - 1] != 0 && p1 > 0)
	{
		x = x - 1;
		p2 = p2 - 1;
	}
	map[p1][p2] = 98;
}
