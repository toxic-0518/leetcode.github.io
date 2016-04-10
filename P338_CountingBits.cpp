//Solution 1 O(n)
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> v(num + 1);
		for (int i = 1; i <= num; i++) v[i] = v[i & (i - 1)] + 1;
		return v;
	}
};
//Solution 2 O(n)
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> v(num + 1);
		for (int n = 1; n <= num; n *= 2) {
			int i = 0, j = n, end = min(num, 2 * n - 1);
			while (j <= end) {
				v[j++] = v[i++] + 1;
			}
		}
		return v;
	}
};
