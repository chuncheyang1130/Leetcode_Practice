class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string str(num, ' ');
        for (int i = 0; i < num; i++){
            if (sum < 10){
                str[i] = '0' + sum;
                sum = 0;
            }
            else {
                str[i] = '9';
                sum -= 9;
            }
        }

        if (sum != 0)
            return "";

        return str;
    }
};