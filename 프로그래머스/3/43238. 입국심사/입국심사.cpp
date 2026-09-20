#include <string>
#include <vector>

using namespace std;
bool possible(long long time,vector<int>& times,int n){
    long long sum=0;
    for(int i=0;i<times.size();i++){
        sum+=(time/times[i]); //각 심사관 당 해당 시간안에 심사하는 인원수
        if(sum>=n) return true;
    }
    return false;
}

long long solution(int n, vector<int> times) {
    long long left=1;
    long long num=times.size()-1;
    long long right=(long long)n*(times[num]);//최대시간
    long long ans;
    
    while(left<=right){
        long long mid=left+(right-left)/2; //총 시간
        if(possible(mid,times,n)){
            ans=mid;
            right=mid-1;;
        }else{
            left=mid+1;
        }
    }
    
    return ans;
}