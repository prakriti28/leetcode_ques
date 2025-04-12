class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> used(26, 0);
        vector<int> indegree(26, 0);
        int cnt=0;
        for (const string& word : words) {
            for (char c : word) {
                used[c - 'a'] = 1;
                
            }
        }
        for(auto it:used){
            if(it==1) cnt++;
        }

        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
             if (s1.size() > s2.size() &&
                s1.substr(0, s2.size()) == s2) {
                return "";
            }
            for (int j = 0; j < len; j++) {

                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    indegree[s2[j] - 'a']++;
                    break;
                }
            }
        }
        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 and used[i]) {
                q.push(i);
            }
        }
        string res;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node + 'a');

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

         cout<<cnt;
         return res.size() != cnt ? "" : res;
    }
};