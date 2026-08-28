class Solution {
private:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;
        for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor) {
            if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        
        for (int city = 0; city < n; ++city) {
            if (!visited[city]) {
                provinces++;
                dfs(city, isConnected, visited);
            }
        }
        
        return provinces;
    }
};
