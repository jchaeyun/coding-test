#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "push")
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (str == "pop")
        {
            if (s.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                int t = s.top();
                cout << t << '\n';
                s.pop();
            }
        }
        else if (str == "size")
        {
            int te = s.size();
            cout << te << '\n';
        }
        else if (str == "empty")
        {
            if (s.empty())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (str == "top")
        {
            if (s.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << s.top() << '\n';
            }
        }
    }
    return 0;
}