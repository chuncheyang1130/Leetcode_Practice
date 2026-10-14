class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string str = "";
        for (int i = 0; i < num; i++){
            if (sum < 10){
                str.push_back('0'+sum);
                sum = 0;
            }
            else {
                str.push_back('9');
                sum -= 9;
            }
        }

        if (sum != 0)
            return "";

        return str;
    }
};