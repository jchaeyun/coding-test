#include <string>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

int solution(vector<vector<int>> routes) {
    //나간지점 순으로 정렬 후 똑같으면 더 빨리 들어온 순으로
    //맨처음의 나간지점에 카메라 설치.(스택?)
    //들어온지점이 스택 top에 있는 것보다 작으면 패스
    //스택 top에 있는것보다 크면, 해당 차량 나간 지점을 스택에 넣기
    
    sort(routes.begin(),routes.end(),[](const vector<int>& a,const vector<int>& b){
        if(a[1]!=b[1]){
            return a[1]<b[1];
        }
        
        return a[0]<b[0];
    });
    stack<int> stk;
    stk.push(routes[0][1]);
    for(int i=0;i<routes.size();i++){
        if(!stk.empty()){
            if(stk.top()>=routes[i][0]){
                continue;
            }else{
                stk.push(routes[i][1]);
            }
        }
        
    }
    
    return (int)stk.size();
    
}