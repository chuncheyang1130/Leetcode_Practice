class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m+n;
        while (l--){
            if (n == 0){
                nums1[l] = nums1[m-1];
                m -= 1;
            }else if (m == 0){
                nums1[l] = nums2[n-1];
                n -= 1;
            }else if (nums1[m-1] >= nums2[n-1]){
                nums1[l] = nums1[m-1];
                m -= 1;
            }else{
                nums1[l] = nums2[n-1];
                n -= 1;
            }
            // cout << "l: " << l << " / " << nums1[l] << endl;
        }
    }
};