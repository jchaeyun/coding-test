#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> rope;
    for (int i = 0; i < n; i++)
    {
        int length;
        cin >> length;
        rope.push_back(length);
    }

    // 작은 순대로 정렬
    sort(rope.begin(), rope.end());

    // 긴 로프부터 비교 시작.  결과값은 습관적으로 long long을 쓰자!
    long long temp = 0;
    for (int j = rope.size() - 1; j >= 0; j--)
    {
        if (temp <= rope[j] * (rope.size() - j))
        {
            temp = rope[j] * (rope.size() - j);
        }
    }

    cout << temp;

    return 0;
}