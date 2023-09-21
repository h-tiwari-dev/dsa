#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(static_cast<int>(nums.size()) == 0){
            return 0;
        }
        int result = 0;
        int counter = 1;
        sort(nums.begin(), nums.end());

        for(int num : nums){
            cout << num << ", ";
        }
        cout << endl;

        for(int i = 0; i < static_cast<int>(nums.size()) - 1; i++){
            if(nums[i] == nums[i+1]) continue;
            if((nums[i+1] - nums[i]) == 1){
                counter++;
                result = max(result, counter);
                continue;
            } 
            counter = 1;
        }
        return max(result, counter);
    }
};


int main(){
    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    Solution * sol = new Solution();

    cout << sol->longestConsecutive(nums);
    return 0;
}
