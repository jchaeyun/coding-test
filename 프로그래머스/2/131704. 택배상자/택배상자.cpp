#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    //보조컨테이너는 스택 구조
    int n=order.size();
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(i+1);
    }
    stack<int> stk;
    int idx=0;
    int cnt=0;
    int i=0;
    
    while(i<n){
       
       //1.메인에서 바로 싣기
        if(idx<n&&(order[i]==v[idx])){
            cnt++;
            i++;
            idx++;
            
        }
        //2.보조에서 꺼내서 싣기
        else if(!stk.empty()&&(order[i]==stk.top())){
            cnt++;
            stk.pop();
            i++;
        }
        //3.메인->보조로 이동
        else if(idx<n){
            stk.push(v[idx]);
            idx++;   
        }else{
            break;
        }
    }
    return cnt;
}