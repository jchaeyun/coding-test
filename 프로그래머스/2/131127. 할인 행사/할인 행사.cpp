#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    
    //end가 마지막날일때까지 반복
    //map을 사용해서 처음 10개 품목의 이름,개수 저장
    //m[want[i]]==number[i]가 아니면 m 조정
    //맞으면 start를 기록해두고 m을 한칸 이동.
    
    int start=0;
    int end=start+9;
    int n=discount.size();
    map<string,int> m;
    //초기화
    for(int i=0;i<10;i++){
        m[discount[i]]++;
    }
    
    int cnt=0;
    while(end<n){
        bool possible = true;
        
        for(int i=0;i<want.size();i++){
            if(m[want[i]]!=number[i]){
                possible = false;
                break;
            }
            
        }
        
        if(possible) cnt++;
        
        m[discount[start]]--;
        start++;
        end++;
        if(end<n) m[discount[end]]++;
        
        
        
    }
    
    
    return cnt;
    
    
}