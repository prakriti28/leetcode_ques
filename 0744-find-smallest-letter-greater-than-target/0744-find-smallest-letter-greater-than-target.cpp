class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        for (char ch : letters) {
            if(ch > target){
                res=ch;
                return res;
            }
        }
        return res;
    }
};