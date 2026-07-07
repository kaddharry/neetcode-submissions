class Solution {
private:
    int calc(int n, int m, string c){
        if(c == "+"){
            return n+m;
        }
        if(c == "-"){
            return n-m;
        }
        if(c == "*"){
            return n*m;
        }
        return n/m;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){
            string h = tokens[i];
            if(st.size() < 2){
                if(h == "+" || h == "-" || h == "*" || h == "/") return 0;
                else st.push(stoi(h));
            }
            else{
                if(h == "+" || h == "-" || h == "*" || h == "/"){
                    int m = st.top();
                    st.pop();
                    int n = st.top();
                    st.pop();
                    int res = calc(n,m,h);
                    st.push(res);
                }
                else st.push(stoi(h));
            }
        }
        if(st.size() != 1) return 0;
        return st.top();
    }
};
