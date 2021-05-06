#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> split1(string str, string delimeter);
vector<int> split(string str, string delimeter);
//int main() {
//
//	string str = "4x^6 + 3x^5 + 2x^4 + 1x^3 + 0x^2";
//	string delimeter = "+";
//	vector<string> result= split1(str, delimeter);
//	for (int i = 0; i < result.size(); i++)
//	{
//		cout << result[i] << endl;
//	}
//	vector<vector<int>> temp;
//	for (int i = 0;i < result.size();i++) {
//		temp.push_back(split(result[i],"x^"));
//		cout << temp[i][0] << " " << temp[i][1] << endl;
//	}
//
//}

vector<string> split1(string str,string delimeter) {
	vector<string> ret;
	string token;
	int pos = str.find(delimeter);
	while (pos!=-1) {
		token = str.substr(0, pos);
		token.erase(remove(token.begin(), token.end(), ' '),token.end());
		ret.push_back(token);
		str = str.substr(pos+delimeter.length());
		pos = str.find(delimeter);
	}
	str.erase(remove(str.begin(), str.end(), ' '), str.end());

	ret.push_back(str);
	return ret;
}

vector<int> split(string str, string delimeter) {
	vector<int> vec;
	string token;
	while (str.find(delimeter) !=-1) {
		int pos = str.find(delimeter);
		token = str.substr(0, pos);
		token.erase(remove(token.begin(), token.end(), ' '),token.end());
		vec.push_back(stoi(token));
		str = str.substr(pos + delimeter.length());
	}
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	vec.push_back(stoi(str));
	return vec;
}