// 인접해있는거면 bfs

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
int cabbage[55][55];
bool visited[55][55];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    // 상하좌우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int i = 0; i < t; i++)
    {
        // [중요] 테스트 케이스마다 맵과 방문기록을 깨끗하게 지워야 함!
        fill(&cabbage[0][0], &cabbage[0][0] + 55 * 55, 0);
        fill(&visited[0][0], &visited[0][0] + 55 * 55, false);

        // 지렁이 개수(테스트 하나 끝나면 초기화해야함)
        int worm = 0;

        int m, n, k;
        cin >> m >> n >> k;

        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;

        // 배추 심은 위치 표시
        for (int j = 0; j < k; j++)
        {
            int r, c;
            cin >> r >> c;
            cabbage[r][c] = 1;
            q1.push({r, c});
        }

        while (!q1.empty())
        {
            // 새로운 배추 그룹
            int start_r = q1.front().first;
            int start_c = q1.front().second;

            q1.pop();

            // 이미 방문한 시작점이면 건너뜀
            if (visited[start_r][start_c])
            {
                continue;
            }

            q2.push({start_r, start_c});      // 새로운 시작점을 큐에 넣음
            visited[start_r][start_c] = true; // 시작점 방문 표시
            worm++;                           // 지렁이 한마리 투입

            // 배추 그룹 bfs 탐색
            while (!q2.empty())
            {
                int current_r = q2.front().first;
                int current_c = q2.front().second;
                q2.pop();

                // 인접한 상하좌우 배추 순회
                for (int v = 0; v < 4; v++)
                {
                    int next_r = current_r + dr[v];
                    int next_c = current_c + dc[v];

                    // 좌표 범위 넘어가면 다른 곳으로 이동
                    if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n)
                    {
                        continue;
                    }

                    if (cabbage[next_r][next_c] == 1 && !visited[next_r][next_c])
                    {
                        visited[next_r][next_c] = true; // 방문 표시
                        q2.push({next_r, next_c});      // 큐에 추가
                    }
                }
            }
        }

        cout << worm << '\n';
    }

    return 0;
}
