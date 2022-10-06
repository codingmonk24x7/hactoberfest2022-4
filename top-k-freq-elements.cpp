class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        for(auto X: nums) {
            check[X]++;
        }
        
        multimap<int, int> freq;
        for(auto X: check) {
            freq.insert({X.second, X.first});
        }
        
        vector<int> ans;
        int t = 0;
        for(auto i = freq.rbegin(); i != freq.rend(); i++) {
            if(t < k) {
                ans.push_back(i->second);
                t++;
            } else break;
        }
        
        return ans;
    }
};
