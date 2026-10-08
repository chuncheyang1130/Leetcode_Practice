class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h;
        for(h = 0; h < citations.size(); h++){
            if (citations[h] <= h)
                break;
        }


        return h;
    }
};