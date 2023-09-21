#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int count = 0; 
       map<int, int> mem;
       mem[0] = 1;
       int sum = 0;

       for(int num : nums){
           sum += num;
           if(mem.find(sum - k) != mem.end()){
               count += mem[sum - k];
           }
           mem[sum] += 1;
       }
       return count;
    }
};

int main(){
    Solution * sol = new Solution();
    vector<int> test = {1, -1, 1, 1, 1, 1, 1};
    cout << "Solution is: " << sol->subarraySum(test, 3);
    return 0;
}
