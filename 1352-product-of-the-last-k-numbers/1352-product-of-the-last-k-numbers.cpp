class ProductOfNumbers {
public:
    vector<int>Prefix;
    ProductOfNumbers() {
        Prefix.clear();
        Prefix.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            Prefix.clear();
            Prefix.push_back(1);
            return;
        }
        Prefix.push_back(num*Prefix.back());
    }
    
    int getProduct(int k) {
        int n=Prefix.size();
        if(k>=n) return 0;
        //else if(k==n) return Prefix[n-1];
        return Prefix[n-1]/Prefix[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */