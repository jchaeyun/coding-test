#include <iostream>
#include <algorithm>

using namespace std;

int gp[505][505];
int score[505][505];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 왼쪽 오른쪽 중 큰거 고르면 되는거 아님?
    // 마지막에 왼쪽을 선택했는지or오른쪽 선택했는지
    // 그전 최대값+왼쪽값, 그전최대값+오른쪽값
    // 대각선 왼,오만 갈수 있다는 것은
    //[2][i] 였다면 [3][i],[3][i+1]만 갈 수 있다는것

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> score[i][j];
        }
    }

    gp[1][0] = score[1][0];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // 오른쪽 끝일때
            if ((j + 1) == i)
            {
                gp[i][j] = gp[i - 1][j - 1] + score[i][j];
            }
            // 왼쪽 끝일때
            else if (j == 0)
            {
                gp[i][j] = gp[i - 1][j] + score[i][j];
            }
            // 그 외
            else
            {
                gp[i][j] = max(gp[i - 1][j - 1], gp[i - 1][j]) + score[i][j];
            }
        }
    }

    int max = gp[n][0];

    for (int i = 0; i < n; i++)
    {
        if (max < gp[n][i])
        {
            max = gp[n][i];
        }
    }

    cout << max;
    return 0;
}