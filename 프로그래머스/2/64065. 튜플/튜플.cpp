#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(string s) {
  //걍 set쓰면 되나? 아니 맵써도 되긴할듯 s.insert() 이거 맞나 문법?
    //for(auto [n,num]:m) 해서 n만 벡터에 집어넣기
   
    for(auto& c:s){
        if(!isdigit(c)) c=' ';
    }
    
    stringstream ss(s);
    string tok;
    map<int,int> m;
    while(ss>>tok) m[stoi(tok)]++; //공백 단위로 끊어서 map에 저장
    
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),[](const pair<int,int>& a,const pair<int,int>& b){
        return a.second>b.second; //개수 많은 순대로 나열
    });
    
    
    vector<int> ans;
    for(auto& [n,num]:v){
        ans.push_back(n);
    }
    
    return ans;
}