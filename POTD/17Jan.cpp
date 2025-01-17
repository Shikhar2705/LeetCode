#include<iostream> 
#include<vector>
using namespace std;

bool doesValidArrayExist(vector<int>& derived) {
    int Xor = derived[0];

    for (int i = 1; i < derived.size(); i++) {
        Xor ^= derived[i];
    }

    return Xor == 0;
}

int main() {

    vector<int> derived1 = {1,1,0};
    vector<int> derived2 = {1,0};

    if (doesValidArrayExist(derived1)) {
        cout << "Valid Array Exists" << endl;
    } else {
        cout << "Valid Array Does Not Exist" << endl;
    }

    if (doesValidArrayExist(derived2)) {
        cout << "Valid Array Exists" << endl;
    } else {
        cout << "Valid Array Does Not Exist" << endl;
    }
    
    return 0;
}