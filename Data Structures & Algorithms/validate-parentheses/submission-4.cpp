class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (st.empty()) {
                if (c == ')' || c == '}' || c == ']')
                    return false;
                else
                    st.push(c);
            } else if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                char top = st.top();

                if (top == '(' && c != ')') return false;
                else if (top == '{' && c != '}') return false;
                else if (top == '[' && c != ']') return false;
                else st.pop();
            }
        }

        return st.empty();
    }
};
