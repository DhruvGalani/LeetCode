class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        vector<int> Map(n+1, 0);
        int count = 0;
        for (int i = 0; i < n; i++){
            Map[A[i]]++;
            if (Map[A[i]] == 2) count++;
            Map[B[i]]++;
            if (Map[B[i]] == 2) count++;
            ans[i] = count;
        }
        return ans;
    }
};