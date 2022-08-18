class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> table((int)1e5+1, 0);
        int len = arr.size();
        for(int i = 0; i < arr.size(); i++)
            table[arr[i]]++;
        
        sort(table.begin(), table.end(), greater<int>());
        int total = 0, ans = 0;
        for(int i = 0; i < table.size(); i++){
            total += table[i];
            ans++;
            if(total >= len/2)
                break;
        }
        return ans;
    }
};