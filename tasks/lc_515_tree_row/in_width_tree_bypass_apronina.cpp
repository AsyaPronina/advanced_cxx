#include <queue>
#include <limits>

class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }

        std::vector<int> result;

        std::queue<TreeNode*> bypass;
        bypass.push(root);

        TreeNode *current = root;
        int levelLimit = 1;
        int nextLevelLimit = 2;
        int count = 0;
        int maxValue = INT_MIN;

        do
        {
            current = bypass.front();
            maxValue = current->val > maxValue ? current->val : maxValue;

            bypass.pop();
            ++count;

            if (current->left != nullptr)
            {
                bypass.push(current->left);
            }
            else
            {
                --nextLevelLimit;
            }

            if (current->right != nullptr)
            {
                bypass.push(current->right);
            }
            else
            {
                --nextLevelLimit;
            }

            if (count == levelLimit)
            {
                count = 0;
                levelLimit = nextLevelLimit;
                nextLevelLimit = nextLevelLimit << 1;
                result.push_back(maxValue);
                maxValue = INT_MIN;
            }

        } while (!bypass.empty());

        return result;
    }
};

