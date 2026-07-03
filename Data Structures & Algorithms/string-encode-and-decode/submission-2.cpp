class Solution {
public:
    string encode(vector<string>& strs) {
        ostringstream oss;
        for (string s : strs) {
            oss << s.size() << "#" << s;
        }
        return oss.str();
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int i = 0;
        
        while (i < s.length()) {
            int hash_pos = s.find('#', i);
            string length_str = s.substr(i, hash_pos - i);
            int length = stoi(length_str);
            
            i = hash_pos + 1;
            string word = s.substr(i, length);
            decoded_strs.push_back(word);
            
            i += length;
        }
        
        return decoded_strs;
    }
};
