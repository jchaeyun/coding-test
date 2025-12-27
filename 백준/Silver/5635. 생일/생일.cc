#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Birth
{
    string name;
    int year;
    int month;
    int day;
};

// 생일 빠른 순대로 정렬
bool compare(const Birth &a, const Birth &b)
{
    if (a.year != b.year)
        return a.year < b.year;
    if (a.month != b.month)
        return a.month < b.month;
    if (a.day != b.day)
        return a.day < b.day;

    return false; // 모든게 다 같을 때는 입력한 순서대로 놔둬라
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Birth> v;

    for (int i = 0; i < n; i++)
    {
        string name;
        int day, month, year;
        cin >> name >> day >> month >> year;

        v.push_back({name, year, month, day});
    }

    sort(v.begin(), v.end(), compare);

    int back = v.size() - 1;
    cout << v[back].name << '\n'
         << v[0].name;

    // v.back().name 이렇게 해도 됨
    return 0;
}