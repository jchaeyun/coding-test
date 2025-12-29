#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    int result = 0;
    int temp = 0;
    bool has_minus = false; // 마이너스 등장하면 뒤에 나오는 건 바로 빼는 모드로

    // 마지막 숫자 처리를 위해 i<=s.length()
    // 문자열 끝에는 '\0'이 들어있다
    for (int i = 0; i <= s.length(); i++)
    {
        // 연산자이거나 문자열의 끝이면 지금까지 만든 숫자를 처리
        if (s[i] == '+' || s[i] == '-' || i == s.length())
        {
            if (has_minus)
            {
                // 마이너스가 한번이라도 나왔다면 그 뒤는 빼기만
                result -= temp;
            }
            else
            {
                // 아직 마이너스 안나왔으면 더함

                result += temp;
            }
            temp = 0; // 숫자 초기화

            // 이번에 만난 연산자가 마이너스라면 플래그를 켬.
            // 이후에 만나는 모든 숫자는 위 로직에 의해 뺄셈 처리됨
            if (s[i] == '-')
            {
                has_minus = true;
            }
        }
        else
        {
            temp = temp * 10 + (s[i] - '0');
        }
    }

    cout << result;

    return 0;
}