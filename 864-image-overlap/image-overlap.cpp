static int freq[4000];
static int ones1[900], ones2[900];
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int n = img1.size();
        int sz1 = 0, sz2 = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(img1[i][j]) ones1[sz1++] = (i << 6) | j;
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(img2[i][j]) ones2[sz2++] = (i << 6) | j;
            }
        }
        memset(freq , 0 , sizeof(freq));
        int res = 0;
        for(int i = 0; i < sz1; ++i){
            const int pos1 = ones1[i];
            for(int j = 0; j < sz2; ++j){
                const int pos2 = ones2[j];
                res = max(res , ++freq[pos2 - pos1 + 2000]);
            }
        }
        return res;
    }
};