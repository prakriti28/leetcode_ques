class Solution {
public:
    long long calculateScore(vector<string>& instructions,
                             vector<int>& values) {
        int index = 0;
        long long score = 0;
        vector<int> visited(values.size(), -1);
        while (index >= 0 and index < values.size()) {
            if (visited[index] >=1 or index >= values.size())
                return score;
                visited[index]=1;
            if (instructions[index] == "jump") {
                index = index + values[index];

            } else if (instructions[index] == "add") {
                score += 1ll*values[index];
                index++;
            }
        }

        return score;
    }
};