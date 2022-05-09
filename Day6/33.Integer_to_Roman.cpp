class Solution 
{
public:
    string intToRoman(int n)
    {
        vector<pair<string,int>>check{{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};
        string ans="";
        
        while(n>0)
        {
            for(auto i:check)
            {
                if(n>=i.second)
                {
                    ans+= i.first;
                    n-=i.second;
                    break;
                }
            }
        }
        
        return ans;
        
    }
};