#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    //인덱스를 큐에 넣기 priorities[idx]==priorities[location] 비교해야돼
    //cnt로 실행순서 기록
    //우선순위큐에 넣고 비교. 값이 같으면 큐에서 꺼내고 값이 작으면 큐에서 꺼내 뒤로보냄
    
    priority_queue<int> pq;
    queue<int> q;
    
    for(int i=0;i<priorities.size();i++){
        q.push(i);
    }
    
    for(int p:priorities){
        pq.push(p);
    }
    
    int cnt=0;
    while(!q.empty()&&!pq.empty()){
        int idx=q.front();
        if(pq.top()==priorities[idx]){
            pq.pop();
            q.pop();
            cnt++;
            if(idx==location) return cnt;
        }else{
            q.pop();
            q.push(idx);
        }
    }
    
    return cnt;
    
}