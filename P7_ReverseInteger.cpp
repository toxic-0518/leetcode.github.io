// note : in c++, the bool value of a non-zero integer is "true"
// while in c, the bool value of a positive integer is "true" 
class Solution {
public:
	int reverse(int x) {
		int result = 0;
		while (true) {
			result += (x % 10);
			x /= 10;
			if (!x) break;
			if (result > INT_MAX / 10 || result  < INT_MIN / 10) return 0;
			result *= 10;
		}
		return result;
	}
};
