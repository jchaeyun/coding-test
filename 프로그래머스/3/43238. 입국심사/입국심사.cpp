#include <string>
#include <vector>

using namespace std;
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool possible(long long mid,int n,vector<int>& times){
    long long cnt=0;
    for(auto time:times){
        cnt+=(mid/time);//모든 심사관이 mid시간 안에 처리할 수 있는 인원
    }
    return cnt>=n;
}
long long solution(int n, vector<int> times) {
    long long left=0;//최소시간
    sort(times.begin(),times.end());
    long long right=(long long)times[times.size()-1]*n; //최대시간
    long long ans=right;
    while(left<=right){
        long long mid=left+(right-left)/2;
        if(possible(mid,n,times)){//가능하면 더 작은 시간 찾기
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    
    return ans;
}