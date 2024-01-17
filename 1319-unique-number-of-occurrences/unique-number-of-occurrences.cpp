class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> record;
        sort(arr.begin(), arr.end());

        int cnt = 1;

        for (int i = 1; i < arr.size(); i++){
            if (arr[i] != arr[i-1]){
                if (record[cnt] > 0){
                    return false;
                }else{
                    record[cnt] = 1;
                    cnt = 1;
                }
            }else cnt++;
        }

        if (record[cnt] > 0)
            return false;

        return true;
    }
};