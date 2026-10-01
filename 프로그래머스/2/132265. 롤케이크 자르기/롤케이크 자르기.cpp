#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    map<int,int> right;
    map<int,int> left;
    for(int i=1;i<topping.size();i++){
        right[topping[i]]++;
    }
    
    int idx=0; //0-idx / idx+1~끝
    left[topping[idx]]++;
    int cnt=0;
    
    
    while(idx<topping.size()){
        
        if(left.size()==right.size()){
            cnt++;
        }
        
        idx++;
        if(idx==topping.size()){
            break;
        }
        right[topping[idx]]--;
        if(right[topping[idx]]==0){
            right.erase(topping[idx]);
        }
        
        
        
        left[topping[idx]]++;
        
        
        
    }
    
    return cnt;
}