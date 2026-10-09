#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    //큐에서 하나 꺼내고 상하좌우 순회.->sum 누적합
    //큐가 비었으면 sum을 벡터 배열에 저장
   
    vector<vector<bool>> visited(maps.size(),vector<bool>(maps[0].size(),false));
    vector<int> ans;
    
    int dc[4]={-1,1,0,0};
    int dr[4]={0,0,1,-1};
    
    queue<pair<int,int>> q;

  
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++){
            //X 아닌 칸 만나면 bfs 시작
         if(maps[i][j]!='X'&&!visited[i][j]){
            visited[i][j]=true;
            q.push({i,j});
            int sum=0; //뭉탱이 더하기 시작
        
                while(!q.empty()){
                    auto cur=q.front();
                    q.pop();
                    int r=cur.first;
                    int c=cur.second;
                    
                    sum+=maps[r][c]-'0';

                    for(int k=0;k<4;k++){
                        int row=r+dr[k];
                        int col=c+dc[k];
                        if(row>=maps.size()||row<0) continue;
                        if(col>=maps[0].size()||col<0) continue;
                        if(!visited[row][col]&&maps[row][col]!='X'){
                            visited[row][col]=true;
                            q.push({row,col});   
                        }
                    }
                }
                
                ans.push_back(sum);
            }
        } 
    }
    if(ans.size()==0){
        ans.push_back(-1);
    }
    sort(ans.begin(),ans.end());
    
    return ans;
}