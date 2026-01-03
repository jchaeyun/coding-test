#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 가지고 있는 랜선 개수 k
    // 같은 길이로 잘라서 만들고 싶은 n개의 랜선
    int k, n;
    cin >> k >> n;

    vector<long long> rope(k);

    for (int j = 0; j < k; j++)
    {
        cin >> rope[j];
    }

    sort(rope.begin(), rope.end());

    long long start = 1;
    long long end = rope.back();
    long long result = 0;

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long sum = 0; // 만든 로프 총 개수
        long long num = 0; // 각 로프로 만든 개수

        for (int i = 0; i < k; i++)
        {
            num = rope[i] / mid;
            sum += num;
        }

        // n개보다 더 만들었으면 자르는 길이를 늘려봄
        if (sum >= n)
        {
            result = mid;    // 정답 후보에 넣음
            start = mid + 1; // 더 길게 잘라도 되나?(이분탐색 응용)
        } // n개보다 덜만들었으면 자르는 길이를 줄여봄
        else // 목표보다 부족함
        {
            end = mid - 1; // 자르는 길이를 줄인다
        }
    }
    cout << result;

    return 0;
}