class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {


        sort(trainers.begin(), trainers.end());
        sort(players.begin(),players.end());

        int n=players.size();
        int m=trainers.size();

        int i=0;
        int j=0;

        int cnt=0;

        while(i<n and j<m){
            if(players[i]<=trainers[j]){
                cnt++;
                i++;
                j++;
            }
            else if(players[i]>trainers[j]){
                j++;
            }
        }




        return cnt;
    }
};