#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(string s) {
    //map에 넣으면 자동으로 정렬되는데 그게 뭔기준?->key 기준
    //map에 넣고 나중에 vector에 넣고 value 기준으로 내림차순
    
    map<int,int> m;
   
        stringstream ss(s);
        string token;
        
        while(getline(ss,token,',')){ //, 기준으로 잘라서 token에 넣음
            
            string cleaned="";
            
            for(char c:token){
                if(c=='{'||c=='}') continue; //토큰에서 {,} 제거
                cleaned+=c;
            }
            
            int x=stoi(cleaned);
            m[x]++;
        }
        
            
    

    
    
    vector<pair<int,int>> v;
    for(auto p:m){
        v.push_back({p.first,p.second});
    }
    
    sort(v.begin(),v.end(),[](auto &a,auto& b){
            return a.second>b.second;
    });
    
    vector<int> ans;
    for(auto p:v){
        ans.push_back(p.first);
    }
    return ans;
}