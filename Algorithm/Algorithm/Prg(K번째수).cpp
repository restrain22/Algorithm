#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (vector<int> command : commands) {
		vector<int> copy = array;
		vector<int>::iterator iter;
		sort(copy.begin() + command[0] - 1, copy.begin() + command[1]);


		for (iter = copy.begin() + command[0] - 1; iter < copy.begin() + command[1]; iter++) {
			if (iter == copy.begin() + command[0] + command[2] - 2)
				answer.push_back(*iter);
		}
		//cout << endl;
	}

	return answer;
}