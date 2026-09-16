#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    //커스텀정렬. 먼저 나가는 것 기준으로 정렬
    //거기에 하나 설치하고, 그 다음 꺼 시작지점보다 뒤에있으면 해당 것 건너뛰기
    //앞에있으면 끝지점에 하나 설치(cnt++) 그 다음꺼 시작지점과 비교
    sort(routes.begin(),routes.end(),[](vector<int>& a,vector<int>& b){
        if(a[1]!=b[1]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    });
    
    int cnt=1; //카메라 설치
    int camera=routes[0][1];//처음 지점
    
    for(int i=0;i<routes.size();i++){
        //카메라 설치 지점보다 그다음 시작 지점이 작으면 continue;
        if(camera>=routes[i][0]) continue;
        cnt++;
        camera=routes[i][1];
        
    }
    
    return cnt;
}