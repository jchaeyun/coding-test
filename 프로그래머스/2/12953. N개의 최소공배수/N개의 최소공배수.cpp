#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> arr) {
    //약수를 찾아서...2/2,3/2,2,2/2,7 ->제일 개수가 많은것들 기준으로 기록 2,2,2,3,7
    //맵 두개 이상. 하나는 약수 기록용 하나는 제일 많은 개수 기록용
    
    map<int,int> sum;
    int ans=1;
    
    for(int i=0;i<arr.size();i++){
        //약수 찾아서 넣기
       
        for(int j=2;j<=arr[i];j++){
            int cnt=0;
            while(arr[i]%j==0){
                cnt++;
                sum[j]=max(sum[j],cnt);
                arr[i]/=j;
            }
        }
        if(arr[i]>1){
            sum[arr[i]]=max(sum[arr[i]],1);
        }
        
    }
    
    for(auto [i,v]:sum){
        for(int j=0;j<v;j++){
            ans*=i;
        }
    }
    
    return ans;
}