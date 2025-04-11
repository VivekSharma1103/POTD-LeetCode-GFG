class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int num = low; num <= high; num++) {
            if (num >= 10 && num <= 99) {
                if (num % 11 == 0) count++; // 2-digit symmetric numbers
            }
            else if (num >= 1000 && num <= 9999) {
                int d1 = num / 1000;
                int d2 = (num / 100) % 10;
                int d3 = (num / 10) % 10;
                int d4 = num % 10;

                if (d1 + d2 == d3 + d4) count++; // 4-digit symmetric numbers
            }
        }

        return count;
    }
};
