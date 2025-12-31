#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 도시 개수
    int n;
    cin >> n;

    // 거리
    vector<long long> v(n - 1);

    for (int i = 0; i < n - 1; i++)
    {

        cin >> v[i];
    }

    // 기름값
    vector<long long> oil;

    // 마지막 기름값은 안 넣음. 어차피 안 쓰니까
    for (int j = 0; j < n - 1; j++)
    {
        long long price;
        cin >> price;
        oil.push_back(price);
    }
    // 마지막 도시의 기름값
    long long end;
    cin >> end;

    // 총 금액
    long long total = 0;
    long long min_price = oil[0]; // 초기화를 0으로 하면 안된다!!!

    for (int k = 0; k < n - 1; k++)
    {

        // 지금까지 중의 기름 최저가로
        if (oil[k] < min_price)
        {
            min_price = oil[k];
        }

        // 다음 도시 갈 수 있을 만큼만 주유
        total = total + min_price * v[k];
    }

    cout << total;

    return 0;
}