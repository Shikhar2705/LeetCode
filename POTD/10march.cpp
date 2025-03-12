#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private: 
    bool isVowel(char c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }

    long long atLeastK(string word, int k) {
        long long count = 0;
        int start = 0, end = 0;

        unordered_map<char, int> vowel;
        int consonant = 0;

        while (end < word.length()) {
            char newLetter = word[end];

            if (isVowel(newLetter)) {
                vowel[newLetter]++;
            } else {
                consonant++;
            }

            while (vowel.size() == 5 && consonant >= k) {
                count += word.length() - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    if (--vowel[startLetter] == 0) 
                        vowel.erase(startLetter);
                } else {
                    consonant--;
                }
                start++;
            }
            end++;
        }

        return count;
    }
public:
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word,k) - atLeastK(word,k+1);
    }
};

int main()
{
    string word = "ieaouqqieaouqq";
    int k = 1;
    Solution sol;

    cout << sol.countOfSubstrings(word, k);
    
    return 0;
}