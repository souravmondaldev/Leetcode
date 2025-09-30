class Solution {
public:
    bool solve(vector<double> &cards){
        if(cards.size() == 1){
            return abs(24 - cards[0]) < 0.01;
        }
        for(int i = 0; i < cards.size(); i ++){
            for(int j = i + 1; j < cards.size(); j ++){
                double a = cards[i], b = cards[j];
                vector<double> nextCards;
                for(int k = 0; k < cards.size(); k ++){
                    if(k != i && k != j){
                        nextCards.push_back(cards[k]);
                    }
                }
                vector<double> results = {a+ b, a - b, b - a, a* b};
                if(a) results.push_back(b/a);
                if(b) results.push_back(a/b);
                for(double result: results){
                    nextCards.push_back(result);
                    if(solve(nextCards))
                        return true;
                    nextCards.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> doubleCards;
        for(int card : cards){
            doubleCards.push_back((double) card);
        }
        return solve(doubleCards);
    }
};