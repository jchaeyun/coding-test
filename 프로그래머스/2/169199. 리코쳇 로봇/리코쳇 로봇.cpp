#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<string> board) {
    //bfs,방문표시는 벽만나서 멈춘 최종위치만. 그 위치를 큐에 넣음
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    
    vector<vector<bool>> visited(
        board.size(),
        vector<bool>(board[0].size(),false)
    );
    
    queue<pair<int,int>> q;
    vector<vector<int>> dist(
        board.size(),
        vector<int>(board[0].size(),0)
    );
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='R'){
                q.push({i,j});
                visited[i][j]=true;
            }
        }
    }
    
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
    
        for(int i=0;i<4;i++){
            int r=row+dr[i];
            int c=col+dc[i];
            while(r>=0&&c>=0&&r<board.size()&&c<board[0].size()
                  &&board[r][c]!='D'){
                r+=dr[i];
                c+=dc[i];
            }
            r-=dr[i];
            c-=dc[i];
            if(board[r][c]=='G') return dist[row][col]+1;
            if(!visited[r][c]){
                visited[r][c]=true;
                
                dist[r][c]=dist[row][col]+1;
            q.push({r,c});
            }
            
           
        }
    }
    
    return -1;
}