#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int cnt=0;
    for(auto n:name){
        if(n=='A') continue;
        if(n<='N'){
            cnt+=(n-'A');
        }else{
            cnt+=('Z'-n+1);
        }
        
    }
    
    int n=name.size();
    int move=n-1;//최대 이동
    
    for(int i=0;i<n;i++){
        int next=i+1;
        while(name[next]=='A'){
            next++;
        }
        
        move=min(move,i*2+n-next); //오른쪽으로 갔다 돌아와서 왼쪽으로
        move=min(move,(n-next)*2+i); //왼쪽으로 갔다 돌아와서 오른쪽으로
        
    }
    
    return move+cnt;
}