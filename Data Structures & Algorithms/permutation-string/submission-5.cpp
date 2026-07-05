class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int k = s1.size();  // window size

        vector<int> fq1(26,0);
        vector<int> fq2(26,0);

        for (char x : s1) fq1[x - 'a']++;
        int l = 0, r = 0;
        while (r < s2.size()) {
            fq2[s2[r] - 'a']++;
            if (r - l + 1 == k) {
                if (fq1 == fq2) return true;
                fq2[s2[l] - 'a']--;
                l++;
            }
            r++;
        }
        return false;
    }
};
