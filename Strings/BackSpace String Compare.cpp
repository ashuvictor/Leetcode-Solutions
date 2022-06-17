

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

class Solution {
public:
    bool backspaceCompare(string s, string t) {
            stack<char> s1, s2;
    
    //while the entered char isn't '#', add it to the stack
    //while the entered char is '#' & the stack contains at least one char, remove the top of the stack
    for(int i=0;i<s.length();i++){
        if(s[i]!='#'){
            s1.push(s[i]);
        }
        else if(s[i]=='#' && !s1.empty()){
            s1.pop();
        }
    }
    
    //the same algorithm as the above one
    for(int j=0;j<t.length();j++){
        if(t[j]!='#'){
            s2.push(t[j]);
        }
        else if(t[j]=='#' && !s2.empty()){
            s2.pop();
        }
    }
    
    //comparing the char of the two stack one by one, they must be from the same size
    int x=s1.size();
    int y=s2.size();
    
    if(x==y){
        for(int k=0;k<x;k++){
            if(s1.top()!=s2.top()){
                return false;
            }
            else{
                s1.pop();
                s2.pop();
            }
        }
        return true;
    }
    else{
        return false;
    }

    }
};




class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size(), m=t.size();
        int i=n-1, j=m-1;
        int skips=0, skipt=0;
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    skips++;
                    i--;
                }
                else if(skips>0){
                    skips--;
                    i--;
                }
                else
                    break;
            }
            while(j>=0){
                if(t[j]=='#'){
                    skipt++;
                    j--;
                }
                else if(skipt>0){
                    skipt--;
                    j--;
                }
                else
                    break;
            }
            if(i>=0 && j>=0 && s[i]!=t[j])
                return false;
            if((i>=0) != (j>=0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};