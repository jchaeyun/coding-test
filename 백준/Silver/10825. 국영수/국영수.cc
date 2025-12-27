#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Data
{
    string name;
    int kor;
    int eng;
    int math;
};

bool compare(const Data &a, const Data &b)
{
    if (a.kor != b.kor)
        return a.kor > b.kor;

    if (a.eng != b.eng)
        return a.eng < b.eng;

    if (a.math != b.math)
        return a.math > b.math;

    return a.name < b.name;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Data> v;

    for (int i = 0; i < n; i++)
    {

        int kor, eng, math;
        string name;
        cin >> name >> kor >> eng >> math;

        v.push_back({name, kor, eng, math});
    }

    sort(v.begin(), v.end(), compare);

    for (int j = 0; j < v.size(); j++)
    {
        cout << v[j].name << '\n';
    }
    return 0;
}