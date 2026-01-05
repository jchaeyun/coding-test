#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> //BFS를 위해

using namespace std;

// N이 최대 1000이므로 넉넉하게 1001로 선언(1번 인덱스부터 쓰기 위함)
vector<int> graph[1001];
bool visited[1001];

// 1.DFS(깊이 우선 탐색)-재귀함수 사용
void dfs(int node)
{
    visited[node] = true; // 방문 체크
    cout << node << " ";  // 방문 순서 출력

    // 연결된 노드들을 순회
    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];
        // 아직 방문하지 않은 곳이면 깊숙히 들어감
        if (!visited[next])
        {
            dfs(next);
        }
    }
}

// 2.BFS(너비 우선 탐색)-큐 사용
void bfs(int start)
{
    queue<int> q;
    q.push(start);         // 시작점 큐에 넣기
    visited[start] = true; // 방문 체크

    while (!q.empty())
    {
        // 큐의 맨 앞을 꺼냄
        int current = q.front();
        q.pop();
        cout << current << " ";

        // 꺼낸 노드와 연결된 친구들을 모두 검사
        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            // 방문 안 했으면 큐에 줄 세우기(예약)
            // 여기서 방문 체크를 해야함. 한 노드와 연결된 건 여러개일수 있으니
            // 큐에서 꺼낸 하나만 방문체크를 하면 중복 방문됨
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, start; // 정점 개수, 간선 개수, 시작 정점
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // 양방향 간선 처리 (중요!)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //[중요 조건] 정점 번호가 작은 것을 먼저 방문하기 위해 정렬
    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS 실행
    dfs(start);
    cout << '\n';

    // BFS 실행 전 방문 기록 초기화(필수!)
    // fill(시작 주소, 끝 주소, 채울 값);
    // visited 배열의 처음(0번)부터 n번 인덱스까지 전부 false로 채워라
    // 주의:끝주소는 포함하지 않으므로 1을 더해줘야 n번까지 칠해짐
    fill(visited, visited + n + 1, false);

    // BFS 실행
    bfs(start);
    cout << '\n';

    return 0;
}
