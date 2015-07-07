class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int w = x, y = 0;
        while (w != 0) {
            y *= 10;
            y += w % 10;
            w /= 10;
        }
        return x==y;
    }
};
