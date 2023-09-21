#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(static_cast<int>(s.size()) != static_cast<int>(t.size())){
            return false;
        }
        map<char, int> s_m;
        map<char, int> t_m;

        for(char c: s){
            s_m[c] += 1;
        }
        for(char c: t){
            t_m[c] += 1;
        }
        bool result = true;

        for(pair<char, int> ci: s_m){
            if(ci.second != t_m[ci.first]){
                result = false;
                break;
            }
        }

        return result;
    }
};

int main() {
    Solution * sol = new Solution();
    string val = sol->isAnagram("rat","cat") ? "True" : "False";
    cout << val;
}
