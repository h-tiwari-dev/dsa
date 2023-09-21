#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;
        int result;
        int size = static_cast<int>(nums.size());

        for(int num: nums){
            freq[num]++;
            if(freq[num] > size/2){
                result = num;
            }
        }
        return result;
    }
};

int main(){
    vector<int> test = {3,2,3};
    Solution * sol = new Solution();

    cout << sol->majorityElement(test);

    return 0;
}
