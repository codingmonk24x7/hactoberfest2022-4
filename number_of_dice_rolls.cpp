class Solution {
public:
    int calcWays(int n, int k, int target, vector<vector<int>>& check) {
        int M = 1e9 + 7;
        
        if(target < 0) return 0;
        if(target == 0 && n == 0) return 1;
        if(target > 0 && n == 0) return 0;
        if(target == 0 && n > 0) return 0;
        
        if(check[n][target] != -1) return check[n][target];
        
        int ans = 0;
        for(int i = 1; i <= k; i++) {
            ans = (ans + (calcWays(n-1, k, target-i, check) % M)) % M;
        }
        
        return check[n][target] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> check(n+1, vector<int>(target+1, -1));
        
        return calcWays(n, k, target, check);
    }
};
