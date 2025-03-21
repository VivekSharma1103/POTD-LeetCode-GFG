class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        queue<string> q;
        vector<string> result;

        // Initialize in-degree map for all recipes
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size(); // Number of required ingredients
            for (string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]); // Add edge from ingredient to recipe
            }
        }

        // Add initial supplies to the queue
        for (string& supply : supplies) {
            q.push(supply);
        }

        // BFS to reduce in-degrees and create recipes
        while (!q.empty()) {
            string item = q.front();
            q.pop();

            if (indegree.count(item)) { // If the item is a recipe
                result.push_back(item);
            }

            // Update dependent recipes
            for (string& recipe : graph[item]) {
                indegree[recipe]--;
                if (indegree[recipe] == 0) { // If all ingredients are available
                    q.push(recipe);
                }
            }
        }

        return result;
    }
};
