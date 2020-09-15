// ×éºÏ
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tmp;
        backtrack(n, k, tmp, result, 1);
        return result;
    }

    void backtrack(int n, int k, vector<int> &tmp, vector<vector<int>> &result, int index) {
        if(tmp.size() == k) {
            result.push_back(tmp);
            return;
        }

        for(int i = index; i <= n; ++i) {
            tmp.push_back(i);
            backtrack(n, k, tmp, result, i + 1);
            tmp.pop_back();
        }
    }
};