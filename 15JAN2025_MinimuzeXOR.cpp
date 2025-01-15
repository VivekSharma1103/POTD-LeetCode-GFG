class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while (n) {
            if (n & 1) count++;
            n = n >> 1;
        }
        return count;
    }
    
    int minimizeXor(int num1, int num2) {
        int setbits = countBits(num2);
        int targetbits = countBits(num1);
        int x = num1;
        
        if (setbits == targetbits) return x; // No changes needed
        
        else if (targetbits < setbits) { // Add set bits
            int i = 0;
            while (setbits != targetbits) {
                if ((x & (1 << i)) == 0) { // If bit i is 0, flip it to 1
                    x ^= (1 << i);
                    setbits--; // Decrement the remaining bits to set
                }
                i++;
            }
            return x;
        }
        
        else { // Remove set bits
            int i = 0;
            while (setbits != targetbits) {
                if (x & (1 << i)) { // If bit i is 1, flip it to 0
                    x ^= (1 << i);
                    targetbits--; // Decrement the number of set bits in x
                }
                i++;
            }
            return x;
        }
    }
};
