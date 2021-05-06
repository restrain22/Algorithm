//#include<iostream>
//#include<stack>
//#include<algorithm>
//#pragma warning(disable:4996)
//using namespace std;
//
//int solution(string s);
//int main() {
//
//	int N = 0;
//	string str = " ";
//	scanf("%d", &N);
//	while (N--) {
//		cin >> str;
//		printf("%d",solution(str));
//	}
//	return 0;
//}
//
//int solution(string s) {
//	int answer = 0;
//	for (int j = 0; j < s.length(); j++)
//	{
//		stack<char> stack1;
//		stack<char> stack2;
//		stack<char> stack3;
//		char ch = s[0];
//		for (int i = 0;i < s.length()-1;i++) {
//			s[i] = s[i + 1];
//		}
//		s[s.length() - 1] = ch;
//		cout << s<<endl;
//		bool flag = true;
//		for (int i = 0; i < s.size(); i++)
//		{
//			flag = true;
//			if (s[i] == '(' || s[i] == ')') {
//				if (s[i] == '(') {
//					stack1.push(s[i]);
//					continue;
//				}
//				if (!stack1.empty())
//					stack1.pop();
//				else {
//					flag = false;
//					break;
//				}
//			}
//			else if (s[i] == '{' || s[i] == '}') {
//				if (s[i] == '{') {
//					stack2.push(s[i]);
//					continue;
//				}
//				if (!stack2.empty())
//					stack2.pop();
//				else {
//					flag = false;
//					break;
//				}
//			}
//			//else if (str[i] == '[' || str[i] == ']')
//			else
//			{
//				if (s[i] == '[') {
//					stack3.push(s[i]);
//					continue;
//				}
//				if (!stack3.empty())
//					stack3.pop();
//				else {
//					flag = false;
//					break;
//				}
//			}
//			//else;
//
//		}
//		if (flag)
//			answer += 1;
//	}
//
//	return answer;
//}


#include <string>
#include <vector>
#include <stack>

using namespace std;


long long solution(vector<int> a, vector<vector<int>> edges);

//int main() {
//    vector<int> a = { -5,0,2,1,2 };
//    vector<vector<int>> edges = { {0,1} ,{3,4},{2,3},{0,3} };
//    solution(a, edges);
//}


long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -2;
    vector<vector<int>> graph(a.size(),vector<int>(a.size(),-99999999));
    for (int i = 0; i < edges.size(); i++)
    {
        printf("graph[%d][%d]=%d\t", edges[i][0], edges[i][1], a[edges[i][0]]);
        printf("graph[%d][%d]=%d\n", edges[i][1], edges[i][0], a[edges[i][1]]);
        graph[edges[i][0]][edges[i][1]] = a[edges[i][1]];
        graph[edges[i][1]][edges[i][0]] = a[edges[i][0]];
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            printf(" %d", graph[i][j]);
        }printf("\n");
    }

    for (int i = 0; i < a.size(); i++)
    {
        //시작점은 i
        vector<int> copyA;
        copyA.assign(a.begin(), a.end());
        int size = copyA.size();
        stack<int> stack;
        vector<bool> visitied(a.size(), false);
        stack.push(i);
        visitied[i] = true;
        printf("%d ", i);

        while (!stack.empty()) {
            int cur = stack.top();
            int j = 0;

            for (;j < size;j++) {
                if (!visitied[j] && graph[cur][j] !=-99999999) {
                    visitied[j] = true;
                    stack.push(j);
                    printf("%d %d\t", cur,j);

                    break;
                }
            }
            if(j==size)
                stack.pop();

        }
        printf("\n");
    }


    return answer;
}