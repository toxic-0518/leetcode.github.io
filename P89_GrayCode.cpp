class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> code{0};
        if(n == 0) return code;
        int s = 1;
        for(int i = 0; i < n; i++) s *= 2;
        code.resize(s);
        code[0] = 0;
        code[1] = 1;
        int i = 2;
        while(i * 2 <= s) {
            for(int j = i; j <= 2 * i - 1; j++) {
                code[j] = i + code[2 * i - j - 1];
            }
            i *= 2;
        }
        return code;
    }
};
