#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{   int tA=(a+1)/2;
    int tB=(b+1)/2;
    int rnd=1;
    while(tA!=tB){
        tA=(tA+1)/2;
        tB=(tB+1)/2;
        rnd++;
        if(tA==tB){
            break;
        }
    }
   
    return rnd;
}