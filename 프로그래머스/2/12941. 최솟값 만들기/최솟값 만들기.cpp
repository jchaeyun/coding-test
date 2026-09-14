#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    //작은거랑 큰거랑 곱하면 되는거아닌가
    //정렬해서 곱하면되겟구만
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<>());//반대로
    
    //124 544
    int sum=0;
    for(int i=0;i<A.size();i++){
        sum+=(A[i]*B[i]);
    }
    
    return sum;
    
}