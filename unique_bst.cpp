class Solution {
public:
    int countPattern(int n, vector<int> &check) {
        if(check[n] != -1) return check[n];
        
        if(n < 2) return check[n] = 1;
        
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += countPattern(i-1, check)*countPattern(n-i, check);
        }
        
        return check[n] = sum;
    }
    
    int numTrees(int n) {    
        vector<int> check(n+1, -1);
        return countPattern(n, check);
    }
};
