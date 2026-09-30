#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    //일단 순회를 하고, 스택에서 꺼낸 숫자보다 작거나같으면 인덱스를 스택에 넣기.
    //크면 스택에서 꺼내고 ans배열에 넣기. while문
    int n=numbers.size();
    vector<int> ans(n,-1);
    stack<int> stk;
  
    
    for(int i=0;i<n;i++){
        while(!stk.empty()&&numbers[stk.top()]<numbers[i]){
            int idx=stk.top();
            ans[idx]=numbers[i];
            stk.pop();
        }
        
        stk.push(i);
    }
    
    return ans;
}