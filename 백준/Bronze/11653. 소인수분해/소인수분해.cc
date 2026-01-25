#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1은 제외고 2부터 나눠지면 소수가 아닌데...나눠지면 false 표시해야하나
    // 시간 오버되니까 미리 좀 표를 만들어야하나
    // 절반까지만 나눠보기..?
    // 누적...?개수를 저장해야하나 2

    int n;
    cin >> n;
    int res = n;
    int i = 2;

    while (i * i <= res)
    {
        if (res % i == 0)
        {
            cout << i << '\n';
            res = res / i;
        }
        else
        {
            i++;
        }
    }
    if (res > 1)
    {
        cout << res << '\n';
    }

    return 0;
}