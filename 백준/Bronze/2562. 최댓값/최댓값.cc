#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;

    for (int i = 0; i < 9; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    vector<int> v_backup = v;

    sort(v.begin(), v.end());

    int max = v.back();
    cout << max << '\n';
    for (int j = 0; j < 9; j++)
    {
        if (v_backup[j] == max)
        {
            cout << j + 1;
        }
    }
}