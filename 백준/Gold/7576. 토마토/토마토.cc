// bfs
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int tomato[1005][1005];
bool visited[1005][1005];

// 가로(c) 세로(r)
int m, n;
queue<pair<int, int>> q;

void bfs()
{

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];

            if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m)
            {
                continue;
            }
            // 토마토가 있고 아직 방문 안했다면
            if (tomato[next_r][next_c] != -1 && !visited[next_r][next_c])
            {
                visited[next_r][next_c] = true;
                tomato[next_r][next_c] = tomato[cur_r][cur_c] + 1; // 이게 날짜 기록
                q.push({next_r, next_c});
            }
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    int unripe = 0;

    // 토마토 집어넣기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            tomato[i][j] = t;

            // 안익은 토마토 개수
            if (tomato[i][j] == 0)
            {
                unripe++;
            }

            // 익은 토마토 넣기
            if (tomato[i][j] == 1)
            {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    // 안익은 토마토 없을떄
    if (unripe == 0)
    {
        cout << 0;
        return 0;
    }

    // tomato 순회
    bfs();

    // 최대값 찾기
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 안익은 토마토 남아있으면
            if (tomato[i][j] == 0)
            {
                cout << -1;
                return 0;
            }

            // 가장 오래 걸린 날짜 찾기
            if (tomato[i][j] >= temp)
            {
                temp = tomato[i][j];
            }
        }
    }
    cout << temp - 1;

    return 0;
}