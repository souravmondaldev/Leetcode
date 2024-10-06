class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        istringstream stream1(sentence1), stream2(sentence2);
        deque<string> queue1((istream_iterator<string>(stream1)), istream_iterator<string>());
        deque<string> queue2((istream_iterator<string>(stream2)), istream_iterator<string>());
        while(!queue1.empty() && !queue2.empty() && queue1.front() == queue2.front()){
            queue1.pop_front();
            queue2.pop_front();
        }
        while(!queue1.empty() && !queue2.empty() && queue1.back() == queue2.back()){
            queue1.pop_back();
            queue2.pop_back();
        }
        return queue1.empty() || queue2.empty();
    }
};