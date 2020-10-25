#include"DList.h"

void DList::copy(const DList& other)
{
if(!other.first)
{
    this->first = nullptr;
    return;
}

Box* toCopy = other.first;
Box* prevCopied = nullptr;

this->first = new Box(other.first->data);
toCopy = toCopy->next;
prevCopied = this->first;

    while(toCopy)
    {
        //prevCopied->next = new Box(toCopy->data);
        //toCopy = toCopy->next;
        //prevCopied->next->prev = prevCopied;
        //prevCopied = prevCopied->next;       
        prevCopied->next = new Box(toCopy->data, nullptr, prevCopied);
        toCopy = toCopy->next;
        prevCopied = prevCopied->next;   
    }
}

void DList::clear()
{
    Box* curr = this->first;
    Box* save;
    while(curr != nullptr)
    {
        save = curr;
        curr = curr->next;
        delete save;
    }
}

DList::DList():first(nullptr){}

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
        this->first->next=this->first->next->next;
    }
    else
    {
        std::cout<<"Cannot pop!";
        return;
    } 
}

void DList::push(const int& other)
{
    this->first = new Box(other, this->first, nullptr);
}

void DList::push_back(const int& other)
{
    if(this->first)
    {
        Box* last = this->first;
        while(last->next != nullptr)
        {
            last = last->next;
        }
        last->next = new Box(other, nullptr, last);
    }
    else
    {
        push(other);
    }    
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
 Box* curr = other.first;
    while(curr != nullptr)
    {
        out << curr->data << " ";
        curr = curr->next;
    }
  return out;
}

int DList::count(Box* l, int x) const
{
Box* curr = this->first;
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

int DList::countFromBegin(const int& x) const
{
    return (*this).count(this->first, x);
}

Box* DList::range(int x, int y)
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
    Box* helper = other.first;
    while(helper != nullptr)
    {
       (*this).push_back(helper->data);
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
                    (*this).pop();
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

void DList::reverse()
{
    Box* curr = this->first;
    Box* next = nullptr;
    Box* prev = nullptr;
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
    Box* curr = this->first;
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
