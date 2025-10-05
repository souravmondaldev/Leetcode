#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    multiset<int> minHalf; // lower half (max side)
    multiset<int> maxHalf; // upper half (min side)
    int windowSize;

    // void add(int value) {
    //     // if minHalf empty, just add
    //     if (minHalf.empty()) {
    //         minHalf.insert(value);
    //         return;
    //     }

    //     int currentMedian = *minHalf.rbegin(); // largest in lower half

    //     if (value >= currentMedian)
    //     {
    //         maxHalf.insert(value);
    //         // rebalance if needed
    //         if ((int)maxHalf.size() > windowSize / 2)
    //         {
    //             minHalf.insert(*maxHalf.begin());
    //             maxHalf.erase(maxHalf.find(*maxHalf.begin()));
    //         }
    //     }
    //     else
    //     {
    //         minHalf.insert(value);
    //         if ((int)minHalf.size() > (windowSize + 1) / 2)
    //         {
    //             maxHalf.insert(*minHalf.rbegin());
    //             minHalf.erase(*minHalf.rbegin());
    //         }
    //     }
    // }

    void rebalance() {
        // Ensure size condition: |minHalf| >= |maxHalf| and diff <= 1
        while ((int)minHalf.size() > (windowSize + 1) / 2) {
            maxHalf.insert(*prev(minHalf.end()));
            minHalf.erase(prev(minHalf.end()));
        }
        while ((int)minHalf.size() < (windowSize + 1) / 2 && !maxHalf.empty()) {
            minHalf.insert(*maxHalf.begin());
            maxHalf.erase(maxHalf.begin());
        }
    }

    void add(int value) {
        if (minHalf.empty() || value <= *minHalf.rbegin())
            minHalf.insert(value);
        else
            maxHalf.insert(value);

        rebalance();
    }
    void remove(int value) {
        if (minHalf.find(value) != minHalf.end())
            minHalf.erase(minHalf.find(value));
        else
            maxHalf.erase(maxHalf.find(value));

        rebalance();
    }

    double getMedian() {
        if (windowSize % 2 == 1)
            return (double) *minHalf.rbegin();
        else
            return ((double)*minHalf.rbegin() + *maxHalf.begin()) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        windowSize = k;
        vector<double> medians;

        minHalf.clear();
        maxHalf.clear();

        // Initialize window
        // minHalf.insert(nums[0]);
        for (int i = 0; i < k; i++)
            add(nums[i]);

        medians.push_back(getMedian());

        for (int i = k; i < nums.size(); i++)
        {
            remove(nums[i - k]);
            add(nums[i]);
            medians.push_back(getMedian());
        }

        return medians;
    }
};
