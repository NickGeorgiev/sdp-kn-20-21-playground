#include <stack>
#include <vector>
#include <queue>
#include <iostream>
#include <exception>
#include <string>
#include <iomanip>

template <class T>
struct TreeNode
{
    T val;
    std::vector<TreeNode *> children;
};
template <class T>
struct TreeThree
{
    T val;
    TreeThree *left;
    TreeThree *mid;
    TreeThree *right;
};
template <class T>
struct BinNode
{
    T val;
    BinNode *left;
    BinNode *right;
};
template <class T>
TreeNode<T> *createTree(unsigned int n)
{
    TreeNode<T> *root = new TreeNode<T>;
    root->val = n;
    if (n <= 4)
    {
        return root;
    }
    root->children.push_back(createTree<T>(n - 1));
    root->children.push_back(createTree<T>(n / 2));
    root->children.push_back(createTree<T>(n / 3));
    return root;
}
template <class T>
void dfs(TreeNode<T> *root)
{
    if (!root)
    {
        return;
    }
    std::stack<TreeNode<T> *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode<T> *cur = s.top();
        s.pop();
        for (TreeNode<T> *el : cur->children)
        {
            s.push(el);
        }
        std::cout << cur->val << " ";
    }
}
template <class T>
void printLeaves(TreeNode<T> *root)
{
    if (!root)
    {
        return;
    }
    std::stack<TreeNode<T> *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode<T> *cur = s.top();
        s.pop();
        if (cur->children.empty())
        {
            std::cout << cur->val << " ";
        }
        else
        {
            for (TreeNode<T> *el : cur->children)
            {
                s.push(el);
            }
        }
    }
}
template <class T>
void add(TreeThree<T> *&root, int data, double r)
{
    if (!root)
    {
        root = new TreeThree<T>{data};
        return;
    }
    else
    {
        if (data * (1 - r) < root->val)
        {
            add(root->left, data, r);
        }
        else if (data * (1 - r) > root->val && data * (1 + r) < root->val)
        {
            add(root->mid, data, r);
        }
        else
        {
            add(root->right, data, r);
        }
    }
}
template <class T>
void bfs3(TreeThree<T> *root)
{
    if (!root)
    {
        return;
    }
    std::queue<TreeThree<T> *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        TreeThree<T> *cur = q.front();
        q.pop();
        if (!cur)
        {
            std::cout << "\n";
            if (!q.empty())
            {
                q.push(cur);
            }
        }
        else
        {
            std::cout << cur->val << " ";
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->mid)
            {
                q.push(cur->mid);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }
    }
}
template <class T>
void bfs2(BinNode<T> *root)
{
    std::cout << " ";
    if (!root)
    {
        return;
    }
    std::queue<BinNode<T> *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        BinNode<T> *cur = q.front();
        q.pop();
        if (!cur)
        {
            std::cout << "\n";
            if (!q.empty())
            {
                q.push(cur);
            }
        }
        else
        {
            std::cout << cur->val << " ";
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }
    }
}
template <class T>
void addBinRoad(const char *route, BinNode<T> *&root, char c)
{
    if (!root && route[0] == 0)
    {
        root = new BinNode<T>{c};
        return;
    }
    if (!root && route[0] != 0)
    {
        std::invalid_argument("Error road");
    }
    if (root && route[0] == 0)
    {
        root->val = c;
        return;
    }
    if (route[0] == 'L')
    {
        addBinRoad(route + 1, root->left, c);
    }
    else if (route[0] == 'R')
    {
        addBinRoad(route + 1, root->right, c);
    }
    else
    {
        std::invalid_argument("Error symbol");
    }
}
std::vector<std::string> levelWords(BinNode<char> *root)
{
    std::string temp;
    std::vector<std::string> result;
    if (!root)
    {
        return result;
    }
    std::queue<BinNode<char> *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        BinNode<char> *cur = q.front();
        q.pop();
        if (!cur)
        {
            result.push_back(temp);
            if (!q.empty())
            {
                q.push(cur);
            }
            temp = "";
        }
        else
        {
            temp.push_back(cur->val);
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }
    }
    return result;
}
void deepWords(BinNode<char> *root, std::vector<std::string> &result, std::string word)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        word.push_back(root->val);
        result.push_back(word);
        return;
    }
    word.push_back(root->val);
    deepWords(root->left, result, word);
    deepWords(root->right, result, word);
    word.pop_back();
}
void print(const std::vector<std::string> &result)
{
    for (auto &&w : result)
    {
        std::cout << w << " ";
    }
    std::cout << std::endl;
}
template <class T>
struct TN
{
    T val;
    TN *left;
    TN *right;
};
template <class T>
void addTN(TN<T> *&root, T data)
{

    if (!root)
    {
        root = new TN<T>{data, nullptr, nullptr};

        return;
    }
    if (data < root->val)
    {
        addTN(root->left, data);
    }
    else if (data > root->val)
    {
        addTN(root->right, data);
    }
}
template <class T>
void print90Deg(TN<T> *root, int n)
{
    if (!root)
    {
        return;
    }
    n += 5;
    print90Deg(root->right, n);
    std::cout << std::setw(n) << root->val << "\n";
    print90Deg(root->left, n);
}
template <class T>
void print90Deg(BinNode<T> *root, int n)
{
    if (!root)
    {
        return;
    }
    n += 5;
    print90Deg(root->right, n);
    std::cout << std::setw(n) << root->val << "\n";
    print90Deg(root->left, n);
}
template <class T>
std::vector<T> listLeaves(TN<T> *root)
{
    std::queue<TN<T> *> q;
    std::vector<T> elem;
    q.push(root);
    while (!q.empty())
    {
        TN<T> *current = q.front();
        q.pop();
        if (!current->left && !current->right)
        {
            elem.push_back(current->val);
        }
        if (current->left)
        {
            q.push(current->left);
        }

        if (current->right)
        {
            q.push(current->right);
        }
    }
    return elem;
}
template <class T>
bool member(TN<T> *&root, const T &data, std::string &trace)
{
    if (!root)
    {
        return false;
    }
    if (root->val == data)
    {
        return true;
    }
    if (member(root->left, data, trace))
    {
        trace.push_back('L');
        return true;
    }

    if (member(root->right, data, trace))
    {
        trace.push_back('R');
        return true;
    }
    if (!trace.empty())
    {
        trace.pop_back();
    }
    return false;
}
template <class T>
std::string findTrace(TN<T> *&root, const T &data)
{
    std::string result = "";
    if (member(root, data, result))
    {
        return result;
    }

    return "NO";
}
template <class T>
T getAt(TN<T> *&root, size_t i)
{
    int count = 0;
    if (count == i)
    {
        return root->val;
    };
    std::queue<TN<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        TN<T> *current = q.front();
        q.pop();
        if (count == i)
        {
            return current->val;
        }
        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
        ++count;
    }

    std::invalid_argument("Error index");
}
template <class T>
void dfsT(TN<T> *root)
{
    if (!root)
    {
        return;
    }
    dfsT(root->right);
    dfsT(root->left);
    std::cout << root->val << " ";
}
template <class T>
void bfsT(TN<T> *root)
{
    if (!root)
    {
        return;
    }
    std::queue<TN<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        TN<T> *current = q.front();
        q.pop();
        std::cout << current->val << std::endl;
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
template <class T>
void DfsTS(TN<T> *root)
{
    if (!root)
    {
        return;
    }
    std::stack<TN<T> *> s;
    s.push(root);
    while (!s.empty())
    {
        TN<T> *current = s.top();
        s.pop();
        std::cout << current->val << std::endl;
        if (current->right)
        {
            s.push(current->right);
        }
        if (current->left)
        {
            s.push(current->left);
        }
    }
}
template <class T>
bool MirrorHelper(BinNode<T> *left, BinNode<T> *right)
{
    if (!left && !right)
    {
        return true;
    }
    if (left && !right)
    {
        return false;
    }
    if (!left && right)
    {
        return false;
    }
    if (left->val != right->val)
    {
        return false;
    }
    return MirrorHelper(left->left, right->right) && MirrorHelper(left->right, right->left);
}
template <class T>
bool isMirrorredTree(BinNode<T> *root)
{
    if (!root)
    {
        return true;
    }
    return MirrorHelper(root->left, root->right);
}
template <class T>
void helper(BinNode<T> *t, std::string &str)
{
    if (!t)
    {
        return;
    }
    str += (t->val);
    if (t->left)
    {
        str += '(';
        helper(t->left, str);
        str += ')';
    }
    if (t->right)
    {
        if (!t->left)
        {
            str += "()";
        }
        str += '(';
        helper(t->right, str);
        str += ')';
    }
}
template <class T>
std::string tree2str(BinNode<T> *t)
{
    std::string s = "";
    helper(t, s);
    return s;
}
template <class T>
std::vector<std::vector<T>> levelOrder(BinNode<T> *root)
{
    if (!root)
    {
        return {{}};
    }
    std::vector<std::vector<T>> result;
    std::queue<BinNode<T> *> q;
    q.push(root);
    q.push(nullptr);

    int i = 0;
    std::vector<T> temp;
    while (!q.empty())
    {
        BinNode<T> *cur = q.front();
        q.pop();
        if (!cur)
        {
            if (!q.empty())
            {
                q.push(cur);
                ++i;
            }
            result.push_back(temp);
            temp.clear();
        }
        else
        {
            temp.push_back(cur->val);
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }
    }
    return result;
}
template <class T>
int sumOfEvenRowsWithLeftNode(BinNode<T> *root)
{
    if (!root || (!root->left && !root->right))
    {
        return 0;
    }
    int row = 0;
    int sum = 0;
    std::queue<BinNode<T> *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        BinNode<T> *current = q.front();
        q.pop();
        if (!current)
        {
            if (!q.empty())
            {
                ++row;
                q.push(current);
            }
        }
        else
        {
            if (row % 2 == 0 && current->left && !current->right)
            {
                sum += current->val;
            }
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
int main()
{
    BinNode<char> *t = new BinNode<char>{'1', nullptr, nullptr};
    // addBinRoad("L", t, 'b');
    // addBinRoad("R", t, 'b');
    // addBinRoad("LL", t, 'c');
    // addBinRoad("RR", t, 'c');
    // addBinRoad("LR", t, 'd');
    // addBinRoad("RL", t, 'd');
    // addBinRoad("LLL", t, 'e');
    // addBinRoad("RRR", t, 'e');
    // addBinRoad("LLLR", t, 'f');
    // addBinRoad("RRRL", t, 'f');

    addBinRoad("L", t, '2');
    addBinRoad("LL", t, '4');
    addBinRoad("R", t, '3');
    // print90Deg(t, 0);

    // std::cout << std::boolalpha << isMirrorredTree(t);
    // std::cout << tree2str(t);
    std::vector<std::vector<char>> v;
    v = levelOrder(t);
    for (auto &&vec : v)
    {
        for (auto &&el : vec)
        {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }

    //bfs2(t);
    //std::vector<std::string> words = levelWords(t);
    // std::vector<std::string> words = {};
    // deepWords(t, words, "");
    // print(words);
    // TreeThree<int> *t = new TreeThree<int>{12, nullptr, nullptr};
    // add(t, 5, 0.5);
    // add(t, 78, 0.5);
    // add(t, 5, 0.5);
    // add(t, 2, 0.5);
    // add(t, 0, 0.5);
    // add(t, 95, 0.5);
    // add(t, 1, 0.5);
    // add(t, 3, 0.5);
    // add(t, 78, 0.5);
    // bfs3(t);
    //  delete t;
    //TreeNode<int> *t = createTree<int>(10);
    //dfs(t);
    //printLeaves(t);
    // TN<int> *t = new TN<int>{9};
    // addTN(t, 5);
    // addTN(t, 1);
    // addTN(t, 10);
    // addTN(t, 8);
    // addTN(t, 15);
    // addTN(t, 0);
    // addTN(t, 95);
    // addTN(t, 1);
    // addTN(t, 3);
    // addTN(t, 78);
    //     print90Deg(t, 0);
    //     std::cout << "\n";
    //     std::vector<int> l = listLeaves(t);
    //     for (auto &&el : l)
    //     {
    //         std::cout << el << " ";
    //     }
    //     std::cout << "\n"
    //               << findTrace(t, 8) << "\n";
    //     std::cout << getAt(t, 2);
}