//solution 1
class Solution {
public:
    string intToRoman(int num) {
        string M[4] = {"", "M", "MM", "MMM"};
        string C[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string result = M[num / 1000] + C[num % 1000 / 100] + X[num % 100 / 10] + I[num % 10];
        return result;
        
    }
};
//solution 2
class Solution {
public:
    string intToRoman(int num) {
        int cur = 0;
        string result = "";
        cur = num / 1000;
        for(int i = 0; i < cur; i++) result += "M";
        num %= 1000;
        if(num >= 900) {
            result += "CM";
            num -= 900;
        }
        else if(num >= 500) {
            result += "D";
            num -= 500;
        }
        else if(num >= 400) {
            result += "CD";
            num -= 400;
        }
        cur = num / 100;
        for(int i = 0; i < cur; i++) result += "C";
        num %= 100;
        if(num >= 90) {
            result += "XC";
            num -= 90;
        }
        else if(num >= 50) {
            result += "L";
            num -= 50;
        }
        else if(num >= 40) {
            result += "XL";
            num -= 40;
        }
        cur = num / 10;
        for(int i = 0; i < cur; i++ ) result += "X";
        num %= 10;
        if(num == 9) {
            result += "IX";
            return result;
        }
        else if(num >= 5) {
            result += "V";
            num -= 5;
        }
        else if(num == 4) {
            result += "IV";
            return result;
        }
        cur = num;
        for(int i = 0; i < cur; i++ ) result += "I";
        return result;
        
    }
};
