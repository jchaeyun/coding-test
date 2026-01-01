#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> m >> n;

    // 1.배열을 만들고 모두 소수라 가정. 0과1은 소수가 아니므로 false
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    // 2.에라토스테네스의 체 가동
    // 제곱근까지만 돌면 됨
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            // i의 배수들을 모두 지워버림(2배수부터 시작)
            for (int j = i * 2; j < n + 1; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int k = m; k < isPrime.size(); k++)
    {
        if (isPrime[k])
            cout << k << '\n';
    }

    return 0;
}