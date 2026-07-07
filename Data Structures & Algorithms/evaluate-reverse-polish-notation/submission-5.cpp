class Solution {
   private:
    int calc(int n, int m, string c) {
        if (c == "+") {
            return n + m;
        }
        if (c == "-") {
            return n - m;
        }
        if (c == "*") {
            return n * m;
        }
        return n / m;
    }

   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& h : tokens) {
            if (h == "+" || h == "-" || h == "*" || h == "/") {
                int m = st.top();
                st.pop();
                int n = st.top();
                st.pop();
                st.push(calc(n, m, h));
            } else {
                st.push(stoi(h));
            }
        }
        return st.top();
    }
};
