#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> seen;
    for (int i = 0; i < n; i++)
    {
        string see;
        cin >> see;
        seen.push_back(see);
    }
    sort(seen.begin(), seen.end());

    vector<string> match;

    vector<string> heard;
    for (int i = 0; i < m; i++)
    {
        string hear;
        cin >> hear;
        if (binary_search(seen.begin(), seen.end(), hear))
        {
            match.push_back(hear);
        }
    }

    sort(match.begin(), match.end());

    cout << match.size() << '\n';

    for (int i = 0; i < match.size(); i++)
    {
        cout << match[i] << '\n';
    }

    return 0;
}