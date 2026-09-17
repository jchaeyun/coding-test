#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    //합이 k보다 작으면 right++;
    //합이 k보다 크면 left++
    //합이 k면 기록하고 return
    int left=0;
    int right=0;
    int sum=sequence[left];
    int ansL=left;
    int ansR=sequence.size()-1;
    while(left<=right&&right<sequence.size()){
        
        if(sum>k){
            sum-=sequence[left];
            left++;
        }else if(sum<k){
            right++;
            sum+=sequence[right];
        }else{
            //길이가 더 짧은 경우
            if((right-left)<(ansR-ansL)){
                ansL=left;
                ansR=right;
            }
            sum-=sequence[left];
            left++;
            
        }
    }
    return {ansL,ansR};
}