class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2)
    {
        //time complexity: O(n1 + n2)
        //space complexity: O(1)

        int ans=0;
        int n1=nums1.size();
        int n2=nums2.size();

        //pointer for 'nums1'
        int i=0;
        //pointer for 'nums2'
        int j=0;

        //traversing both arrays
        while((i<n1) && (j<n2))
        {
            //checking valid pair condition
            if((i <= j) && (nums1[i] <= nums2[j]))
            {
                //updating 'maximum' distance
                ans=max(ans,j-i);
                //moving 'j' forward to increase distance
                j++;
            }
            //if invalid but "i<=j", move 'i'
            else if(i <= j)
                i++;
            //otherwise if "i>j", move 'j' to catch up
            else
                j++;
        }
        //returning final answer
        return ans;
    }
};