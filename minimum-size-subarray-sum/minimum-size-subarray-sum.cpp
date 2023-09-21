#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int sum = 0, ans = INT_MAX, left = 0;
            for (int i = 0; i < static_cast<int>(nums.size()); i++) {
                sum += nums[i];
                while(sum >= target){
                    ans = min(ans, i + 1 - left);
                    sum -= nums[left++];
                }
            }

            return ans == INT_MAX ? 0 : ans;
        }
};

int main(){
    Solution * sol = new Solution();
    vector<int> test = {2,3,1,2,4,3};

    cout << "Solution is: " << sol->minSubArrayLen(7, test);
    return 0;
}
