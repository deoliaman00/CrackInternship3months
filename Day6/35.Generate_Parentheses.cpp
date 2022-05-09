class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open=n;
        int close=n;
        solve(open,close,"",res);
        return res;
    }
    void solve(int open ,int close,string op,vector<string> &res){
        if(open==0 && close==0){
            res.push_back(op);
            return;
        }
        if(open!=0){
            string op1=op;
            op1+="(";
            solve(open-1,close,op1,res);
        }
        if(close>open){
            string op2=op;
            op2+=")";
            solve(open,close-1,op2,res);
        }
    }
};