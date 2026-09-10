#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
   //sort로 오름차순 정렬
    //int right,int left
    //int right 하나 태우고 right-- int left 태울수 있으면 태우고 left++
    sort(people.begin(),people.end());
    int right=people.size()-1;
    int left=0;
    int cnt=0;
    
    while(left<=right){
        int sum=0;
        sum+=people[right];
        right--;
       if(sum+people[left]<=limit){
           left++;
       }
        cnt++;
    }
    return cnt;
}