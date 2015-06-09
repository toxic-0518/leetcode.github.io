/**
 *  Dynamic Programming Method
 *  Time(O^2) Space(O^2)
 * 
 **/
 
class Solution {
public:
    string longestPalindrome(string s) {
        bool table[1000][1000] = {false};
        int maxLen = 1;
        int start = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            table[i][i] = true;
        }
        
        for(int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1]) {
                table[i][i+1] = true;
                maxLen = 2;
                start = i;
            }
        }
        
        for(int len = 3; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if(table[i+1][j-1] && s[i] == s[j]) {
                    table[i][j] = true;
                    if(len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
