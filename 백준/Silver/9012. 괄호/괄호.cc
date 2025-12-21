#include <iostream>
#include <stack>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        stack<char> stk;
        for (int j = 0; j < s.length(); j++)
        {

            if (s[j] == '(')
            {
                stk.push(s[j]);
            }
            else if (!stk.empty() && stk.top() == '(' && s[j] == ')')
            {
                stk.pop();
            }
            else
            {
                stk.push(s[j]);
            }
        }
        if (stk.empty())
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}