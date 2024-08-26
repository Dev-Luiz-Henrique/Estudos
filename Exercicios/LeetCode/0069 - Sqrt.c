/*
    Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
    The returned integer should be non-negative as well.

    You must not use any built-in exponent function or operator.
    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/
 
int mySqrt(int x) {                   
    long long low = 1, high = x, mid;
    int res = 0;
    while(low <= high){                                  
        mid = low + (high - low)/2;
        if(mid * mid == x) return mid;
        if(mid * mid < x) {
            low = mid + 1;  
            res = mid;
        }
        else high = mid - 1;
    }
    return res;
}

int main() {
    return 0;
}