class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        while((num > 0) && (num & 1) != 1) {
            num >>= 1;
            if((num & 1) != 0) return false;
            num >>= 1;
        };
        return ((1 ^ num) == 0);
    }
};
