#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files) {
   //head부분을 다 소문자로 tolower 바꾸기->대소문자 구분안함
   //head가 같다면 number의 숫자 순으로 정렬. 0은 무시됨(012==12)->stoi(number)
   //number도 같다면 원래 순서대로 놔둠
    
    
    struct FileInfo{
        string original;
        string head;
        int number;
        int idx;
    };
    
    
    
    vector<FileInfo> v;
    
    for(int i=0;i<files.size();i++){
        
        string s=files[i];
        
        int start=0;
        while(start<s.size()&&!isdigit(s[start])){
            start++; //s[start]전까지가 head
        }
        
        int end=start;
        while(end<s.size()&&isdigit(s[end])){
            end++; //s[end]전까지가 number
        }
        
        string head=s.substr(0,start);
        int num=stoi(s.substr(start,end-start));
        for(char& c:head){
           c=tolower(c); 
        }
        
        
        v.push_back({s,head,num,i});
   
    }
    sort(v.begin(),v.end(),[](const FileInfo& a,const FileInfo& b){
        if(a.head!=b.head){
            return a.head<b.head;
        }
        
        if(a.number!=b.number){
            return a.number<b.number;
        }
        
        return a.idx<b.idx; //a<b는 안됨 자료형이 FileInfo니까
    }); 
    
    vector<string> ans;
    
    for(auto file:v){
        ans.push_back(file.original);
    }
    
    return ans;
}