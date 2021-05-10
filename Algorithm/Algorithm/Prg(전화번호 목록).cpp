#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
	unordered_map<string, int> hash;
	vector<string>::iterator iter;
	for (string name : phone_book) {
		hash[name] = 1;
	}

	for (auto j : phone_book) {
		string answer = "";
		for (int i = 0; i < j.size(); i++) {

			answer += j[i];
			if (answer != j && hash[answer] != 0)
			{
				return false;
			}
		}
	}

	return true;
}