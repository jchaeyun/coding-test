// 최소칸이니까 bfs?
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;
int map[105][105];
bool visited[105][105];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // map에 입력받기
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    // 상,하,좌,우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // bfs
    // 인접한 값이 1이고 !visited면 이동

    queue<pair<int, int>> q;

    // 시작 지점
    q.push({0, 0});
    // 방문 표시
    visited[0][0] = true;

    while (!q.empty())
    {
        // 현재 위치
        int current_r = q.front().first;
        int current_c = q.front().second;
        q.pop();

        // 상하좌우 움직임
        for (int u = 0; u < 4; u++)
        {

            int next_r = current_r + dr[u];
            int next_c = current_c + dc[u];

            // 맵 밖을 나가는지 체크!!!
            if (next_r >= n || next_r < 0 || next_c >= m || next_c < 0)
            {
                continue;
            }
            // 상하좌우 칸 중에 값이 1이고 아직 방문 안한게 있으면
            if (map[next_r][next_c] == 1 && !visited[next_r][next_c])
            {
                visited[next_r][next_c] = true;                      // 방문 표시
                map[next_r][next_c] = map[current_r][current_c] + 1; // 거리 표시
                q.push({next_r, next_c});                            // 큐에 넣음
            }
        }
    }

    cout << map[n - 1][m - 1];

    return 0;
}