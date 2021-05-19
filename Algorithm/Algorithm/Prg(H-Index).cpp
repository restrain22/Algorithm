#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(vector<int> citations);

//int main() {
//    vector<int>citations = { 3, 0, 6, 1, 5 };
//    cout<<solution(citations);
//}
int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end(), greater<>());
	for (answer = 1; answer <= citations.size(); answer++) {
		if (citations[answer] <= answer) break;
	}
	if (!citations[0]) return 0;
	return answer;
}