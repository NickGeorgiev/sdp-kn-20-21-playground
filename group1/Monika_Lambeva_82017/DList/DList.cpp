#include"DList.h"

void DList::copy(const DList& other)
{
if(!other.first)
{
    this->first = nullptr;
    this->last = nullptr;
    return;
}

Box* toCopy = other.first;
Box* prevCopied = nullptr;

this->first = new Box(other.first->data);
toCopy = toCopy->next;
prevCopied = this->first;

    while(toCopy)
    { 
        prevCopied->next = new Box(toCopy->data, nullptr, prevCopied);
        toCopy = toCopy->next;
        prevCopied = prevCopied->next;   
    }
    this->last = prevCopied;
}

void DList::clear()
{
    Box* curr = this->first;
    Box* save;
    while(curr)
    {
        save = curr;
        curr = curr->next;
        delete save;
    }
}

DList::DList():first(nullptr), last(nullptr){}

DList::DList(const DList& other)
{
    copy(other);
}

DList& DList::operator=(const DList& other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

DList::~DList()
{
    clear();
}

void DList::pop()
{
    if(this->first)
    {
        this->first = this->first->next;
        delete this->first->prev;   
        this->first->prev = nullptr;
        this->first->next=this->first->next;
    }
    else
    {
        this->last = nullptr;
        std::cout<<"Cannot pop!";
        return;
    } 
}

void DList::push(const int& other)
{
    this->first = new Box(other, this->first, nullptr);
    if(!this->last)
    {
        this->last = this->first;
    }
}

void DList::push_back(const int& other)
{
    if(this->first)
    {
        this->last = this->last->next = new Box(other,nullptr, this->last);
    }
    else
    {
        push(other);
    }    
}

DList& DList::operator+= (const int &x)
{
    push(x);
    return *this;
}

DList DList::operator+ (const int& x) const
{
    DList buffer(*this);
    buffer += x;
    return buffer;
}

std::ostream& operator<<(std::ostream& out, const DList& other)
{
 Box* curr = other.first;
    while(curr)
    {
        out << curr->data << " ";
        curr = curr->next;
    }
  return out;
}

int DList::count(Box* l, int x) const
{
Box* curr = this->first;
while(curr->data != l->data && curr)
{
    curr = curr->next;
}
int counter = 0;
while(curr)
{
    if(curr->data == x) counter++;
    curr = curr->next;
}
return counter;
}

int DList::countFromBegin(const int& x) const
{
    return count(this->first, x);
}

Box* DList::range(int x, int y)
{
while(y >= x)
{
    push(y);
    y--;
}
return this->first;
}

void DList::append(const DList& other)
{
    Box* helper = other.first;
    while(helper)
    {
       push_back(helper->data);
       helper = helper->next;
    }
}

DList& DList::concat(const DList& l1, const DList& l2)
{
    DList newList(l1);
    newList.append(l2);
    *this = newList;    
    return *this;
}

void DList::removeAll(const int& x)
{     
    if(this->first)
    {
        Box* curr = this->first;
        Box* saver = curr->next;
        while(curr)
        {            
            if(curr->data == x) 
            {
                if(!curr->prev)
                {
                    pop();
                }                
                else if(!saver)
                {
                    curr->prev->next = nullptr;
                    delete curr;
                    return;
                }
                else
                {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                }         
            } 
            curr = saver;
            saver = saver->next;
        }    
    }
}

void DList::swap(Box* curr, Box* next, Box* prev)
{
    next = curr->next;
    curr->next = prev;
    curr->prev = next;
    prev = curr;
    curr = next;
}

void DList::reverse()
{
    Box* curr = this->first;
    Box* next = nullptr;
    Box* prev = nullptr;
    while(curr)
    {
       swap(curr, next, prev);
    }
    this->first = prev;
}

void DList::removeAllDuplicates()
{
    Box* curr = this->first;
    while(curr)
    {
        if(countFromBegin(curr->data) > 1) removeAll(curr->data);
        curr = curr->next;
    }
}

void DList::removeElement(const int& index)
{
    if(index == 0)
    {
        pop();
        return;
    }
    Box* curr = this->first;
    Box* prev = nullptr;
    int i = 0;
    while(i != index && curr != nullptr)
    {
        i++;
        prev = curr;
        curr = curr->next;
    }
    if(curr) 
    {
        prev->next = curr->next;
        curr->next->prev = prev;
    }
}

void DList::mergeWithSorted(const DList& other)
{
    Box* curr = nullptr;
    Box* next = this->first;
    Box* otherCurr = other.first;
    if(next)
    {
        while(otherCurr)
        {
            if(curr == nullptr && otherCurr->data <= next->data)
            {
                push(otherCurr->data);
                otherCurr = otherCurr->next;
            }
            else if(next == nullptr && otherCurr->data >= curr->data)
            {
                push_back(otherCurr->data);
                otherCurr = otherCurr->next;
                curr = nullptr;
                next = this->first;
            }
            else if(otherCurr->data >= curr->data && otherCurr->data <= next->data)
            {
                Box* newBox = new Box;
                newBox->data = otherCurr->data;
                curr->next = newBox;
                newBox->prev = curr;
                newBox->next = next;
                next->prev = newBox;

                otherCurr = otherCurr->next;
                curr = nullptr;
                next = this->first;
            }   
            curr = next;
            next = next->next;     
        }
    }
    else
    {
        append(other);
    }
}
