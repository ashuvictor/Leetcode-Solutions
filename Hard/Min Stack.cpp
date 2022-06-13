
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.


class MinStack {
public:
    stack<int>st;
    stack<int>st1;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        st1=st;
        int mini=INT_MAX;
        while(!st1.empty())
        {
            mini=min(mini,st1.top());
            st1.pop();
        }
        return mini;
    }
};






class MinStack {
public:
    stack<int>s;
    stack<int>s2;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(s2.empty() or val<=s2.top())
            s2.push(val);
    }
    
    void pop() {
        if(!s2.empty() and !s.empty() and s.top()==s2.top())
s2.pop();
        s.pop();
        }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s2.top();
    }
};



class MinStack {
public:
  stack<pair<int, int>> minStack;
  MinStack() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }

  void push(int val) {
    int minimum = !minStack.empty()? min(val, minStack.top().second): val;
    minStack.push({val, minimum});
  }

  void pop() {
    minStack.pop();
  }

  int top() {
    return minStack.top().first;
  }

  int getMin() {
    return minStack.top().second;
  }
};



class MinStack {
  stack < long long > st;
  long long mini;
  public:
    /** initialize your data structure here. */
    MinStack() {
      while (st.empty() == false) st.pop();
      mini = INT_MAX;
    }

  void push(int value) {
    long long val = Long.valuevalue;
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
        st.push(2 * val * 1 LL - mini);
        mini = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  int top() {
    if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;
    return el;
  }

  int getMin() {
    return mini;
  }
};