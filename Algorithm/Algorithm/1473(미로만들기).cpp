#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

//int main() {
//	//길이 값 저장
//	int N = 0;
//	//X와 Y의 최대/최소값 저장, dir은 방향 값을 저장
//	int xMAX, yMAX, xMIN, yMIN, dir;
//	//X와 Y의 좌표를 기억하기 위한 변수
//	int x, y;
//
//	//0:북 1:동 2:남 3:서 방향 / 최초 방향은 남향이므로 dir=2
//	dir = 2; 
//
//	scanf("%d", &N);
//	
//	// (2N+1,2N+1) 배열 생성
//	vector<vector<char>> graph(2 * N+1, vector<char>(2 * N+1, '#'));
//	
//	//(N,N)을 시작점으로 지정하고 시작점은 # -> .로 변경(이동 가능한 위치이므로)
//	x = y = N;
//	graph[x][y] = '.';
//
//	//시작점이 N이므로 N을 기준으로 하여 최대/최소값을 찾는다.
//	xMAX = yMAX = xMIN = yMIN = N;
//	for (int i = 0; i < N; i++)
//	{
//		char ch = ' ';
//		scanf(" %c", &ch);
//
//		//우측 방향일 때
//		if (ch == 'R')
//			dir = (dir + 1) % 4;
//		//좌측 방향일 때
//		else if (ch == 'L')
//			dir = (4+dir - 1) % 4;
//		//전진일 때
//		else {
//			switch (dir)
//			{
//			//북향
//			case 0: 
//				y = y - 1;
//				graph[y][x] = '.';
//				yMIN = min(y, yMIN);
//				break;
//			//동향
//			case 1:
//				x = x + 1;
//				graph[y][x] = '.';
//				xMAX = max(x, xMAX);
//				break;
//			//남향
//			case 2:
//				y = y + 1;
//				graph[y][x] = '.';
//				yMAX = max(y, yMAX);
//				break;
//			//서향
//			case 3:
//				x = x - 1;
//				graph[y][x] = '.';
//				xMIN = min(x, xMIN);
//				break;
//			}
//		}
//	}
//
//	//최종 결과 출력
//	for (int i = yMIN; i <= yMAX; i++)
//	{
//		for (int j = xMIN; j <= xMAX; j++)
//		{
//			printf("%c", graph[i][j]);
//		}printf("\n");
//
//	}
//}
