#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

//int main() {
//	//���� �� ����
//	int N = 0;
//	//X�� Y�� �ִ�/�ּҰ� ����, dir�� ���� ���� ����
//	int xMAX, yMAX, xMIN, yMIN, dir;
//	//X�� Y�� ��ǥ�� ����ϱ� ���� ����
//	int x, y;
//
//	//0:�� 1:�� 2:�� 3:�� ���� / ���� ������ �����̹Ƿ� dir=2
//	dir = 2; 
//
//	scanf("%d", &N);
//	
//	// (2N+1,2N+1) �迭 ����
//	vector<vector<char>> graph(2 * N+1, vector<char>(2 * N+1, '#'));
//	
//	//(N,N)�� ���������� �����ϰ� �������� # -> .�� ����(�̵� ������ ��ġ�̹Ƿ�)
//	x = y = N;
//	graph[x][y] = '.';
//
//	//�������� N�̹Ƿ� N�� �������� �Ͽ� �ִ�/�ּҰ��� ã�´�.
//	xMAX = yMAX = xMIN = yMIN = N;
//	for (int i = 0; i < N; i++)
//	{
//		char ch = ' ';
//		scanf(" %c", &ch);
//
//		//���� ������ ��
//		if (ch == 'R')
//			dir = (dir + 1) % 4;
//		//���� ������ ��
//		else if (ch == 'L')
//			dir = (4+dir - 1) % 4;
//		//������ ��
//		else {
//			switch (dir)
//			{
//			//����
//			case 0: 
//				y = y - 1;
//				graph[y][x] = '.';
//				yMIN = min(y, yMIN);
//				break;
//			//����
//			case 1:
//				x = x + 1;
//				graph[y][x] = '.';
//				xMAX = max(x, xMAX);
//				break;
//			//����
//			case 2:
//				y = y + 1;
//				graph[y][x] = '.';
//				yMAX = max(y, yMAX);
//				break;
//			//����
//			case 3:
//				x = x - 1;
//				graph[y][x] = '.';
//				xMIN = min(x, xMIN);
//				break;
//			}
//		}
//	}
//
//	//���� ��� ���
//	for (int i = yMIN; i <= yMAX; i++)
//	{
//		for (int j = xMIN; j <= xMAX; j++)
//		{
//			printf("%c", graph[i][j]);
//		}printf("\n");
//
//	}
//}
