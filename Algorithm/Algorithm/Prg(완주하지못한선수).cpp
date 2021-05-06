#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion);

int main() {

	//vector<string> paricipant = { "leo", "kiki", "eden" };
	//vector<string> completion = { "eden", "kiki" };

	vector<string> paricipant = { "mislav", "stanko", "mislav", "ana"};
	vector<string> completion = { "stanko", "ana", "mislav" };

	solution(paricipant, completion);

	return 0;
}

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> hashTable;

	for (string name : completion) {
		//++hashTable[name];
		if (hashTable.end() == hashTable.find(name))
			hashTable.insert(make_pair(name, 1));
		else
			hashTable[name] += 1;
	}
	for (string name : participant) {
		if (hashTable.end() == hashTable.find(name))
			return name;
		else {
			hashTable[name] -= 1;
			if (hashTable[name] < 0)
				return name;
		}
	}
	for (auto pair : hashTable) {
		if (pair.second > 0)
			return pair.first;
	}
}