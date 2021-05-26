#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solution1(int X);

int dp[1000001];
//int main() {
//	int X = 0;
//	cin >> X;
//	cout << solution1(X);
//	return 0;
//}

int solution1(int X) {
	if (X <= 1) return 0;
	if (dp[X] > 0) return dp[X];
	dp[X] = solution1(X-1) + 1;
	if (X % 2 == 0) {
		int temp = solution1(X / 2) + 1;
		dp[X] = min(dp[X], temp);
	}
	if (X % 3 == 0) {
		int temp = solution1(X / 3)+1;
		dp[X] = min(dp[X], temp);
	}	
	return dp[X];
}