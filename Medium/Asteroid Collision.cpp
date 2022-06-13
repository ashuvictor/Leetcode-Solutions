
https://leetcode.com/problems/asteroid-collision/
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;bool flag=true;
     for(auto x:asteroids)
     { flag=true;
         while(!st.empty() and x<0 and st.top()>0)
         {
             if(abs(x)>st.top())
                 st.pop();
             else if(abs(x)<st.top())
             {
                 flag=false;break;
             }
             else
             {
                 st.pop();flag=false;break;
             }
                 
         }
         if(flag)
             st.push(x);
     
     }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
        }
};




class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> ans;
        stack<int> s;
        //cases
        // stack top --- incoming asteroid
        // left          left         nothing happens
        // left          right        nothing happens
        // right         left         collision (+-)
        // right          right       nothing happens
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(asteroids[i]);
            }
            else{
                if(s.top()>0 && asteroids[i]<0){
                    bool f=false;
                    while(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(asteroids[i])>abs(s.top())){
                        s.pop();
                        f=true;
                    }
                    bool g=false;
                    if(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(asteroids[i])==abs(s.top())){
                        s.pop();
                        g=true;
                    }
                    if(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(asteroids[i])<abs(s.top())){
                        g=true;
                    }
                    if(f && !g)
                        s.push(asteroids[i]);
                }
                else {
                    s.push(asteroids[i]);
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};