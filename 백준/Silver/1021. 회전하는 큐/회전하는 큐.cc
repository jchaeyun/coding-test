#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m; // 덱의 크기 n, 뽑아낼 숫자의 개수 m
    deque<int> dq;
    int count = 0;               // 2,3번 연산의 횟수
    for (int k = 1; k <= n; k++) // 덱에 1~n까지 수 넣기
    {
        dq.push_back(k);
    }

    for (int j = 0; j < m; j++) // m개의 숫자를 찾음
    {
        int target; // 뽑아낼 숫자의 위치
        cin >> target;
        int idx = 0;
        for (int u = 0; u < dq.size(); u++)
        {
            if (dq[u] == target)
            {
                idx = u; // 그 숫자가 현재 덱에 위치한 인덱스
                break;
            }
        }
        if (dq.front() == target) // 1번 연산
        {
            dq.pop_front();
        }
        else
        {
            if ((idx > (dq.size() / 2))) // 3번 연산:뽑아낼 숫자의 위치가 뒤에 가까운 경우
            {
                while (dq.front() != target)
                {
                    dq.push_front(dq.back());
                    dq.pop_back();
                    count += 1;
                }
                dq.pop_front(); // 1번 연산
            }
            else if ((idx <= (dq.size() / 2))) // 2번 연산: 뽑아낼 숫자의 위치가 앞에 가까운 경우
            {
                while (dq.front() != target)
                {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    count += 1;
                }
                dq.pop_front(); // 1번 연산
            }
        }
    }

    cout << count;

    return 0;
}
