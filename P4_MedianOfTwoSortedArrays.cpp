class Solution {
public:
    static int findkthsmallest(vector<int>::iterator itv1, int m,  vector<int>::iterator itv2, int n,  int k) {
        if(n > m) {
            return findkthsmallest(itv2, n, itv1, m, k);
        }
        if(n == 0) {
            return *(itv1 + k - 1);
        }
        if(k == 1) {
            return min(*itv1, *itv2);
        }
        int j = min(k / 2, n);
        int i = k-j;
        if(*(itv1 + i - 1) > *(itv2 + j - 1)) {
            return findkthsmallest(itv1, i, itv2 + j, n - j, k - j);
        }
        else {
            return findkthsmallest(itv1 + i, m - i, itv2, j, k - i);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = (nums1.size() + nums2.size()) / 2;
        int m1 = findkthsmallest(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), k + 1);
        if((nums1.size() + nums2.size())%2 == 0) {
            int m2 = findkthsmallest(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), k);
            return (double)((double)m1 + (double)m2)/2.0;
        }
        return (double)m1;
    }
};
