/**
 * Solution 1
 * Time : 32ms
 * 
 **/
 
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

/**
 *  Solution 2
 *  Time: 20ms
 * 
 **/
 
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		string* strArr = new string[numRows];
		int n = s.length();
		int i = 0;
		int gap = numRows - 2;
		while (i < n) {
			for (int j = 0; i < n && j < numRows; j++) strArr[j] += s[i++];
			for (int j = gap; i < n && j > 0; j--) strArr[j] += s[i++];
		}
		string result = "";
		for (int i = 0; i < numRows; i++) {
			result += strArr[i];
		}
		return result;
	}
};
