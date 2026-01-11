#include <iostream>
#include <algorithm>

using namespace std;

int tile[1005];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    /*
    2xn 크기의 직사각형ㅇ
    1x2 ,2x1
    1x2 두번 또는 2x1 한번

    끝에 오는 블럭 1x2 2개면 남은 공간 2*(n-2)
    2x1면 남은 공간 2*(n-1)
    tile[1]=1 //2x1 1번
    tile[2]=2 //1x2 2번, 2x1 2번

    */

    tile[1] = 1;
    tile[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        tile[i] = tile[i - 1] + tile[i - 2];
        tile[i] = tile[i] % 10007;
    }

    cout << tile[n];

    return 0;
}