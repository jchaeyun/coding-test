#include <iostream>
#include <algorithm>

using namespace std;

int dp[15];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 1; // 1
    dp[2] = 2; // 1+1,2
    dp[3] = 4; // 1+1+1,1+2,2+1,3

    // 2.점화식으로 미리 다 채워놓기(4부터 10(최대값)까지)
    for (int i = 4; i <= 10; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    // 3.물어보는 숫자에 따라 대답하기
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}