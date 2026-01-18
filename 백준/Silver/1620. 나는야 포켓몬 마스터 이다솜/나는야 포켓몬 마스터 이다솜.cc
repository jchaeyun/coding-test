#include <iostream>
#include <vector>
#include <string>
#include <map>    //map 필수! map<key,value> key는 검색할 단어, value는 검색 결과->앞에 넣은 걸로 뒤에 걸 찾음
#include <cctype> //isdigit 함수

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> pokimon;    // 번호->이름찾는 용도
    map<string, int> name_map; // 이름->번호 찾는 용도

    // 인덱스 계산 편하려고 0번에 쓰레기값넣음
    pokimon.push_back("DUMMY");

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        pokimon.push_back(s);
        name_map.insert({s, i});
    }

    for (int j = 0; j < m; j++)
    {
        string str;
        cin >> str;
        // 숫자인지 확인
        if (isdigit(str[0]))
        {
            int num = stoi(str);
            cout << pokimon[num] << '\n';
        }
        else
        {
            cout << name_map[str] << '\n';
        }

        
    }

    return 0;
}