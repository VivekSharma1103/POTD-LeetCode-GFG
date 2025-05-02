class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n, 0);

        // Step 1: Apply forces from 'R'
        int force = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                force = n;  // maximum force
            } else if (dominoes[i] == 'L') {
                force = 0;  // blocked by 'L'
            } else {
                force = max(force - 1, 0);
            }
            forces[i] += force;
        }

        // Step 2: Apply forces from 'L'
        force = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                force = n;
            } else if (dominoes[i] == 'R') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            forces[i] -= force;  // subtract because left forces are negative
        }

        // Step 3: Compute result
        string result;
        for (int f : forces) {
            if (f > 0) result += 'R';
            else if (f < 0) result += 'L';
            else result += '.';
        }

        return result;
    }
};
