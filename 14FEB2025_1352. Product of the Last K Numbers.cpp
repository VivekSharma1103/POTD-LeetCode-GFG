class ProductOfNumbers {
public:
    vector<int> prefixProd;
    
    ProductOfNumbers() {
        prefixProd.push_back(1);  // Sentinel value to simplify calculations
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProd.clear();
            prefixProd.push_back(1);  // Reset on zero
        } else {
            prefixProd.push_back(prefixProd.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= prefixProd.size()) return 0;  // If k exceeds valid range, zero must have been encountered
        return prefixProd.back() / prefixProd[prefixProd.size() - k - 1];
    }
};
