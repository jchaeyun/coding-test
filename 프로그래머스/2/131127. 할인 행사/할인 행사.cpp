#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    //사야하는 것들 총 개수는 열개
    //총 날짜는 10<= <=100,000
    //int left,right으로 map에 넣고 그게  map[want[i]]==number[i]인지 체크
    //아니면 map[left]--,left++,right++하고 map[right]++
    int left=0;
    int right=9;
    int cnt=0;
    map<string,int> m;
    bool ok=false;
    //초기값
    for(int i=0;i<10;i++){
        m[discount[i]]++;
    }
    while(right<discount.size()){
      bool ok=true;
        
       for(int i=0;i<want.size();i++){
           if(m[want[i]]!=number[i]){
             ok=false;
             break;    
           } 
       }
        
        //다 일치하면 
        //cnt++하고 한칸씩 이동
        if(ok){
             cnt++;
        }
        
        m[discount[left]]--;
        left++;
        if((right+1)==discount.size()) break;
        right++;        
        m[discount[right]]++;
    }
    
    return cnt;
}