#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();               // 버퍼에 남은 엔터를 비워줘야 getline이 정상 작동함
    for (int i = 0; i < n; i++) // 문자열 n개 받음
    {
        string s;

        int num;
        getline(cin, s); // 공백 포함 문자열 입력 받음(그리고 문자열 안에 \n은 버리고 저장)
        s += '\n';       // 마지막 단어도 출력해야 하므로 끝에 공백 넣음
        stack<char> stk;
        for (int j = 0; j < s.length(); j++)
        {

            if (s[j] == ' ' || s[j] == '\n') // 공백 문자를 만나면
            {
                // 벡터에 넣은 글자들을 뒤에서부터 출력

                while (!stk.empty())
                {
                    cout << stk.top(); // 뒷글자부터 출력
                    stk.pop();         // 스택에서 삭제
                }
                cout << s[j]; // 끝에 공백 문자 출력
            }
            else
            {
                stk.push(s[j]); // 공백 문자 아니면 스택에 저장
            }
        }
    }

    return 0;
}