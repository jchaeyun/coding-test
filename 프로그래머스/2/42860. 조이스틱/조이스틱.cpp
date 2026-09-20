#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    //세로
    int cnt=0;
    for(char& c:name){
        if(c=='A') continue;
        if(c>'A'&&c<='N') {
            cnt+=(c-'A');
        }else{
            cnt+=('Z'-c+1);
        }
        
    }
    
    //가로
    //1.기본값:왼쪽으로 쭉가기
    //2.왼쪽으로 i만큼 갔다가 돌아가서 오른쪽으로
    //3.오른쪽으로 갔다가 돌아가서 왼쪽으로
    int move=name.size()-1;
    int n=name.size();
    for(int i=0;i<n;i++){
        int next=i+1;
        while(next<n&&name[next]=='A'){
            next++;
        } 
        
            move=min(move,i*2+n-next);
            move=min(move,(n-next)*2+i);
        
    }
    
    return move+cnt;
}