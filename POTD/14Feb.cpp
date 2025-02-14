#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> prefix;
    int size;
    ProductOfNumbers() {
        prefix = {1};
        size = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            prefix = {1};
            size = 0;
        } else {
            prefix.push_back(prefix[size] * num);
            size++;
        }

        cout << num << " is successfully added to the data stream" << endl;
    }
    
    int getProduct(int k) {
        if (k > size) return 0;

        return prefix[size] / prefix[size - k];
    }
};

int main()
{
    ProductOfNumbers pn;
    pn.add(3);
    pn.add(0);
    pn.add(2);
    pn.add(5);
    pn.add(4);
    cout << pn.getProduct(2) << endl;
    cout << pn.getProduct(3) << endl;
    cout << pn.getProduct(4) << endl;
    pn.add(8);
    cout << pn.getProduct(2) << endl;
    return 0;
}