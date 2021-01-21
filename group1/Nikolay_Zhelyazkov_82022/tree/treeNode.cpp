#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isTreeHasOne(TreeNode *root)
    {
        if (!root)
        {
            return false;
        }
        if (!root->left && !root->right && root->val != 1)
        {
            return false;
        }
        if (root->val == 1)
        {
            return true;
        }
        return isTreeHasOne(root->left) || isTreeHasOne(root->right);
    }
    void erase(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        if (!isTreeHasOne(root->right))
        {
            delete root->right;
            root->right = nullptr;
        }
        if (!isTreeHasOne(root->left))
        {
            delete root->left;
            root->left = nullptr;
        }
        erase(root->right);
        erase(root->left);
    }
    TreeNode *pruneTree(TreeNode *root)
    {
        if (!root)
        {
            return nullptr;
        }
        erase(root);
        return root;
    }
};

// void check(TreeNode *r, vector<int> &v, int level, int &max)
// {
//     if (!r)
//     {
//         return;
//     }
//     if (max < level)
//     {
//         v.push_back(r->val);
//         max = level;
//     }
//     check(r->right, v, level + 1, max);
//     check(r->left, v, level + 1, max);
// }
// vector<int> rightSideView(TreeNode *root)
// {
//     vector<int> v;
//     int max = 0;
//     if (!root)
//     {
//         return v;
//     }
//     check(root, v, 1, max);
//     return v;
// }

// void Tree::BFS(Tree::Node *root) const
// {
//     std::queue<Tree::Node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         Tree::Node *cur = q.front();
//         q.pop();
//         std::cout << cur->data << " -> ";
//         if (!cur->left && !cur->right)
//         {
//             continue;
//         }

//         q.push(cur->left);
//         q.push(cur->right);
//     }
// }