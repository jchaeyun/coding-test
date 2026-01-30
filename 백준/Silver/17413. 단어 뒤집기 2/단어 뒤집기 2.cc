#include <iostream>
#include <string>
#include <stack>

using namespace std;

//입력 끝에 왔거나, 태그 안이 아니면서 공백을 만났으면
//스택에 있는거 다 출력
//입력 끝이 아니면 공백도 출력

//< 만나면 스택에 있던거 다 출력하고 is_tag=true 설정하고 <출력
//>만나면 is_tag=false 설정하고 > 출력

//그 외(그냥 문자)일땐
//is_tag=true이면 그냥 출력
//is_tag=false이면 스택에 넣기

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s); // 공백 포함 입력

    stack<char> stk;
    bool is_tag = false;

    for (int i = 0; i <= s.length(); i++)
    {

        // 문자열이 끝났거나 공백을 만났을때(태그 밖일 때)
        if (i == s.length() || (!is_tag && s[i] == ' '))
        {
            while (!stk.empty())
            {
                cout << stk.top();
                stk.pop();
            }

            if (i < s.length())
            {
                cout << ' ';
            }
        }
        // tag일 경우
        else if (s[i] == '<')
        {
            // 태그 전까지 쌓인 글자 출력
            while (!stk.empty())
            {
                cout << stk.top();
                stk.pop();
            }

            is_tag = true;
            cout << s[i];
        }
        else if (s[i] == '>')
        {
            is_tag = false;
            cout << s[i];
        }
        else
        {
            if (!is_tag)
            {
                stk.push(s[i]);
            }
            else
            {
                cout << s[i];
            }
        }
    }

    return 0;
}