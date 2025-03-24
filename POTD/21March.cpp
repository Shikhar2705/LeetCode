#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> inDegree;
        set<string> available(supplies.begin(), supplies.end());

        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = 0; 
        }

        for (int i = 0; i < recipes.size(); i++) {
            for (string& ingredient : ingredients[i]) {
                if (!available.count(ingredient)) { 
                    graph[ingredient].push_back(recipes[i]); 
                    inDegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        
        for (const string& recipe : recipes) {
            if (inDegree[recipe] == 0) q.push(recipe);
        }

        vector<string> ans;

        while (!q.empty()) {
            string recipe = q.front();
            q.pop();
            ans.push_back(recipe);

            for (const string& dependentRecipe : graph[recipe]) {
                if (--inDegree[dependentRecipe] == 0) {
                    q.push(dependentRecipe);
                }
            }
        }

        return ans;
    }
};
    

int main()
{
    Solution solution;
    vector<string> recipes = {"bread", "sandwich", "burger"};
    vector<vector<string>> ingredients = {{"flour", "water"}, {"bread", "ham"}, {"bread", "meat"}};
    vector<string> supplies = {"flour", "water", "ham", "meat"};

    vector<string> result = solution.findAllRecipes(recipes, ingredients, supplies);

    cout << "Recipes that can be prepared: ";
    for (const string& recipe : result) {
        cout << recipe << " ";
    }
    cout << endl;
    return 0;
}