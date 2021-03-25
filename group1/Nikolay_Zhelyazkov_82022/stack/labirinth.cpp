#include <iostream>
#include <stack>
const int labSize = 8;
int lab[labSize][labSize] = {
    0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    1, 1, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    1, 0, 1, 0, 1, 0, 0, 0,
    0, 0, 1, 0, 1, 0, 0, 0,
    0, 0, 1, 0, 1, 0, 0, 0,
    0, 0, 1, 0, 1, 0, 0, 0};
struct position
{
    int x, y;
    position up() { return position{x, y - 1}; }
    position down() { return position{x, y + 1}; }
    position left() { return position{x - 1, y}; }
    position right() { return position{x + 1, y}; }

    bool operator==(const position &other)
    {
        return x == other.x && y == other.y;
    }
    bool operator!=(const position &other)
    {
        return x != other.x || y != other.y;
    }
};

bool ok(position p)
{
    return p.x >= 0 &&
     p.x < labSize &&
      p.y < labSize &&
       p.y >= 0 && 
       lab[p.y][p.x] == 0;
}

bool way(position start, position goal)
{
    std::stack<position> s;
    s.push(start);
    while (!s.empty() && s.top() != goal)
    {
        position current = s.top();
        s.pop();
        if (ok(current))
        {
            lab[current.y][current.x] = 9;
            s.push(current.left());
            s.push(current.up());
            s.push(current.right());
            s.push(current.down());
        }
    }
    return !s.empty();
}

int main()
{
     std::cout << way(position{0,0},position{7,7}) << std::endl;
}