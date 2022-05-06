class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        
        map<int,int>ans;
        int n=nums.size();
        int aa=0,sum=0;
        ans[0]=1;
        //0->1
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
           // 
            
            if(ans.find(sum-k)!=ans.end())
            {
                aa+=ans[sum-k];
                cout<<aa<<" ";
            }
            ans[sum]++;     
        }
         return aa;
        
    }
};