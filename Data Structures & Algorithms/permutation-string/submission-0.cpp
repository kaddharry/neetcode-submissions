class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(); //window size
        sort(s1.begin(),s1.end());
        string comp = s1;
        for(int i = 0; i < s2.size() - k + 1; i++){
            string temp = s2.substr(i, k);
            sort(temp.begin(), temp.end());
            if(comp == temp) return true;
        }
        return false;
    }
};
