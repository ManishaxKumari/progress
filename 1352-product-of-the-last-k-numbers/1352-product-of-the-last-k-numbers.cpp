class ProductOfNumbers {
public:
    vector<int>arr;
    //vector<int>suffix;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        arr.push_back(num);
        // int n=arr.size();
        // suffix.resize(n);
        // suffix[n-1]=arr[n-1];
        // for(int i=n-2;i>=0;i--){
        //     suffix[i]=suffix[i+1]*arr[i];
        // }
    }
    
    int getProduct(int k) {
        int n=arr.size();
        int product=1;
        for(int i=n-k;i<n;i++){
            product*=arr[i];
        }
        return product;
        //return suffix[arr.size()-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */