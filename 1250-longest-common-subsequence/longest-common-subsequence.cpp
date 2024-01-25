class Solution {
public:
    int binarySearch(vector<int>& vec, int target) {
        int left = 0, right = vec.size()-1;

        while (left != right){
            int mid = (left + right) / 2;

            if (vec[mid] < target)
                left = mid + 1;
            else if (vec[mid] >= target)
                right = mid; 
        }

        return right;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<int> LIS;
        vector<int> seq;
        vector<vector<int>> alphs(26, vector<int>());

        for (int i = (int)text1.size()-1; i >= 0; i--){
            int alph = text1[i]-'a';
            alphs[alph].push_back(i);
        }

        for (int i = 0; i < text2.size(); i++){
            int alph = text2[i]-'a';
            seq.insert(seq.end(), alphs[alph].begin(), alphs[alph].end());
        }

        // for (int i = 0; i < seq.size(); i++)
        //     cout << seq[i] << " ";
        // cout << endl;

        for (int i = 0; i < seq.size(); i++){
            if (LIS.empty()){
                LIS.push_back(seq[i]);
            }else if (seq[i] > LIS.back()){
                LIS.push_back(seq[i]);
            }else{
                int pos = binarySearch(LIS, seq[i]);
                LIS[pos] = seq[i];
            }

            // for (int i = 0; i < LIS.size(); i++)
            //     cout << LIS[i] << " ";
            // cout << endl;
        }

        int len = LIS.size();
        return len;
    }
};