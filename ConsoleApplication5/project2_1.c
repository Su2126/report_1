#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void F_main_map();   //메인맵함수
void F_mini_map();   // 미니맵 함수
void woman_home();   //사람이랑 집 위치 함수
void walk();         //사람 랜덤으로 움직이는 함수
void ptr();          //포인터 생기는 함수
void hand();       //키값받는함수

void ptr_walk1();    //포인터 랜덤움직임
void ptr_walk2();
void ptr_walk3();
void ptr_walk4();

int x, y, x1, y1, i, j;     //사람, 집, 반복문 변수
int again, finish;        // while문에 넣을 변수
int p1, p2;  //포인터위치변수
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

void main()   //--------------------메인함수
{
	srand(time(NULL));
	woman_home();
	F_main_map();

	printf("\n집에 도착하였습니다.\n");
}

void woman_home()
{
	again = 1;
	while (again > 0)               //------------------------사람 위치 처음 지정
	{
		x = rand() % 12;
		y = rand() % 12;
		if (map[y][x] != 9) again = 0;
	}
	again = 1;
	while (again > 0)               //------------------------집 위치 처음 지정
	{
		x1 = rand() % 12;
		y1 = rand() % 12;
		if (map[y1][x1] != 9 && map[y][x] == 1 && map[y1][x1] == 4) again = 0;   //사람 1이면서  집이 4일때
		if (map[y1][x1] != 9 && map[y][x] == 2 && map[y1][x1] == 3) again = 0;   //사람 2이면서  집이 3일때
		if (map[y1][x1] != 9 && map[y][x] == 3 && map[y1][x1] == 2)	again = 0;   //사람 3이면서  집이 2일때
		if (map[y1][x1] != 9 && map[y][x] == 4 && map[y1][x1] == 1) again = 0;   //사람 4이면서  집이 1일때
	}
	ptr();
}

void F_main_map()
{
	while (finish == 0)
	{
		if (y == y1 && x == x1) finish = 1;
		system("cls");
		map[y1][x1] = 100;         // 집
		map[p1][p2] = 98;
		map[y][x] = 99;          //사람
		for (i = 0; i < 12; i++)
		{
			for (j = 0; j < 12; j++)
			{
				if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 0)  printf("□");   //길
				if (map[i][j] == 9)    printf("■");   //벽
				if (map[i][j] == 98)   printf("Po");   // 포인터
				if (map[i][j] == 99)   printf("♧");   //사람
				if (map[i][j] == 100)  printf("◎");   // 집
			}
			printf("\n");
		}
		Sleep(500);
		F_mini_map();
	}

}

void F_mini_map()     //----------------사람발자국 남는거 초기화
{
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 12; j++)  map[i][j] = map_2[i][j];
	}
	b = map[y][x];    //------------------사람이 움직인 후
	if (a != b)     //--------------------넘어간 분면이 전 분면과 다를시 실행
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
	if (map[y1][x1] == map[y][x])     //----집과 사람 위치 같을시 다른 모든 분면 통제
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

void walk()       //---------------------술취한사람 25%확률 걸음
{
	a = map[y][x];  //------------------사람이 움직이기 전
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
void ptr()    //-------위치 포인터값
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

void ptr_walk1()    //-----------------------------------1사분면
{
	key = rand() % 4;
	if (key == 0 && p1 > 0 && map[p1 - 1][p2] != 9)  p1 = p1 - 1;
	if (key == 1 && p1 < 5 && map[p1 + 1][p2] != 9)  p1 = p1 + 1;
	if (key == 2 && p2 > 0 && map[p1][p2 - 1] != 9)  p2 = p2 - 1;
	if (key == 3 && p2 < 5 && map[p1][p2 + 1] != 9)  p2 = p2 + 1;
}
void ptr_walk2()      //---------------------------------2사분면
{
	key = rand() % 4;
	if (key == 0 && p1 > 0 && map[p1 - 1][p2] != 9)  p1 = p1 - 1;
	if (key == 1 && p1 < 5 && map[p1 + 1][p2] != 9)  p1 = p1 + 1;
	if (key == 2 && p2 > 6 && map[p1][p2 - 1] != 9)  p2 = p2 - 1;
	if (key == 3 && p2 < 11 && map[p1][p2 + 1] != 9) p2 = p2 + 1;
}
void ptr_walk3()     //----------------------------------3사분면
{
	key = rand() % 4;
	if (key == 0 && p1 > 6 && map[p1 - 1][p2] != 9)  p1 = p1 - 1;
	if (key == 1 && p1 < 11 && map[p1 + 1][p2] != 9) p1 = p1 + 1;
	if (key == 2 && p2 > 0 && map[p1][p2 - 1] != 9)  p2 = p2 - 1;
	if (key == 3 && p2 < 5 && map[p1][p2 + 1] != 9)  p2 = p2 + 1;
}
void ptr_walk4()      //---------------------------------4사분면
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
