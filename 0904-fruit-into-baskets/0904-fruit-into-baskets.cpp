class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() == 1)
            return 1;
        int i = 0;
        int j = 0;
        int n = fruits.size();
        unordered_map<int, int> mp;
        int maxFruits = INT_MIN;

        while (j < n) {
            mp[fruits[j]]++;

            if (mp.size() > 2) {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            maxFruits = max(j-i+1,maxFruits);

            j++;
        }
        return maxFruits;
    }
};