class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];
    
    for (int i = 0; i < n; i++) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        st.pop();
      }
        
      int k = st.empty()? 0 : st.top() + 1;
      leftsmall[i] = k;
        
      st.push(i);
    }
    
    while (!st.empty())
      st.pop();
    
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && heights[st.top()] >= heights[i])
        st.pop();

      int k = st.empty()? n-1 : st.top() - 1;
      rightsmall[i] = k;

      st.push(i);
    }
    
    int maxA = 0;
    for (int i = 0; i < n; i++) {
      maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    
    return maxA;
  }
};