
brute force is of 2 for loops
for(int i=0 ..n)
{
    for(int j=i+2 ....n)
    if(isValid(s,i,j))
}

class Solution {
public:
    int longestValidParentheses(string s)
    {
        
        int n=s.size();
        int ans=0;
        int left=0,right=0;
        for(int i=0;i<n;i++)
        {
           if(s[i]==')')
           {
               right++;
           }
           else if(s[i]=='(')
            {
                left++;
            }
            if(left==right)
            {
                ans=max(left+right,ans);
            }
            else if(right>left)
            {
                left=right=0;
            }
        }
        
        left=right=0;
        
        for(int i=n-1;i>=0;i--)
        {
           if(s[i]=='(')
           {
               left++;
           }
            else if(s[i]==')')
            {
                right++;
            }
            if(left==right)
            {
                ans=max(left+right,ans);
            }
            else if(left>right)
            {
                left=right=0;
            }
        }
        
        return ans;
    }
};
My solution uses DP. The main idea is as follows: I construct a array longest[], for any longest[i], it stores the longest length of valid parentheses which is end at i.

And the DP idea is :

If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.

Else if s[i] is ')'

     If s[i-1] is '(', longest[i] = longest[i-2] + 2

     Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        int dp[n];  // dp[i] denotes longestValidParentheses till i
        int ans=0;
        for(int i=0;i<n;i++)
            dp[i]=0;
        for(int i=1;i<n;i++){
            if(s[i]=='(')
                dp[i]=0;
            else{
                if(s[i-1]=='('){
                    if(i>=2){
                        dp[i]=dp[i-2]+2;
                    }
                    else
                        dp[i]=2;
                }
                else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='('){
                    if(i-dp[i-1]>=2)
                        dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2;
                    else
                        dp[i]=dp[i-1]+2;   
                }
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};
   int longestValidParentheses(string s) {
            if(s.length() <= 1) return 0;
            int curMax = 0;
            vector<int> longest(s.size(),0);
            for(int i=1; i < s.length(); i++){
                if(s[i] == ')'){
                    if(s[i-1] == '('){
                        longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
                        curMax = max(longest[i],curMax);
                    }
                    else{ // if s[i-1] == ')', combine the previous length.
                        if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                            longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                            curMax = max(longest[i],curMax);
                        }
                    }
                }
                //else if s[i] == '(', skip it, because longest[i] must be 0
            }
            return curMax;
        }




class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), longest = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }
        if (st.empty()) longest = n;
        else {
            int a = n, b = 0;
            while (!st.empty()) {
                b = st.top(); st.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            longest = max(longest, a);
        }
        return longest;
    }
};
The workflow of the solution is as below.

Scan the string from beginning to end.
If current character is '(',
push its index to the stack. If current character is ')' and the
character at the index of the top of stack is '(', we just find a
matching pair so pop from the stack. Otherwise, we push the index of
')' to the stack.
After the scan is done, the stack will only
contain the indices of characters which cannot be matched. Then
let's use the opposite side - substring between adjacent indices
should be valid parentheses.
If the stack is empty, the whole input
string is valid. Otherwise, we can scan the stack to get longest
valid substring as described in step 3.