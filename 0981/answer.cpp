class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> t;
        
    TimeMap() {
          
    }
    
    void set(string key, string value, int timestamp) {
        this->t[key][timestamp] = value; 
    }
    
    string get(string key, int timestamp) {
        if (this->t[key].empty()) return "";
        auto it = this->t[key].lower_bound(timestamp);
        if (it->first == timestamp) return it->second;
        if (it == t[key].begin()) return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
