class AllOne {
public:
    unordered_map<string, int> mp;
    set<pair<int, string>> st;
    AllOne() {
        
    }
    
    void inc(string key) {
        st.erase({mp[key], key});
        mp[key] ++;
        st.insert({mp[key], key});
    }
    
    void dec(string key) {
        st.erase({mp[key], key});
        mp[key] --;
        if(mp[key] > 0)
            st.insert({mp[key], key});
    }
    
    string getMaxKey() {
        return st.size() ? prev(st.end())->second : "";
    }
    
    string getMinKey() {
        return st.size() ? st.begin()->second : "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */