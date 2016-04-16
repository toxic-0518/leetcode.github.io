class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        vector<int> mask(words.size());
        for(int i = 0; i < words.size(); i++) {
            for(char c : words[i]) {
                mask[i] |= 1 << c - 'a' ;
            }
        }
        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if((mask[i] & mask[j]) != 0) continue;
                result = max(result, (int)(words[i].size() * words[j].size()));
            }
        }
        return result;
    }
};
