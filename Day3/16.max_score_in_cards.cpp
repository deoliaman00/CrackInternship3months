class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {   //  0 1 2 3 4 5 6
        // [1,2,3,4,5,6,1]
        
        int res=0, n=cardPoints.size(), s=0;
        
        // res=0 n= 7 s=0
        for(int i=n-k; i<n;i++) res+=cardPoints[i];
        
        // i=>7-3=>4=>5=>6=>7x.
        
       // res= 5=>11=>12.  res=12
        
        //  i=0   s=12  0<3 0++
        
        for(int i=0, s=res;i<k;i++) 
        {
            s-=cardPoints[n-k+i];  // n-k+i=> 4=>5=>6=>7x
            // cardPoints=> 5=>6=>1
            // s=> 12-5=> 7 => 8-6=> 2 => 4-1=>  3 
            s+=cardPoints[i];
            //i=> 0 => 1 => 2 => 3x
            // s=> 7+1 => 8 => 2+ 2=> 4 => 3+3= > 6
            res=max(res,s); // res=8......(5,6,1).....(6,1,1)......(1,1,2).....(1,2,3)......()
        }
        
        
        
        return res;
        
    }
};