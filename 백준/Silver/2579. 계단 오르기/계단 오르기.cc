#include <iostream>
#include <algorithm>

using namespace std;

int dp[305];    // 각 계단까지의 최대 점수 저장
int score[305]; // 계단 자체의 점수
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    dp[i]=dp[i-3]+dp[i-1]+score[i]//마지막에 1계단 오른거면 그 전에는 두칸 올라간것
    dp[i]=dp[i-2]+score[i]//마지막에 두계단 오름
    */

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
    }
    // 초기값 세팅
    dp[1] = score[1];
    dp[2] = score[1] + score[2]; // 1번째+2번째 밟는게 무조건 이득

    // 3번째 계단은 1->3 또는 2->3중 큰것
    dp[3] = max(score[2] + score[3], score[1] + score[3]);

    for (int i = 4; i <= n; i++)
    {
        // 2칸 점프vs1칸 점프+그 전에 2칸 점프
        dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
    }

    cout << dp[n];

    return 0;
}