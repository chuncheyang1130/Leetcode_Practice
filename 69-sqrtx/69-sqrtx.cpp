class Solution {
public:
    int mySqrt(int x) {
        long long upper = 1000000;
        long long lower = 0;
        
        long long mid = (upper+lower)/2;
        while(upper > lower){
            if((mid+1)*(mid+1) > x && mid*mid <= x)
                break;
            else if((mid+1)*(mid+1) <= x)
                lower = mid + 1;
            else if(mid*mid >= x)
                upper = mid - 1;
            
            mid = (upper+lower)/2;
        }
        return (int)mid;
    }
};