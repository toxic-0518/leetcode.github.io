class Solution {
public:
	int maxArea(vector<int>& height) {
		if(height.size() <= 1) return 0;
		int i = 0, j = height.size() - 1;
		int left = height[i], right = height[j];
		int area = min(left, right);
		while(i < j) {
		    int minHeight = min(height[i], height[j]);
		    if(minHeight * (j - i) > area) area = minHeight * (j - i);
		    while(i < j && height[i] <= minHeight) i++;
		    while(i < j && height[j] <= minHeight) j--;
		}
		return area;
	}
};
