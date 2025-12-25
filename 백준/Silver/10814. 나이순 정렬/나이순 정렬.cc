#include <iostream>
#include <algorithm> //stable_sort를 쓰기 위함
#include <string>
#include <vector>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first; // 이름은 고려하지 않고 있던대로 냅둠
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    pair<int, string> p;
    vector<pair<int, string>> v;

    for (int i = 0; i < n; i++)
    {
        int age;
        string name;
        cin >> age >> name;

        p = {age, name}; // pair에 값 이렇게 넣음!!
        v.push_back(p);
    }

    stable_sort(v.begin(), v.end(), compare);
    for (int j = 0; j < v.size(); j++)
    {
        cout << v[j].first << ' ' << v[j].second << '\n';
    }
    return 0;
}