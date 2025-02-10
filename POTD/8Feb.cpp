#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class NumberContainers {
    public:
        unordered_map<int, int> indexMap;
        unordered_map<int, set<int>> smallestIndex;
        NumberContainers() {}
        
        void change(int index, int number) {
            if (indexMap.find(index) != indexMap.end()) {
                int prev = indexMap[index];
                smallestIndex[prev].erase(index);
    
                if (smallestIndex[prev].empty()) {
                    smallestIndex.erase(prev);
                }
            }
            indexMap[index] = number;
            smallestIndex[number].insert(index);
        }
        
        int find(int number) {
            if (smallestIndex.find(number) == smallestIndex.end()) return -1;
    
            return *smallestIndex[number].begin();
        }
    };

int main()
{
    NumberContainers nc;
    cout << nc.find(10) << endl;
    nc.change(2, 10);
    nc.change(1,10);
    nc.change(3,10);
    nc.change(5,10);
    cout << nc.find(10) << endl;
    nc.change(1,20);
    cout << nc.find(10) << endl;
    
    return 0;
}