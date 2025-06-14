class Solution {
public:
    int minMaxDifference(int num) {

        // int num=9;
        int number = num;
        int a,b;

        while (number > 0) {
            int rem = number % 10;
            if ( rem!=9) {
                a=rem;
            }
            if(rem!=0){
                b=rem;
            }
            number = number / 10;
        }
        cout<<a<<b<<endl;

        int mx = 0;
        int cnt = 0;
        number = num;
        while (number > 0) {
            int rem = number % 10;
            if (rem == a) {
                rem = 9;
            }
            mx += rem * pow(10, cnt);
            cnt++;
            number = number / 10;
        }


        number=num;

        int mn = 0;
        int cnt2 = 0;
        while (number > 0) {
            int rem = number % 10;
            if (rem == b) {
                rem = 0;
            }
            mn += rem * pow(10, cnt2);
            cnt2++;
            number = number / 10;
        }


        return mx-mn;
    }
};