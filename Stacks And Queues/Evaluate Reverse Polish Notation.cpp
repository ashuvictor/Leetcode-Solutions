



Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="/")
            {
                if(st.size()>=2)
                {
                    int x=st.top();
                    st.pop();
                    int y=st.top();
                    st.pop();
                    if(tokens[i]=="+")
                        st.push(x+y);
                    if(tokens[i]=="-")
                        st.push(y-x);
                    if(tokens[i]=="*")
                        st.push(x*y);
                    if(tokens[i]=="/")
                        st.push(y/x);
                }
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
    return st.top();}
};