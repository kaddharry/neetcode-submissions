class Solution {
    void helper(string& s, int& i, string &res){
        int cur = 0;
        while(i < s.length()){
            char c = s[i];

            if(isdigit(c)){
                cur = (c - '0') + (cur*10);
                i++;
            }
            else if(c == '['){
                i++;
                string temp = "";
                helper(s, i, temp);

                for(int k = 1; k <= cur; ++k){
                    res += temp;
                }
                cur = 0;
            }
            else if(c == ']'){
                i++;
                return;
            }
            else{
                res.push_back(c);
                i++;
            }
        }

    }
public:
    string decodeString(string s) {
        string result = "";
        int i = 0;
        helper(s, i, result);
        return result;
    }
};