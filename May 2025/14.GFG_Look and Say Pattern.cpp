class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string current = "1";

        for (int i = 2; i <= n; ++i) {
            string next = "";
            int len = current.length();
            int j = 0;

            while (j < len) {
                char digit = current[j];
                int count = 1;

                // Count consecutive same digits
                while (j + 1 < len && current[j + 1] == digit) {
                    j++;
                    count++;
                }

                next += to_string(count) + digit;
                j++;
            }

            current = next;
        }

        return current;
    }
};
