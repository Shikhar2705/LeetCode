#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void addSpace(string &result, int maxWidth, int isLast) {
      if (result.size() == maxWidth)
        return ;

      int spaceCount = 0;

      for (int i = 0; i < result.size(); i++) {
        if (result[i] == ' ')
          spaceCount++;
      }

      int spaceNeeded = maxWidth - result.size();

      if (spaceCount == 0 || isLast == 1) {
        result.insert(result.length(), spaceNeeded, ' ');
        return ;
      }
        
      int eachSlot = spaceNeeded / spaceCount;

      int leftSlot = spaceNeeded % spaceCount;

      for (int i = 0; i < result.size(); i++) {
        if (result[i] == ' ' && (eachSlot > 0 || leftSlot > 0)) {
          int spaces = eachSlot + ((leftSlot--) > 0 ? 1 : 0);
          result.insert(i,spaces,' ');
          i += spaces;
        }
      }

      return ;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;

        string curr = words[0];

        for (int i = 1; i < words.size(); i++) {
          if (curr.length() + words[i].length() < maxWidth) {
            curr = curr + " " + words[i];
          }
          else {
            addSpace(curr, maxWidth,0);
            result.push_back(curr);
            curr = words[i];
          }
        }

        addSpace(curr, maxWidth, 1);
        result.push_back(curr);

        return result;
    }
};

int main()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};

    int maxWidth = 16;

    Solution sol;

    vector<string> justifiedText = sol.fullJustify(words, maxWidth); 

    for (int i = 0; i < justifiedText.size(); i++) {
        cout << justifiedText[i] << endl;
    }
    return 0;
}