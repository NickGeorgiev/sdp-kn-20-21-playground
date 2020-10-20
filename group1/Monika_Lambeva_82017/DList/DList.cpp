#include"DList.h"

void DList::copy(const DList& other)
{
if(other.first == nullptr)
{
    this->first = nullptr;
    return;
}

box* toCopy = other.first;
box* prevCopied = nullptr;

this->first = new box(other.first->data);
toCopy = toCopy->next;
prevCopied = this->first;

    while(toCopy != nullptr)
    {
        prevCopied->next = new box(toCopy->data);
        toCopy = toCopy->next;
        prevCopied->next->prev = prevCopied;
        prevCopied = prevCopied->next;        
    }
}

void DList::clear()
{
    box* curr = this->first;
    box* save;
    while(curr != nullptr)
    {
        save = curr;
        curr = curr->next;
        delete save;
    }
}

DList::DList()
{
    this->first = nullptr;
}

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

//box* getFirst()const
//{
//return this->first;
//}
void DList::pop()
{
    box* saver = this->first->next;
    delete this->first;
    this->first = saver;
}

void DList::push(const int& other)
{
box* newElem = new box;
newElem->data = other;
newElem->next = this->first;
if(this->first != nullptr)
{
    this->first->prev = newElem;
}
this->first = newElem;
}

void DList::push_back(const int& other)
{
    if(this->first == nullptr)
    {
        (*this).push(other);
        return;
    }
   box* newElem = new box;
   newElem->data = other;
   newElem->next = nullptr;
   box* last = this->first;
   while(last->next != nullptr)
   {
       last = last->next;
   }
last->next = newElem;
newElem->prev = last;
}

DList& DList::operator+= (const int &x)
{
    (*this).push(x);
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
 box* curr = other.first;
    while(curr != nullptr)
    {
        out << curr->data << " ";
        curr = curr->next;
    }
  return out;
}

int DList::count(box* l, int x)
{
box* curr = this->first;
while(curr->data != l->data && curr != nullptr)
{
    curr = curr->next;
}
int counter = 0;
while(curr != nullptr)
{
    if(curr->data == x) counter++;
    curr = curr->next;
}
return counter;
}

int DList::countFromBegin(const int& x)
{
    box* curr = this->first;
    int counter = 0;
    while(curr != nullptr)
    {
        if(curr->data == x) counter++;
        curr = curr->next;
    }
    return counter;
}

box* DList::range(int x, int y)
{
while(y >= x)
{
    (*this).push(y);
    y--;
}
return this->first;
}

void DList::append(const DList& other)
{
    box* saver = this->first;
    while(saver != nullptr)
    {
        saver = saver->next;
    }
    box* helper = other.first;
    while(helper != nullptr)
    {
       (*this).push_back(helper->data);
       helper = helper->next;
    }
}

DList& DList::concat(const DList& l1, const DList& l2)
{
    DList newList;

    newList.append(l1);
    newList.append(l2);
    *this = newList;    
    return *this;
}

void DList::removeAll(const int& x)
{
if(this->first == nullptr)
{
    this->first = nullptr;
    return;
}
box* curr = this->first;
box* prev = nullptr;
    while(curr != nullptr)
    {
        if(curr->data == x) 
        {
            if(curr->prev == nullptr)
            {
                this->first = curr->next;
               
            }
            else
            {
               prev->next = curr->next;
             curr->next->prev = prev;
            }              
        }    
        prev = curr;
        curr = curr->next;
    }
}

void DList::reverse()
{
    box* curr = this->first;
    box* next = nullptr;
    box* prev = nullptr;
    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    this->first = prev;
}

void DList::removeAllDuplicates()
{
    box* curr = this->first;
    while(curr != nullptr)
    {
        if(countFromBegin(curr->data) > 1) (*this).removeAll(curr->data);
        curr = curr->next;
    }
}

void DList::removeElement(const int& index)
{
    if(index == 0)
    {
        (*this).pop();
        return;
    }
    box* curr = this->first;
    box* prev = nullptr;
    int i = 0;
    while(i != index && curr != nullptr)
    {
        i++;
        prev = curr;
        curr = curr->next;
    }
    if(curr == nullptr) return;
    prev->next = curr->next;
    curr->next->prev = prev;
}

void DList::mergeWithSorted(const DList& other)
{
box* curr = nullptr;
box* next = this->first;

box* otherCurr = other.first;

    while(otherCurr != nullptr)
    {
        if(curr == nullptr && otherCurr->data <= next->data)
        {
            (*this).push(otherCurr->data);
            otherCurr = otherCurr->next;
        }
        else if(next == nullptr && otherCurr->data >= curr->data)
        {
            (*this).push_back(otherCurr->data);
            otherCurr = otherCurr->next;
            curr = nullptr;
            next = this->first;
        }
        else if(otherCurr->data >= curr->data && otherCurr->data <= next->data)
        {
            box* newBox = new box;
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