class Solution {

public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string hex = "";
        string hexDigits = "0123456789ABCDEF";
        while (num > 0) {
            hex = hexDigits[num % 16] + hex;
            num /= 16;
        }
        return hex;
    }
    string toHexa(int num) {
        if (num == 0)
            return "0";
        string hex = "";
        string hexDigits= "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        while (num > 0) {
            hex = hexDigits[num % 36] + hex;
            num /= 36;
        }
        return hex;
    }

    string concatHex36(int n) {

        long long int sq = pow(n, 2);
        long long int cube = pow(n, 3);
        string s1 = "";
        string s2;
        bool flag = false;

        for (int i = 10; i >= 0; i--) {
            long long int temp = pow(16, i);

            if ((sq / temp) > 0)
                flag = true;
            if (flag) {

                // s1.concat(toHex(sq / temp));
                s1+=toHex(sq/temp);
            }
            sq = sq % temp;
        }
        bool flag2 = false;
        for (int i = 10; i >= 0; i--) {
            long long int temp = pow(36, i);
            if ((cube / temp) > 0)
                flag2 = true;
            if (flag2) {

                // s2.concat(toHexa(cube / temp));
                s2+=toHexa(cube/temp);
            }

            cube = cube % temp;
        }

        return s1+s2;
    }
};