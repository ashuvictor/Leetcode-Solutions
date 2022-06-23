



Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
class Solution {
public:

    //create "num" copies of str [ex: num = 3, str = "abc" => ans = "abcabcabc"]
    string decode_handler(int num, string str)
    {
        string ans = "";
        while(num--)
            ans+=str;
        return ans;
    }
    
    //recursive function to decode string (pos is pass by reference to keep track of pointer in same string)
    string decode_helper(int &pos, string s)
    {
        int n = s.size();
        int num = 0;
        string plaintext = "";
        
        for(; pos < n; ++pos)
        {
            if(s[pos] >= '0' and s[pos] <='9')      //store number of times to send to decode_handler
                num = num*10 + s[pos] - '0';        //handle double digits ( ex: 10[a] )
            
            else if(s[pos] >='a' and s[pos] <= 'z') //if english letter, append to plaintext
                plaintext += s[pos];
            
            else if(s[pos] == '[')                  // if open brace, deocde inside part first
            {
                string temp = decode_helper(++pos, s); //store result of inside decoding
                plaintext +=  decode_handler(num,temp); //handle outside decoding and add to current plaintext
                num = 0;                                // reset num for next concatentaion [ex: 3[a]2[b] -> after num = 3, str = "a" done, we need to start again from num =2, str = "b"]
            }   
            else if(s[pos] == ']')                  //if close brace, return plaintext to process
                return plaintext; 
        }
        return plaintext;                           //control will reach here for cases like 2[a]b ->aab -> have to return plaintext outside loop too.
    }
    
    string decodeString(string s) {
        int pos = 0;
        string plaintext = decode_helper(pos,s);
        return plaintext;
    }
};




class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int i=0,n=s.size();
        string ans="";
        while(i<n){
            st.push(s[i]);
            if(st.top()==']'){
                st.pop();
                string s1="";
                while(!st.empty() && st.top()!='['){
                    s1+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(s1.begin(), s1.end());
                string num="";
                string v="";
                int times=0;
                while(!st.empty() && isdigit(st.top())){
                    num+=st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());
                times=stoi(num);
                for(int i=0;i<times;i++)
                    v+=s1;
                for(int i=0;i<v.size();i++)
                    st.push(v[i]);
            }
            i++;
        }
        while(!st.empty()){
                    ans+=st.top();
                    st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};