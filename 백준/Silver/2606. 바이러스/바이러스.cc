#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[101];
bool visited[101];
int cmptr = 0; // 감염된 컴퓨터 수

// 깊이 탐색
void dfs(int node)
{
    visited[node] = true;
    cmptr++;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];

        if (!visited[next])
        {
            dfs(next);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true; // 숙주는 바이러스 감염 개수에 포함 안됨!

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int k = 0; k < graph[current].size(); k++)
        {
            int next = graph[current][k];
            if (!visited[next])
            {
                visited[next] = true;
                cmptr++;
                q.push(next);
            }
        }
    }

    cout << cmptr;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // n:컴퓨터의 수
    // m:연결된 컴퓨터의 쌍
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    cout << cmptr - 1; // 숙주 컴퓨터는 감염 개수에 포함 안 되므로 1을 뺌

    // bfs(1);

    return 0;
}