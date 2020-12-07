#include "Stack.h"
#include <iostream>
#include <vector>

struct PartOfArrayWrapper
{
    size_t start;
    size_t end;
    bool isSorted;

public:
    PartOfArrayWrapper(const size_t &start, const size_t &end)
    {
        this->start = start;
        this->end = end;
        this->isSorted = (start == end);
    }
    PartOfArrayWrapper(const size_t &start, const size_t &end, bool sorted)
    {
        this->start = start;
        this->end = end;
        this->isSorted = sorted;
    }

    size_t middle()
    {
        return (start + end) / 2;
    }
    void print(const std::vector<int> &arr)
    {
        for (size_t i = start; i <= end; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

void merge(std::vector<int> &arr, size_t start, size_t middle, size_t end)
{
    std::vector<int> left_part, right_part;
    size_t left_part_size = middle - start + 1;
    size_t right_part_size = end - middle;
    int i, j, k;

    for (i = 0; i < left_part_size; i++)
    {
        left_part.push_back(arr[start + i]);
    }

    for (j = 0; j < right_part_size; j++)
    {
        right_part.push_back(arr[middle + 1 + j]);
    }

    i = 0, j = 0, k = start;

    while (i < left_part_size && j < right_part_size)
    {
        if (left_part[i] < right_part[j])
        {
            arr[k] = left_part[i++];
        }
        else
        {
            arr[k] = right_part[j++];
        }
        k++;
    }

    while (i < left_part_size)
    {
        arr[k++] = left_part[i++];
    }

    while (j < right_part_size)
    {
        arr[k++] = right_part[j++];
    }
}

void merge_sort(std::vector<int> &arr)
{
    if (arr.size() <= 1)
    {
        return;
    }

    Stack<PartOfArrayWrapper> arrayParts = Stack<PartOfArrayWrapper>();
    Stack<PartOfArrayWrapper> arrayPartsHelper = Stack<PartOfArrayWrapper>();

    size_t middle = (0 + arr.size() - 1) / 2;

    arrayParts.push(PartOfArrayWrapper(middle + 1, arr.size() - 1));
    arrayParts.push(PartOfArrayWrapper(0, middle));

    while (arrayParts.size() != 1)
    {

        while (!arrayParts.empty())
        {
            PartOfArrayWrapper arrayPart = arrayParts.pop();
            if (!arrayPart.isSorted)
            {
                arrayPartsHelper.push(PartOfArrayWrapper(arrayPart.start, arrayPart.middle()));
                arrayPartsHelper.push(PartOfArrayWrapper(arrayPart.middle() + 1, arrayPart.end));
            }
            else
            {
                arrayPartsHelper.push(arrayPart);
            }
        }

        while (!arrayPartsHelper.empty())
        {
            PartOfArrayWrapper arrayPart = arrayPartsHelper.pop();

            if (arrayPartsHelper.empty())
            {
                arrayParts.push(arrayPart);
            }
            else if (arrayPart.isSorted)
            {
                if (arrayPartsHelper.top().isSorted)
                {
                    merge(arr, arrayPartsHelper.top().start, arrayPartsHelper.top().end, arrayPart.end);
                    arrayParts.push(PartOfArrayWrapper(arrayPartsHelper.pop().start, arrayPart.end, true));
                }
                else
                {
                    arrayParts.push(arrayPart);
                }
            }
            else
            {
                arrayParts.push(arrayPart);
            }
        }
    }
}

int main()
{
    std::vector<int> array = {35, 2, 45, 6, 2, 3, 78, 23};
    merge_sort(array);

    for (const int &elem : array)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}