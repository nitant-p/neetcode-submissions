class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> table;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        table[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = table.find(key);
        if (it == table.end()) return "";

        auto& vals = it->second;

        int low = 0, high = vals.size() - 1;
        if (vals[low].first > timestamp) return "";

        int maxI = INT_MIN;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vals[mid].first > timestamp) high = mid - 1;
            else if (vals[mid].first < timestamp) {
                low = mid + 1;
                maxI = max(maxI, mid);
            }
            else return vals[mid].second;
        }

        return vals[maxI].second;
    }
};
