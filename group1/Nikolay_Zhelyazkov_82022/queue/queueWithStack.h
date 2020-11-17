#ifndef Q_INCLUDED
#define Q_INCLUDED
#include <iostream>
#include <stack>
#include <exception>

class QueueWithStack
{
private:
  std::stack<int>pushStack;
  std::stack<int>popStack;
  void prePush();
  void prePop();
  void copy(const QueueWithStack&);
  void clear();
public:
    QueueWithStack();
   // QueueWithStack(std::initializer_list<int>);
    QueueWithStack(const QueueWithStack&);
    void popFront();
    void pushBack(const int&);
    int front();
    int back();
    size_t size()const;
    bool empty()const;
    QueueWithStack& operator=(const QueueWithStack&);
    friend std::ostream& operator<<(std::ostream&,QueueWithStack&);
    
};

#endif