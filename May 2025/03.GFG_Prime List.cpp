class Solution {
  public:
    // Sieve to generate primes up to MAX
    const int MAX = 100050;
    vector<bool> is_prime;

    Solution() {
        is_prime.resize(MAX, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i < MAX; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j < MAX; j += i)
                    is_prime[j] = false;
            }
        }
    }

    int nearestPrime(int num) {
        if (is_prime[num]) return num;

        int i = 1;
        while (true) {
            if (num - i >= 2 && is_prime[num - i]) return num - i;
            if (num + i < MAX && is_prime[num + i]) return num + i;
            i++;
        }
    }

    Node* primeList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            temp->val = nearestPrime(temp->val);
            temp = temp->next;
        }
        return head;
    }
};
