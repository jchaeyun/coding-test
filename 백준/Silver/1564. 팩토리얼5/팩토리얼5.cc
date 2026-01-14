#include <iostream>
#include <algorithm>
#include <string> //to_string 위해

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    // 오버플로우 방지를 위한 모듈러(넉넉하게 10^12)
    // 5자리만 남기면 계산 도중 오차가 생길 수 있어서 넉넉히 잡음
    long long mod = 1000000000000;

    long long answer = 1;
    for (int i = 1; i <= num; i++)
    {
        answer *= i;

        // 끝에 붙은 0 때기
        while (answer % 10 == 0)
        {
            answer /= 10;
        }

        // 숫자 너무 커지면 앞부분 자르기
        answer %= mod;
    }

    // 마지막 5자리 출력
    answer %= 100000; // 최종적으로 5자리만 남김

    cout.width(5);  // 5칸 확보
    cout.fill('0'); // 빈칸은 0으로 채움
    cout << answer;

    return 0;
}