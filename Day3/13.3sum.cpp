class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
     vector<vector<int>> ans;
        int n=nums.size();
        int i,j,k,sum;
        for(i=0;i<n-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                
            j=i+1,k=n-1,sum=0-nums[i];
             while(j<k){
                 if(nums[j]+nums[k]==sum)
                 {
                     vector<int> a1;
                     a1.push_back(nums[i]);
                      a1.push_back(nums[j]);
                      a1.push_back(nums[k]);
                     ans.push_back(a1);
                     
                     while(j<k && nums[j]==nums[j+1]) j++;
                     while(j<k && nums[k]==nums[k-1]) k--;
                     
                     j++;
                     k--;
                 
                 }
                 else if(nums[j]+nums[k]<sum) j++;
                 else
                     k--;
                 
             }
                
            }
            
        }
         return ans;
            
    }
};