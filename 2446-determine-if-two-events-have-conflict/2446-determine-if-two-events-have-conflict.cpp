class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string event1start = event1[0], event1end = event1[1],
               event2start = event2[0], event2end = event2[1];

        if (event2start >= event1start and event2start <= event1end) {
            return true;
        } else if (event2start <= event1start and event2end >= event1start) {
            return true;
        }

        return false;
    }
};