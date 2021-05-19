#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(vector<int> numbers, int target);
void dfs(vector<int> numbers, int target, int index, int sign, int sum,int& answer);
//int main() {
//
//    vector<int> numbers = { 1, 1, 1, 1, 1 };
//    int target = 3;
//    cout<<solution(numbers, target);
//    return 0;
//}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0,1,0, answer);
    return answer;
}
void dfs(vector<int> numbers, int target, int index, int sign, int sum, int& answer){

   // cout << numbers[index] * sign << " ";
    if (index == numbers.size()-1) {
        if(sum == target)
            answer += 1;
        cout << endl;
        return;
    }
    sum += numbers[index] * sign;
    dfs(numbers, target, index + 1, 1,sum,answer);
    sum += numbers[index] * sign;
    dfs(numbers, target, index + 1, -1, sum, answer);
}
