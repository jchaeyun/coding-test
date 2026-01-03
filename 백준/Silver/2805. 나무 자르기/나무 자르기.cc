#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // n:나무의 수 m:가져가려는 나무의 길이
    long long n, m;
    cin >> n >> m;

    vector<long long> tree(n);
    for (int i = 0; i < n; i++) // i 초기화 빼먹지 마라!!!
    {
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end());

    long long start = 1;
    long long end = tree.back();
    long long result = 0;

    while (start <= end)
    {
        long long height = (start + end) / 2;
        long long sum = 0;

        for (int j = 0; j < n; j++)
        {

            // 절단기 길이 설정보다 tree가 더 짧다면 자른 게 없음
            if (height > tree[j])
            {
                continue;
            } // 절단기 길이 설정보다 tree가 길거나 같다면
            else
            {
                sum += tree[j] - height;
            }
        }

        // 목표 길이 이상으로 나무를 자름
        if (sum >= m)
        {
            result = height;    // 일단 최대 높이로 저장
            start = height + 1; // 절단기 설정 높이를 높여볼까
        }
        else // 목표 길이에 도달 못함
        {
            end = height - 1; // 절단기 설정 높이를 낮춰볼까
        }
    }
    cout << result;

    return 0;
}