#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int n=numbers.size();
    stack<int> stk;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        while(!stk.empty()&&(numbers[stk.top()]<numbers[i])){
                v[stk.top()]=numbers[i];
                stk.pop();
        }
        stk.push(i);
    }
    
    while(!stk.empty()){
        int idx=stk.top();
        v[idx]=-1;
        stk.pop();
    }
    
    return v;
}