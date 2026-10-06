#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(),targets.end(),[](const vector<int>& a,const vector<int>& b){
        if(a[1]!=b[1]){
            return a[1]<b[1];
        }
        
        return a[0]<b[0];
    });
    int bullet=targets[0][1];
    int cnt=1;
    for(int i=0;i<targets.size();i++){
        if(bullet<=targets[i][0]){
            bullet=targets[i][1];
            cnt++;
        }
    }
    
    return cnt;
}