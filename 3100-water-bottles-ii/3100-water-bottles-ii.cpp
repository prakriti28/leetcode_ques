class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        int emptyBottles = numBottles;
        numBottles = 0;
        int fullBottles = 0;

        while (emptyBottles >= 0) {

            if (fullBottles > 0) {
                res += fullBottles;
                fullBottles--;
                emptyBottles++;

            } else {
                emptyBottles = emptyBottles - numExchange;
                numExchange++;
                fullBottles++;
            }
        }
        return res;
    }
};