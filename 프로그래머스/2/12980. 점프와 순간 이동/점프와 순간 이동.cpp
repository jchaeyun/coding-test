#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{  
    long long jump=0;
    while(n>0){
        if(n%2==0){
            n/=2;
        } 
        else{
            n-=1;
                jump++;
        }
    }
    return jump;
}