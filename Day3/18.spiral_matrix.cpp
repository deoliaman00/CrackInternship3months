class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        /*
        
         1  2 3  4
         5  6 7  8
         9 10 11 12
        
        */
        vector<int> sol;
        int i;
        int low=0,top=0,right=matrix[0].size()-1,below=matrix.size()-1;
        // low=0--top=0--right=4----below=3
        while(low<=right && top<=below)
        {
            
            for(i=low;i<=right;i++)
            {
                sol.push_back(matrix[top][i]);
            }
            top++;
            if(top>below) break;
            // 1->2->3->4 printed
            
            for(i=top;i<=below;i++)
            {
                sol.push_back(matrix[i][right]);
            }    
            right--;
            if(low>right) break;
            
            // 1->2->3->4--->8->12->
            
            for(i=right;i>=low;i--)
            {
                sol.push_back(matrix[below][i]);
            }
            below--;
            
            // 1->2->3->4---->8->12---->11->10->9----
            for(i=below;i>=top;i--)
            {
                sol.push_back(matrix[i][low]);
            }
            low++;
        }
        return sol;
              
        
    }
};