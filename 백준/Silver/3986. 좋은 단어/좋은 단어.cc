#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        stack<char> stk;
        for (int j = 0; j < s.length(); j++)
        {
            if (!stk.empty() && s[j] == stk.top())
            {
                stk.pop();
            }
            else // 짝이 안맞거나,스택이 비어있으면 그냥 쌓음
            {
                stk.push(s[j]);
            }
        }

        if (stk.empty())
        { // 좋은 단어일 경우(스택이 비어있음)
            count++;
        }
    }
    cout << count;
    return 0;
}