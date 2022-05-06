class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n=nums.size();
    if(n==0) return 0;
        int i=0,j=1;
//.....  1 1 2 2 2 3 3
//..itr1.... 1 2 2 2 2 3 3
// itr2..... 1 2 3 2 2 3 3

        while(j<n)
        {
            if(nums[i]!=nums[j])
            {   i++;
                nums[i]=nums[j];
            }
            j++;
        }
        
       return i+1; 
        
    }
};