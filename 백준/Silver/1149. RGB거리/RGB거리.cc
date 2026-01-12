#include <iostream>
#include <algorithm>

using namespace std;

// 누적 최소 비용(마지막 색에 따라 세가지)
int dp[1005][3];
// 칠하는 비용(마지막이 빨초파인 세 경우)
int cost[1005][3];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 마지막 생각해볼까
    // i:빨 [1][0] i-1:초파 중 더 싼거min(dp[i-1][1],dp[i-1][2])+cost[i][0],i-2:빨파 중 더 싼거/빨초 중 더 싼거
    // i:파

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int r, b, g;
        cin >> r >> g >> b;
        cost[i][0] = r;
        cost[i][1] = g;
        cost[i][2] = b;
    }

    for (int i = 1; i <= n; i++)
    {
        // 마지막이 빨간색이라면 그 전 색깔 초록 또는 파란색 최소 비용+빨간색 비용
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        // 마지막이 초록색이면 그 전 색깔 빨강 또는 파란색 최소 비용+초록색 비용
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        // 마지막이 파란색이면 그 전 색깔 빨강 또는 초록색 최소 비용+파란색 비용
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);

    return 0;
}