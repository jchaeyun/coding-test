#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    //스택 
    //꺼내서 같으면 pop
    //마지막에 비어있으면 return 1 아니면 return 0
    stack<char> stk;
    stk.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(!stk.empty()){
            if(stk.top()==s[i]){
                stk.pop();
                continue;
            }else{
               stk.push(s[i]); 
            }
        }else{
            stk.push(s[i]);
        }
        
       
        
    }
    if(stk.empty()){
        return 1;
    }else{
        return 0;
    }
     
    
}