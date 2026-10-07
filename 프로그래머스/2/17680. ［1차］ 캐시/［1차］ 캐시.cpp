#include <string>
#include <vector>
#include <deque>
#include <cctype>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    //cities의 인덱스를 cache배열(큐)에 저장. [0,3,4] 이렇게?
    //매번 캐시를 순회? 
    //캐시 순회하면서 해당 city 있으면 그 city의 인덱스를 새로 push,맨 앞은 pop
    deque<int> q;
    int time=0; //cachehit은 1,miss는 5
    for(int i=0;i<cities.size();i++){
               transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower); 
    }
   
    for(int i=0;i<cities.size();i++){ 
        bool ishit=false;
        if(!q.empty()){
            for(int j=0;j<q.size();j++){
                if(cities[q[j]]==cities[i]){
                    ishit=true; //hit
                    q.erase(q.begin()+j);
                    break;
                } 
            }    
        }
        q.push_back(i);//miss든 hit이든 최근꺼로 업뎃하고,캐시가 다 찼다면 맨 앞을 빼야함(LRU)
        
        if(ishit){
            time+=1;
    
        }else{
            time+=5;
            if(q.size()>cacheSize){
                q.pop_front();
            } 
        }
    }
    
    return time;
}