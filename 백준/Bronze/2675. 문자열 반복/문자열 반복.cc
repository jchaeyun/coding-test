#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    int T, R;

    string P;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> R;
        cin >> S;
        vector<char> word;
        for (int j = 0; j < S.length(); j++)
        {
            for (int k = 0; k < R; k++)
            {
                word.push_back(S[j]);
            }
        }
        for (int m = 0; m < word.size(); m++)
        {
            cout << word[m];
        }

        cout << '\n';
    }

    return 0;
}