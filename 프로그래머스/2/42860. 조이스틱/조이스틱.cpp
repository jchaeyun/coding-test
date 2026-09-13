#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
   //세로방향 이동부터 기록
    int cnt=0;
    int n=name.size();
    for(int i=0;i<n;i++){
        if(name[i]<'N'){
            cnt+=(name[i]-'A');
        }else{
            cnt+=('Z'-name[i]+1);
        } 
    }
    
    //가로방향 이동->A인경우가 문제.
    //오른쪽으로 가는거VS왔던길 되돌아간다음 마지막-타겟만큼이동
    
    int move=n-1;
    
    for(int i=0;i<n;i++){
        int next=i+1;
        while(next<n&&name[next]=='A') next++;
        move=min(move,i*2+(n-next)); //오른쪽으로 먼저 갔다가 돌아가서 왼쪽으로
        move=min(move,(n-next)*2+i); //왼쪽으로 먼저 갔다가 돌아와서 오른쪽으로
    }
    
    return move+cnt;
    
}


