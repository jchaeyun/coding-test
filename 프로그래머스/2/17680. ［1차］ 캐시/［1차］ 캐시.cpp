#include <string>
#include <vector>


using namespace std;

int solution(int cacheSize, vector<string> cities) {
   //배열에 1~cacheSize만큼 번호매김
  //cacheSize만큼 미리 넣어둠
    //for()해서 0인건 패스. 
    //해당 cities 찾으면 time+1,다른것들 번호를 -1씩,맨앞(1)은 0으로 바꿈. 해당 cities에 해당하는것 cacheSize로 바꿈. 
    //못찾으면 time+5,다른것들 번호를 -1씩,맨앞(1)은 0으로 바꿈.해당 cities에 해당하는것 cacheSize,
    
   
    int time=0;
    if(cacheSize==0) return cities.size()*5; //캐시 사이즈 0일때
    vector<string> v;
    for (auto& c : cities){
        for (auto& ch : c) ch = tolower(ch);
    }
    
    for(int i=0;i<cities.size();i++){
        bool hit=false;
        for(int j=0;j<v.size();j++){
          if(v[j]==cities[i]){
              hit=true;
              v.erase(v.begin() + j);
              break;
          }
    }
        if(hit){
             time+=1;
         }else{
             time+=5;
             if(v.size()>=cacheSize) v.erase(v.begin());
             
         }v.push_back(cities[i]); //캐시에 새로 넣기
        
    }
    return time;
    
}