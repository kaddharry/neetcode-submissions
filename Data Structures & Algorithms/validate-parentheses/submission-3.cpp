class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        char c = s[i];
        stack<char> st;
        st.push('z'); // z marks the end
        if (c == ')' || c == ']' || c == '}')
            return false;
        st.push(c);
        i++;
        while (i < s.size()) {
            c = s[i];
            char temp = st.top(); // if temp == z and c = s[i] != \0 that means
                                  // it's an open bracket so push so it need to be on top of stack
            if (c == ')' && temp != '(')
                return false;
            if (c == ']' && temp != '[')
                return false;
            if (c == '}' && temp != '{')
                return false;
            if (c == ')' || c == ']' || c == '}')
                st.pop();
            else
                st.push(c);

            i++;
        }
        if (st.top() == 'z')
            return true;
        return false;
    }
};