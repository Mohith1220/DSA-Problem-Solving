class Solution {
private:
    int memo[31] = {0}; 

public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
    
        if (memo[n] != 0) {
            return memo[n];
        }
    
        return memo[n] = fib(n - 1) + fib(n - 2);
    }
};
