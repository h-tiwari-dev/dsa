#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            vector<vector<int>> maxHeights;

            for(int i = 0; i < matrix.size(); i++){
                vector<int> temp;
                for(int j = 0; j < matrix[i].size(); j++){
                    if(i > 0 && matrix[i][j] != '0'){
                        temp.push_back((matrix[i][j] == '1' ? 1 : 0) + maxHeights[i - 1][j]);
                    } else {
                        temp.push_back(matrix[i][j] == '1' ? 1 : 0);
                    }
                }
                maxHeights.push_back(temp);
            }

            int maxArea = INT_MIN;
            for(auto heightRow: maxHeights){

                stack<pair<int, int>> monoIncArr;
                int start;
                for(int i = 0; i < static_cast<int>(heightRow.size()); i++){
                    start = i;
                    while(!monoIncArr.empty() && monoIncArr.top().second > heightRow[i]){
                        auto top = monoIncArr.top();
                        monoIncArr.pop();
                        maxArea = max(maxArea, top.second * (i - top.first));
                        start = top.first;
                    } 
                    monoIncArr.push({start, heightRow[i]});
                }

                while(!monoIncArr.empty()){
                    auto top = monoIncArr.top();
                    monoIncArr.pop();
                    maxArea = max(maxArea, top.second * (static_cast<int>(heightRow.size()) - top.first));
                }
            }

            return maxArea == INT_MIN ? 0 : maxArea;
        }
};

int main(){
    //vector<vector<char>> test{{'1','1','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector<vector<char>> test{{'1'}};
    Solution * sol = new Solution();
    cout << sol->maximalRectangle(test);
    return 0;
}
