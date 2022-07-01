bool cmp(vector<int>& b1, vector<int>& b2){
    if(b1[1] > b2[1])    
        return true;
    else return false;
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int total = 0, ind = 0;
        while(truckSize > 0 && ind < boxTypes.size()){
            if(boxTypes[ind][0] > truckSize){
                total += truckSize * boxTypes[ind][1];
                return total;
            }else{
                total += boxTypes[ind][0] * boxTypes[ind][1];
                truckSize -= boxTypes[ind][0];
                ind++;
            }
        }
        return total;
    }
};