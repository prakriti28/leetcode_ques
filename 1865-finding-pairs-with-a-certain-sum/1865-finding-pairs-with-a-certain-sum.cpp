class FindSumPairs {
public:
    vector<int> arr1;
    vector<int> arr2;
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->arr1 = nums1;
        this->arr2 = nums2;
        for (auto ar1 : nums1) {
            mp1[ar1]++;
        }

        for (auto ar2 : nums2) {
            mp2[ar2]++;
        }
    }

    void add(int index, int val) {

        int oldVal = arr2[index];
        mp2[oldVal]--;
        if (mp2[oldVal] == 0)
            mp2.erase(oldVal);

        arr2[index] += val;
        mp2[arr2[index]]++;
    }

    int count(int tot) {
        long long cnt = 0;

        for (auto& it : mp1) {
            int elem = tot - it.first;

            if (mp2.find(elem) != mp2.end()) {
              cnt += 1LL * it.second * mp2[elem];
            }
        }

        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */