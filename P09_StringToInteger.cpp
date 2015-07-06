class Solution {
public:
    int myAtoi(string str) {
        double base;
        int sig = 1;
        int i = 0;
        while(i < str.length() && str[i] == ' ')
            i++;
        if(i < str.length() && str[i] == '-' || str[i] == '+') {
            if(str[i] == '-') sig = -1;
            i++;
        }
      
        if(i == str.length() || str[i] > '9' || str[i] < '0') {
            return 0;
        }
        else {
            base = (int)(str[i] - '0');
            i++;
        }
        while(i < str.length()) {
            if(str[i] > '9' || str[i] < '0') {
                break;
            }
            else {
                base *= 10;
                base += (int)(str[i] - '0');
                i++;
            }
            
        }
        base *= sig;
        if(base > INT_MAX) 
            return INT_MAX;
        else if(base < INT_MIN)
            return INT_MIN;
        else
            return (int)base;
        
    }
};
