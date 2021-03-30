#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


void print(int N, vector<vector<int>> arr);
int findMAX(int N, int H, vector<vector<int>> arr);
class point {
public:
	int x, y;
	point(int _x, int _y) {
		x = _x; y = _y;
	}
};
int main() {

	int N = 0;
	int max = -1;
	int H = 0;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N, 0));

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (H < arr[i][j]) H = arr[i][j];
		}
	}
	//print(N,arr);

	for (int i = 0; i <= H; i++)
	{
		int count = findMAX(N, i, arr);
		//cout << "INDEX : " << i << " COUNT : "<< count;
		max = (max < count) ? count : max;
		//cout << " MAX : " << max << endl << endl;
	}
	cout << max;
}

void print(int N, vector<vector<int>> arr) {
	cout << endl << endl;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << arr[i][j];
			if (j < N - 1) cout << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
int findMAX(int N, int H, vector<vector<int>> temp) {
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	queue<point> q;
	int count = 1;
	int dx[4] = { 1,0, -1,0 };
	int dy[4] = { 0,1,0,-1 };

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = temp[i][j] <= H ? -1 : temp[i][j];
		}
	}
	//print(N, temp);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//printf("i : %d, j : %d\n", i, j);
			if (!visited[i][j] && temp[i][j] != -1) {
				//printf("count : %d, x : %d, y : %d\n", count, i, j);
				q.push(point(i, j));
				visited[i][j] = true;
				while (!q.empty()) {
					point p = q.front();
					q.pop();
					for (int k = 0;k < 4;k++) {
						int x = p.x + dx[k]; int y = p.y + dy[k];
						if ((x >= 0 && x < N) && (y >= 0 && y < N)) {
							if (temp[x][y] != -1 && !visited[x][y]) {
								//printf("count : %d, x : %d, y : %d\n", count,x, y);
								visited[x][y] = true;
								temp[x][y] = count;
								q.push(point(x, y));
							}
						}
					}
				}
				count += 1;
			}
		}
	}
	return count - 1;
}