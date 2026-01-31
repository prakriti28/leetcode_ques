class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {

        unordered_map<int, Employee*> mp;
        for (auto e : employees) {
            mp[e->id] = e;
        }

        queue<int> q;
        q.push(id);

        int res = 0;

        while (!q.empty()) {
            int currId = q.front();
            q.pop();

            Employee* emp = mp[currId];
            res += emp->importance;

            for (int sub : emp->subordinates) {
                q.push(sub);
            }
        }

        return res;
    }
};
