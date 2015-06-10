class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		string* strArr = new string[numRows];
		int n = s.length();
		for (int i = 0; i < n; i++) {
			int pos = i % (numRows * 2 - 2);
			if (pos < numRows) {
				strArr[pos] += s[i];
			}
			else {
				strArr[numRows * 2 - 2 - pos] += s[i];
			}
		}
		string result = "";
		for (int i = 0; i < numRows; i++) {
			result += strArr[i];
		}
		return result;
	}
};
