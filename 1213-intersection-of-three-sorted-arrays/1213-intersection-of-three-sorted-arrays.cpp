class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> intersec;
        map<int, int> ht;

        for (auto& el : arr1){
            if (ht.find(el) == ht.end())
                ht[el] = 1;
            else ht[el]++;
        }

        for (auto& el : arr2){
            if (ht.find(el) == ht.end())
                ht[el] = 1;
            else ht[el]++;
        }

        for (auto& el : arr3){
            if (ht.find(el) == ht.end())
                ht[el] = 1;
            else ht[el]++;
        }

        for (auto it = ht.begin(); it != ht.end(); it++){
            if (it->second == 3)
                intersec.push_back(it->first);
        }

        return intersec;
    }
};