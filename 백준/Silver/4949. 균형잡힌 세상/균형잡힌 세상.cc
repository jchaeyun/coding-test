#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {

        string s;
        stack<char> stk; // 각 문자열마다 stack 하나씩만
        getline(cin, s); // 공백 포함 한 줄 입력 받음

        if (s == ".")
        {
            break;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            else if (!stk.empty() && stk.top() == '[' && s[i] == ']')
            {
                stk.pop();
            }
            else if (!stk.empty() && stk.top() == '(' && s[i] == ')')
            {
                stk.pop();
            }
            else if (s[i] == ')' || s[i] == ']')
            {
                stk.push(s[i]);
            }
        }

        if (stk.empty())
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }

    return 0;
}