#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string,string> m; // 아이디,최종 닉네임
    vector<string> v;
    vector<pair<string,string>> log; //아이디,행동
    //파싱이 문제다
    //enter:m[아이디]=닉네임
    //change=m[아이디]=닉네임
    //leave 그냥냅둠
    for(string& r:record){
        stringstream ss(r);
        string cmd,uid,nick;
        ss>>cmd>>uid>>nick;
        if(cmd=="Enter"){
            m[uid]=nick;
            log.push_back({uid,cmd});
        }else if(cmd=="Change"){
             m[uid]=nick;
        }else{
            log.push_back({uid,cmd});
        }
        
    }
    
    for(auto& [id,act]:log){
        if(act=="Enter"){
            v.push_back(m[id]+"님이 들어왔습니다.");
        }else{
            v.push_back(m[id]+"님이 나갔습니다.");
        }
        
    }
    
    
    
    
    
    //map을 vector에 담아서 반환
    return v;
}