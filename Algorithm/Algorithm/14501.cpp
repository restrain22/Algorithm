#include<iostream>
#include<vector>

using namespace std;	

vector<int> T, P;
vector<int> MEM;
vector<bool> visited(100,false);
int N;

int dp(int i);
//int main() {
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		int a = 0; int b = 0;
//		cin >> a >> b;
//		T.push_back(a); P.push_back(b);
//		MEM.push_back(0);
//	}
//	dp(0);
//	return 0;
//}
int dp(int i) {
	cout << "진입 시도 | i : " << i+1 << ", i+T[i] : " << i+1 + T[i] << " ";
	if (i + T[i] >= N  || visited[i+T[i]]) {
		cout <<" i+T[i]"<< endl;
		return 0;
	}
	if (i >= N || visited[i]) {
		cout << "i+1"<<endl;
		return 0;
	}
	visited[i] = true;

		cout <<"진입 성공 | i : "<< i+1<<", i+T[i] : "<<i+1+T[i] << " " << endl;

	//MAX값 입력
	MEM[i] = MEM[i]>P[i]?MEM[i]:P[i];
	
	dp(i+T[i]);
	visited[i] = false;

	dp(i+1);
	visited[i] = false;

}