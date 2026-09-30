#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int n=queue1.size();
    
    long long sum1=0;
    for(int i=0;i<n;i++){
        sum1+=queue1[i];
    }
    
     long long sum2=0;
    for(int i=0;i<n;i++){
        sum2+=queue2[i];
    }
    if((sum1+sum2)%2==1) return -1;
    long long target=(sum1+sum2)/2;
    
    long long cnt=0;
    long long left=0;
    long long right=n-1;
    
    vector<int> arr;
    for(auto x:queue1){
        arr.push_back(x);
    }
    
     for(auto x:queue2){
        arr.push_back(x);
    }
    
    while(cnt<=3*n){
        if(sum1==target) return cnt;
        
        if(sum1<target){
            right++;
            sum1+=arr[right%(2*n)];
        }else{
            sum1-=arr[left%(2*n)];
            left++;
        }
        
        cnt++;
        
    }
     
         return -1;
    
}