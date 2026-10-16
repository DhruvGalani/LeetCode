class Solution {
public:
    struct Node{
        Node *next[10];
        bool checkKey(char ch){
            if(next[ch-'0']!=NULL)
                return true;
            return false;
        }
        
        void put(char ch,Node* n){
            next[ch-'0'] = n;
        }

        Node* getLink(char ch){
            return next[ch-'0'];
        }
    };

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Construct Trie using arr1

        Node* root = new Node();
        for(int i=0;i<arr1.size();++i){
            auto rightNow = root;
            auto s = to_string(arr1[i]);
            for(auto ch:s){
                if(!rightNow->checkKey(ch)){
                    rightNow->put(ch,new Node());
                }
                rightNow = rightNow->getLink(ch);
            }
        }
        int ans = 0;
        for(int i=0;i<arr2.size();++i){
            auto s = to_string(arr2[i]);
            auto rightNow = root;
            int temp = 0;
            for(auto ch:s){
                if(!rightNow->checkKey(ch))
                    break;
                temp++;
                rightNow = rightNow->getLink(ch);
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};