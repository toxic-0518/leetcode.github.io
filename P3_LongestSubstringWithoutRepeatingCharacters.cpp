class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) {
            return 0;
        }
        vector<int> vec(256, -1);
        int count = 0;
        int start = 0;
        for(int i = 0; i < s.length(); i++) {
            if(vec[s[i]] >= start) {
                start = vec[s[i]] + 1;
            } 
            vec[s[i]] = i;
            count = max(count, i - start + 1);
        }
        return count;
    }
};
