class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generate(0, 0, n * 2, "");
        return pars;
    }
    void generate(int left, int right, int total, string cur) {
        if(left + right == total) {
            pars.push_back(cur);
            return;
        }
        else if(right == left) {
            generate(left + 1, right, total, cur + '(');
        } 
        else if(left == total / 2) {
            generate(left, right + 1, total, cur + ')');
        }
        else {
            generate(left + 1, right, total, cur + '(');
            generate(left, right + 1, total, cur + ')');
        }
    }
private:
    vector<string> pars;
};
