class Solution {
public:
    string customSortString(string order, string s) {
        std::unordered_map<char, int> freqs;
        for (char ch : s)
            freqs[ch]++;

        std::string result;
        for (char ch : order) {
            result += std::string(freqs[ch], ch);
            freqs.erase(ch);
        }

        for (auto [ch, freq] : freqs)
            result += std::string(freq, ch);

        return result;
    }
};