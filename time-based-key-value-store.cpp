class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mapping;
    
    TimeMap() {    
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {  
        int s = 0, e = mapping[key].size()-1, mid = s + (e-s)/2;
        
        while(s <= e) {
            mid = s + (e-s)/2;
            if(mapping[key][mid].first == timestamp) {
                return mapping[key][mid].second;
            }
            if(mapping[key][mid].first > timestamp) {
                e = mid - 1;
            } else {
                s = mid + 1;
                if(s <= e && mapping[key][s].first > timestamp) return mapping[key][mid].second;
            }
        }
        
        if(mid < mapping[key].size() && mapping[key][mid].first < timestamp) return mapping[key][mid].second;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
