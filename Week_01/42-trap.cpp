// NO42. Ω””ÍÀÆ
class Solution {
public:
    int trap(vector<int>& height) {
        height.insert(height.begin(), 0);
        height.insert(height.end(), 0);

        int result = 0;
        stack<int> stack;

        for(int i = 0; i < height.size(); ++i) {
            while(!stack.empty() && height[i] > height[stack.top()]) {
                int tmp = height[stack.top()];
                stack.pop();
                while(!stack.empty() && tmp == height[stack.top()])
                    stack.pop();

                if(!stack.empty())
                    result += (min(height[stack.top()], height[i]) - tmp) * (i - stack.top() - 1);
            }

            stack.push(i);
        }
        return result;
    }
};