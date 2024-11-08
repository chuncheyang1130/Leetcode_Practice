class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> intersec;
        
        int i = 0, j = 0, k = 0;
        
        while (i < arr1.size() && j < arr2.size() && k < arr3.size()){
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]){
                intersec.push_back(arr1[i]);
                i++;
                j++;
                k++;
            }else {
                int minimum = min({arr1[i], arr2[j], arr3[k]});
                if (arr1[i] == minimum)
                    i++;
                if (arr2[j] == minimum)
                    j++;
                if (arr3[k] == minimum)
                    k++;
            }
        }


        return intersec;
    }
};