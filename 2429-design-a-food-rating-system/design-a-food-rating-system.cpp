class FoodRatings {
private:
    unordered_map<string, int> foodRatings;
    unordered_map<string, string> foodCuisines;
    unordered_map<string, set<pair<int, string>>> cuisineFoodRatings;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i ++){
            foodRatings[foods[i]] = ratings[i];
            foodCuisines[foods[i]] = cuisines[i];
            cuisineFoodRatings[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cuisineName = foodCuisines[food];
        auto oldElemenetIterator = cuisineFoodRatings[cuisineName].find({-foodRatings[food], food});
        cuisineFoodRatings[cuisineName].erase(oldElemenetIterator);

        foodRatings[food] = newRating;
        cuisineFoodRatings[cuisineName].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto higestRated = *cuisineFoodRatings[cuisine].begin();
        return higestRated.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */