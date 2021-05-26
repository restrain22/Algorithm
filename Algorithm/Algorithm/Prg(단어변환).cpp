#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;

int solution(string begin, string target, vector<string>words);
void dfs(string begin, string target, vector<string>words, vector<int> visited, int comp);
int minVal = INT_MAX;
//int main() {
//
//	string begin = "hit";
//	string target = "cog";
//	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
//
//	//vector<string> words = { "hot", "dot", "dog", "lot", "log" };
//	cout<<solution(begin, target, words);
//
//
//}

void dfs() {

}

int solution(string begin, string target, vector<string>words) {
	int answer = 0;
	vector<int> visited(words.size(), 0);
	int jump = 0;
	dfs(begin, target, words, visited,0);
	if (minVal == INT_MAX)
		answer = 0;
	else
		answer = minVal;

	return answer;
}
void dfs(string begin, string target, vector<string>words, vector<int> visited,int comp) {
	cout << begin<<" : " << comp << endl;
	if (begin == target) {
		minVal = min(comp, minVal);
		cout << minVal << endl << endl;
		return;
	}
	for (int i = 0;i < words.size();i++) {
		int count = 0;
		for (int j = 0;j < words[i].size();j++) {
			if (words[i][j] != begin[j]) {
				count += 1;
			}
		}
		if (count == 1 && !visited[i]) {
			visited[i] = 1;
			dfs(words[i], target, words, visited, comp + 1);
			visited[i] = 0;
		}
	}
}