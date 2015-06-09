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

/**
 *  Brute Force
 *  Time(O^2) Space(1)
 * 
 **/
 
class Solution {
public:
    static string expandAroundCenter(string s, int c1, int c2) {
        int l = c1, r = c2, n = s.length();
        while(l >= 0 && r <= n-1 && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, (r - 1) - (l + 1) + 1);
    }
    string longestPalindrome(string s) {
        string longest, temp;
      for(int i = 0; i < s.length(); i++) {
          temp = expandAroundCenter(s, i, i);
          if(temp.length() > longest.length()) {
              longest = temp;
          }
          temp = expandAroundCenter(s, i, i + 1);
          if(temp.length() > longest.length()) {
              longest = temp;
          }
      }
      return longest;
    }
};

/**
 *  Manacher’s Algorithm
 *  Time O(n) Space O(n)
 * 
 **/
 
class Solution {
public:
    static string preProcess(string s) {
        if(s.length() == 0) {
            return "^$";
        }
        string ret = "^";
        for(int i = 0; i < s.length(); i++) {
            ret += "#" + s.substr(i,1);
        }
        ret += "#$";
        return ret;
    }
    string longestPalindrome(string s) {
        string T = preProcess(s);
        int n = T.length();
        int C = 0, R = 0;
        int* P = new int[n];
        for(int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i;
            P[i] = R > i ? min(R - i, P[i_mirror]) : 0;
            while(T[i + 1 + P[i]] ==  T[i - 1 - P[i]]) {
                P[i]++;
            }
            if(P[i] + i > R) {
                R = i + P[i];
                C = i;
            }
        }
        int maxLen = 0;
        int center = 0;
        for(int i = 1; i < n - 1; i++) {
            if(P[i] > maxLen) {
                maxLen = P[i];
                center = i;
            }
        }
        delete [] P;
        P = nullptr;
        return s.substr((center - maxLen - 1) / 2, maxLen);
    }
};
