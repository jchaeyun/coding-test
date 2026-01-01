#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        if (v[i] == 1)
            continue;

        // 소수 여부 flag
        bool is_prime = true;

        // 소수인지 검사하고 어떤 숫자로 나눠지면(소수 아님) 반복문 빠져나감
        for (int j = 2; j * j <= v[i]; j++)
        {
            if (v[i] % j == 0)
            {
                is_prime = false;
                break;
            }
        }

        // 반복문이 끝나고도 깃발이 true이면 소수 개수 +1
        if (is_prime)
        {
            count++;
        }
    }

    cout << count;

    return 0;
}
