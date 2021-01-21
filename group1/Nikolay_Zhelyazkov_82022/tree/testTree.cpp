#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
struct Node
{
    int data;
    Node *left, *right;
};

int ascending(Node *&root, int sum, int prev)
{

    if (!root)
    {
        return sum;
    }

    if (root->data > prev)
    {
        return std::max(ascending(root->left, sum + root->data, root->data), ascending(root->right, sum + root->data, root->data));
    }
    else
    {
        return sum;
    }
}
int maxpath(Node *t)
{
    if (!t)
    {
        return 0;
    }
    return ascending(t, 0, INT_MIN);
}
std::vector<int> average(Node *root)
{
    if (!root)
    {
        return {};
    }
    std::queue<Node *> q;
    std::vector<int> res;
    q.push(root);
    q.push(nullptr);
    int count = 0;
    int sum = 0;
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        if (!current)
        {
            if (!q.empty())
            {
                q.push(current);
            }
            res.push_back((sum / count));
            sum = 0;
            count = 0;
        }
        else
        {
            sum += current->data;
            ++count;
            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }
    }
    return res;
}
void printVector(std::vector<int> &v)
{
    for (auto &&el : v)
    {
        std::cout << el << " ";
    }
}
struct CharNode
{
    char data;
    CharNode *left, *right;
};
void dfs(CharNode *root, std::string str, std::unordered_map<std::string, int> &m)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        str += root->data;
        if (!m.count(str))
        {
            m[str] = 1;
        }
        else
        {
            ++m[str];
        }
    }
    dfs(root->left, str += root->data, m);
    str.pop_back();
    dfs(root->right, str += root->data, m);
}
void bfs(CharNode *root, std::unordered_map<std::string, int> &m)
{
    if (!root)
    {
        return;
    }
    std::queue<CharNode *> q;
    std::string str;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        CharNode *current = q.front();
        q.pop();
        if (!current)
        {
            if (!q.empty())
            {
                q.push(current);
            }

            if (!m.count(str))
            {
                m[str] = 1;
            }
            else
            {
                ++m[str];
            }
            str = "";
        }
        else
        {
            str += current->data;
            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }
    }
}
std::string mostFrequent(CharNode *root)
{
    std::unordered_map<std::string, int> m;
    if (!root)
    {
        return "";
    }
    dfs(root, "", m);
    bfs(root, m);
    int max = 0;
    std::string res = "";
    for (auto &&el : m)
    {
        if (el.second > max)
        {
            max = el.second;
            res = el.first;
        }
    }
    return res;
}
int main()
{
    Node *root = new Node{1, new Node{2, new Node{3, nullptr, nullptr}, nullptr}, new Node{1, new Node{9, nullptr, nullptr}, new Node{8, nullptr, nullptr}}};
    //ex.1
    std::cout << maxpath(root) << "\n";
    //ex.2
    Node *r2 = new Node{1, new Node{2, nullptr, new Node{5, nullptr, nullptr}}, new Node{5, nullptr, nullptr}};
    std::vector<int> v = average(r2);
    printVector(v);
    //ex.3
    CharNode *r = new CharNode{'c', new CharNode{'a', new CharNode{'c', nullptr, nullptr}, nullptr}, new CharNode{'a', new CharNode{'a', nullptr, nullptr}, new CharNode{'c', nullptr, nullptr}}};
    std::cout << "\n";
    std::cout << mostFrequent(r);

    delete root;
    delete r2;
    delete r;
    return 0;
}