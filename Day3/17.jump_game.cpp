class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        //  [2,3,1,1,4]........
        int n=nums.size();
        int reacheable=0;
        for(int i=0;i<n;i++)
        {
            if(reacheable<i) //...0<0..4<2...8<3
            {
                return false;
            }
            reacheable=max(reacheable,i+nums[i]);//....r=4+4
        }
        return true;
        
    }
};