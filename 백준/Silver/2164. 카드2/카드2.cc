#include <string>
#include <iostream>
#include <deque>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    deque<int> dq;
    // 덱 1~n로 채우기
    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    while (dq.size() > 1)
    {
        dq.pop_front();
        if (dq.size() == 1)
        {
            break;
        }

        // 맨 위에 있는 카드를 빼서 밑으로 옮김
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout << dq.front();

    return 0;
}