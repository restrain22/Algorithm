#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//int main() {
//	int N = 0;
//	vector<string> str;
//	int answer = 0;
//
//	cin >> N;
//	for (int i = 0;i < N;i++) {
//		string temp = "";
//		cin >> temp;
//		str.push_back(temp);
//	}
//
//	for (string line : str) {
//		for (int i = 0;i < line.length();i++) {
//			int count = 0;
//			cout << line[i] << " " << line << " " << count << endl;
//
//			while (1) {
//				if (!line.find(line[i])) {
//					break;
//				}
//				line = line.substr(line.find(line[i]) - 1);
//				count += 1;
//
//
//			}
//		}
//	}
//	cout << answer;
//}