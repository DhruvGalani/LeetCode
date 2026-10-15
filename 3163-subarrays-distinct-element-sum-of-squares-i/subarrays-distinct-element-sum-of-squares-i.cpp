#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int total_score = 0;
        
        for (int i = 0; i < n; ++i) {
            bitset<101> seen;
            int distinct = 0;
            for (int j = i; j < n; ++j) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = 1;
                    distinct++;
                }
                total_score += distinct * distinct;
            }
        }
        
        return total_score;
    }
};