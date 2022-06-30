class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int totalNum = size1 + size2;
        int n1, n2;
        for(int i = -1, j = -1; ; ){
            if(i+1 == size1 || (j+1 < size2 && nums1[i+1] > nums2[j+1]) ){
                if(i+j+2 == (totalNum-1)/2)
                    n1 = nums2[j+1];
                if(i+j+2 == totalNum/2){
                    n2 = nums2[j+1];
                    break;
                }else{
                    j++;
                }
            }else if(j+1 == size2 || (i+1 < size1 && nums1[i+1] <= nums2[j+1])){
                if(i+j+2 == (totalNum-1)/2)
                    n1 = nums1[i+1];
                if(i+j+2 == totalNum/2){
                    n2 = nums1[i+1];
                    break;
                }else{
                    i++;
                }
            }
        }
        
        return (n1 + n2) / 2.0;
    }
};