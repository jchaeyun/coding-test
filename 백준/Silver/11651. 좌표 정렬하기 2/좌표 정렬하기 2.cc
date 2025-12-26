#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> v;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    for (int j = 0; j < v.size(); j++)
    {
        cout << v[j].second << ' ' << v[j].first << '\n';
    }

    return 0;
}