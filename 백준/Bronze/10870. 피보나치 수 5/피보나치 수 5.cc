#include <iostream>

using namespace std;

int fibo(int n)
{
    if (n <= 1)
        return n;
    return fibo(n - 2) + fibo(n - 1);
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << fibo(n);
    return 0;
}