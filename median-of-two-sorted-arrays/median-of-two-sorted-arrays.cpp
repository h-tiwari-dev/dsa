#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Size = static_cast<int>(nums1.size());
        int nums2Size = static_cast<int>(nums2.size());
        vector<int> mergedArr;

        int i = 0, j = 0;

        while (i < nums1Size && j < nums2Size){
            if(nums1[i] < nums2[j]){
                mergedArr.push_back(nums1[i]);
                i++;
            } else {
                mergedArr.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1Size) {
                mergedArr.push_back(nums1[i]);
                i++;
        }
        while (j < nums2Size) {
                mergedArr.push_back(nums2[j]);
                j++;
        }
        bool isEven = (nums1Size + nums2Size) % 2 == 0;
        if(isEven){
            return static_cast<float>(mergedArr[(nums1Size + nums2Size) / 2 - 1] + mergedArr[(nums1Size + nums2Size) / 2]) / 2;
        } else {
            return mergedArr[(nums1Size + nums2Size) / 2];
        }
    }
};

int main(){
    vector<int> nums1 = {};
    vector<int> nums2 = {2};
    Solution * sol = new Solution();

    cout << "Solution is: " <<sol->findMedianSortedArrays(nums1, nums2);

    return 0;
}
