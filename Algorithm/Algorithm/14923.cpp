#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class point {
public:
    int x;
    int y;
    point(int x, int y) {
        this->x = x; this->y = y;
    }
};
int sol();
int bfs(vector<vector<int>> vec, point, point);

//int main() {
//
//   cout<< sol();
//}

int sol()
{
    int answer = 0;
    int N = 0, M = 0;
    int Ex = 0, Ey = 0;
    int Hx = 0, Hy = 0;
    cin >> N >> M;
    cin >> Hx >> Hy;
    cin >> Ex >> Ey;
    vector<vector<int>> graph(N, vector<int>(M, 0));
    vector<vector<int>> graphCopy(graph.size(), vector<int>(graph[0].size(),0));
    vector<int> delX; vector<int> delY;
   
    point pE(Ex-1,Ey-1), pH(Hx-1,Hy-1);
    int minCnt = INT32_MAX;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];        
            if (graph[i][j])
            {
                delX.push_back(i); delY.push_back(j);
            }
        }
    }

    for (int i = 0;i < delX.size();i++) {
        int x = delX[i]; int y = delY[i];
        copy(graph.begin(), graph.end(), graphCopy.begin());
        graphCopy[x][y] = 0;
         int comp = bfs(graphCopy, pE, pH);
        minCnt < comp ? minCnt : minCnt = comp;
       

       
    }

    return answer=minCnt;
}
int bfs(vector<vector<int>> vec, point pE, point pH){
    queue<point> queue;
    vector<vector<int>> visited(vec.size(), vector<int>(vec[0].size(),0));
    int dx[4] = { 1,0,-1,0 }; int dy[4] = { 0,-1,0,1 };
    queue.push(pH);
    
    while (!queue.empty()) {
        point now = queue.front();
        visited[now.x][now.y] += 1;
        queue.pop();
        for (int i = 0;i < 4;i++) {
            point next(now.x + dx[i], now.y + dy[i]);

            if (next.x < 0 || next.x + dx[i] > vec.size() || next.y + dy[i] < 0 || next.y + dy[i] > vec[0].size())continue;
            if (vec[next.x][next.y] || visited[next.x][next.y]) continue;
            visited[next.x][next.y] = visited[now.x][now.y];
            queue.push(next);
        }
    }

    if (!visited[pE.x][pE.y]) return -1;
    return visited[pE.x][pE.y]-1;
}