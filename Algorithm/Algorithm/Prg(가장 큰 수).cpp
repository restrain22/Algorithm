#include <string>
#include <vector>
#include<algorithm>

using namespace std;
bool compare3(string a, string b);

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> sNumbers;

	for (auto number : numbers) {
		sNumbers.push_back(to_string(number));
	}
	sort(sNumbers.begin(), sNumbers.end(), compare3);
	if (sNumbers.front() == "0")
		return "0";
	for (auto number : sNumbers) {
		answer += number;
	}
	return answer;
}
bool compare3(string a, string b) {
	return a + b > b + a;
}