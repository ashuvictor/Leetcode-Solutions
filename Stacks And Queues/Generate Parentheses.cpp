

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

class Solution {
public:
    void solve(int open,int close,int n,string temp,vector<string>&ans){
     if(temp.size()==2*n){
         ans.push_back(temp);
         return;
     }
        if(open<n)
        {
            temp.push_back('(');
            solve(open+1,close,n,temp,ans);
            temp.pop_back();
        }
        if(close<open)
        {
            temp.push_back(')');
            solve(open,close+1,n,temp,ans);
            temp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        solve(0,0,n,temp,ans);
        return ans;
    }
};


class Solution {
public:
    vector<string> ans;
    void f(string s,int open,int close){        //open => '(' count remaining
        if(open==0&&close==0){                  //close=> ')' count remaining
            ans.push_back(s);
            return;
        }
        if(open>0)f(s+"(",open-1,close);
        if(open<close)f(s+")",open,close-1);    //'(' must be placed before ')'
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        f("",n,n);                              //Balanced string will have
        return ans;                             //n-open and n-closing brackets
    }
};