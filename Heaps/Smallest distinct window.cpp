Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1/
https://leetcode.com/problems/minimum-window-substring/


acquire till the time you get the  and when you get all then start releasing till match count doesnt disturb


 string minWindow(string s, string t) {
        
        int beg=0,mn=INT_MAX;
        int c=0,in=-1;
        int ns=s.length(),nt=t.length();
        unordered_map<char,int> m1,m2;
        int i;
        
        for(i=0;i<nt;i++)
            m1[t[i]]++;
        
        
        for(i=0;i<ns;i++)
        {
            if(c<nt)
            {
                m2[s[i]]++;
                
                if(m1.find(s[i])!=m1.end() && m2[s[i]]<=m1[s[i]])
                    c++;
            }
            
            while(c==nt && beg<=i)
            {
                if(i-beg+1<mn)
                {
                    mn=i-beg+1;
                    in=beg;
                }
                m2[s[beg]]--;
                
                if(m1.find(s[beg])!=m1.end() && m2[s[beg]]<m1[s[beg]])
                    c--;
                
                beg++;
            }
        }
        
        if(mn==INT_MAX)
            return "";
        
        return s.substr(in,mn);
    }  string minWindow(string s, string t)
    {
        int ns=s.length(),nt=t.length();
        int c=0,beg=0;
        int mn=INT_MAX,in=-1;        
        int i;
        unordered_map<char,int> m;
        
        for(i=0;i<nt;i++)
            m[t[i]]++;
        
        for(i=0;i<ns;i++)
        {
            m[s[i]]--;
            
            if(m[s[i]]>=0)
                c++;
            
            while(c==nt && beg<=i)
            {
                if(i-beg+1<mn)
                {
                    mn=i-beg+1;
                    in=beg;
                }
                
                m[s[beg]]++;
                if(m[s[beg]]>0)
                    c--;
                
                beg++;
            }
        }
        
        if(mn==INT_MAX)
            return "";
        
        return s.substr(in,mn);
    }
3. Using freq array (fastest)
Time - O(n)
Space - O(256) (max of 256 characters can be there in map)

    string minWindow(string s, string t)
    {
        int ns=s.length(),nt=t.length();
        int c=0,beg=0;
        int mn=INT_MAX,in=-1;        
        int i;
        int f[256]={0};
        
        for(i=0;i<nt;i++)
            f[t[i]]++;
        
        for(i=0;i<ns;i++)
        {
            f[s[i]]--;
            
            if(f[s[i]]>=0)
                c++;
            
            while(c==nt && beg<=i)
            {
                if(i-beg+1<mn)
                {
                    mn=i-beg+1;
                    in=beg;
                }
                
                f[s[beg]]++;
                if(f[s[beg]]>0)
                    c--;
                
                beg++;
            }
        }
        
        if(mn==INT_MAX)
            return "";
        
        return s.substr(in,mn);
    }


string minWindow(string s, string t) {
int count =0;int start_idx=-1;
int min_so_far=INT_MAX;
int start=0;int window_size;

    //now making our searing table by array
    int ft[256]={0};//frequency list of t array
    int fs[256]={0};//frequency list of s array
    
    //update frequency of t in ft
    for(int i=0;i<t.length();i++){
        ft[t[i]]++;
    }
    
    //sliding window algorithm
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        fs[ch]++;
        
     //we will check how many characters matched till now in fs and ft
        if(ft[ch]!=0 && fs[ch]<=ft[ch]){
            count++;
        }
        
      //any point if string t length==count i.e all frequency we contain in fs
      //start contraction
        
       if(count==t.length()){
        //start removing from left if the character not present in t string 
        //or frequency is higher than the required frequency
         while(ft[s[start]]==0 || fs[s[start]]>ft[s[start]]){
             fs[s[start]]--;
             start++;
         }
           //note the window size
        window_size=i-start+1;
        if(window_size<min_so_far){
            min_so_far=window_size;
            start_idx=start;
        }
           
      }
        
        
        
    }
    if(start_idx==-1){return "";}
    
    return s.substr(start_idx,min_so_far);
}




//gfg
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
     unordered_map<char,int>M;
     for(auto c:str)
     {
         M[c]++;
     }
     int n=str.length();
     int m=M.size();
     int res=INT_MAX;
    M.clear();
    int i=0,j=0;
    while(j<n){
        M[str[j]]++;
        if(M.size()<m)
        j++;
        else if(M.size()>=m){
            while(M.size()>=m){
                res=min(res,j-i+1);
                M[str[i]]--;
                if(M[str[i]]==0)
                M.erase(str[i]);
                i++;
            }
            j++;
        }
        
    }
    return res;
    }
};
