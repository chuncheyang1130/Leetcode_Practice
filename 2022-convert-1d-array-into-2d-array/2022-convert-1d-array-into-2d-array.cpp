class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size())
            return vector<vector<int>>();

        vector<vector<int>> matrix(m);

        int start = 0;

        for (int i = 0; i < m; i++){
            matrix[i] = vector<int>(original.begin()+start, original.begin()+start+n);
            start += n;
        }

        return matrix;
    }
};