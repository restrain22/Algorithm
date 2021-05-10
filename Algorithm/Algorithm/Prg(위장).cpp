#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int>hash;
    int answer = 1;
    for (int i = 0; i < clothes.size(); i++) {
        ++hash[clothes[i][1]];
    }

    for (auto i : hash) {
        //cout << i.first << " " << i.second << endl;
        answer *= (i.second + 1);
    }


    return answer - 1;
}