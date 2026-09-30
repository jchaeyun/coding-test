#include <string>
#include <vector>
#include <stack>


using namespace std;

vector<int> solution(vector<int> prices) {
    //비교대상>해당숫자면 비교대상 인덱스-해당인덱스->시간 너무 오래걸림
  
    stack<int> stk;
    
    int n=prices.size();
    vector<int> ans(n);
  
    
    for(int i=0;i<n;i++){
        //현재 가격(i)이 이전가격(idx)보다 떨어진 경우
        while(!stk.empty()&&prices[stk.top()]>prices[i]){
            int idx=stk.top(); //0,1,2,3,4
            stk.pop();
            ans[idx]=i-idx;
        }
        
        //i 기준으로 뒤의 가격 보기
        stk.push(i);
    }
    
    while(!stk.empty()){
        int idx=stk.top(); 
            stk.pop();
            ans[idx]=n-1-idx;
    }
  
    return ans;
    
}