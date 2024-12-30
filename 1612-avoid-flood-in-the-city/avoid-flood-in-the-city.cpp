// class Solution {
// public:
//     vector<int> avoidFlood(vector<int>& rains) {
//         multiset<int> lakesToDryIdx;
//         vector<int> ans;
//         for(int i = 0; i < rains.size(); i ++){
//             // lake to fill
//             if(rains[i] > 0){
//                 if(!lakesToDryIdx.empty() && lakesToDryIdx.count(rains[i])){
//                     cout << "F " << i <<endl;
//                     return {};
//                 }
//                 ans.push_back(-1);
//                 lakesToDryIdx.insert(rains[i]);
//             }
//             else if (rains[i] == 0 && lakesToDryIdx.empty()){
//                 ans.push_back(1);
//             }
//             else if(rains[i] == 0 && !lakesToDryIdx.empty()){
//                 int top = *prev(end(lakesToDryIdx));
//                 lakesToDryIdx.erase(lakesToDryIdx.find(top));
//                 cout << top << endl;
//                 ans.push_back(top);
//             }


//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> floodedLakes; // Tracks the last day a lake was filled
        multiset<int> dryDays; // Keeps track of indices of dry days
        vector<int> ans(rains.size(), -1); // Initialize ans with -1 for rainy days

        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] > 0) { // Rainy day
                int lake = rains[i];
                if (floodedLakes.count(lake)) {
                    // Check for a dry day to dry this lake
                    auto it = dryDays.lower_bound(floodedLakes[lake]);
                    if (it == dryDays.end()) {
                        cout << "F " << i << endl;
                        return {}; // No dry day available, flooding occurs
                    }
                    ans[*it] = lake; // Use this dry day to dry the lake
                    dryDays.erase(it); // Remove the dry day from the set
                }
                floodedLakes[lake] = i; // Update the last filled day for this lake
            } else { // Dry day
                dryDays.insert(i); // Record the index of the dry day
                ans[i] = 1; // Default value for dry days
            }
        }
        return ans;
    }
};
