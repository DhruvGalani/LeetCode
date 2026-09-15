class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size(), cnt = 0, start = 0;   // start = first unconsumed index

        auto isPal = [&](int l, int r) {         // index-based, no substr copy
            while (l < r)
                if (s[l++] != s[r--]) return false;
            return true;
        };

        for (int i = 0; i < n; i++) {            // i = right end of candidate
            if (i - k + 1 >= start && isPal(i - k + 1, i)) {   // length k
                cnt++; start = i + 1; continue;
            }
            if (i - k >= start && isPal(i - k, i)) {           // length k+1
                cnt++; start = i + 1;
            }
        }
        return cnt;
    }
};