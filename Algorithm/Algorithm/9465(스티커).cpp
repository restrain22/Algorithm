#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int T, N;

	cin >> T;

	while (T--) {
		cin >> N;
		vector<vector<int>> arr(2, vector<int>(N, 0)),dp(2,vector<int>(N,0));

		for (int j = 0;j < 2;j++) {
			for (int i = 0;i < N;i++) {
				cin >> arr[j][i];
			}
		}

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < 2;j++) {
				if (i == 0) {
					dp[j][i] = arr[j][i];
				}
				if (i == 1) {
					dp[j][i] = arr[j][i] + dp[!j][i - 1];
				}
				if (i > 1) {
					dp[j][i] = max(max(dp[0][i-2], dp[1][i-2]), dp[!j][i - 1]) + arr[j][i];
				}
			}
		}
		cout << max(dp[0][N - 1], dp[1][N - 1]) << endl;;
	}


}