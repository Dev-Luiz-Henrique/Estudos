/*
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

int climbStairs(int n) {
    int *memo = malloc((n + 2) * sizeof(int));
    memo[1] = 1; 
    memo[2] = 2;

    for(int i = 3; i <= n; i++)
        memo[i] = memo[i-1] + memo[i-2];
    int ans = memo[n];
    free(memo);
    return ans;
}

int main(){
    return 0;
}