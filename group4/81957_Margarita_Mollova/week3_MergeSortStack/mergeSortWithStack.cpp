#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct MergeState
{
    int start;
    int end;
};

void merge (vector<int>& arr, const MergeState& state)
{
    int stateMiddle = (state.start + state.end)/2;

    vector<int> leftPart;
    for (int i=state.start; i<=stateMiddle; i++)
    {
        leftPart.push_back(arr[i]);
    }

    int i = 0, j = stateMiddle + 1, k = state.start;
    while (i < leftPart.size() && j <= state.end)
    {
        if (leftPart[i] <= arr[j])
        {
            arr[k++] = leftPart[i++];
        }
        else
        {
            arr[k++] = arr[j++];
        }  
    }

    while (i < leftPart.size())
    {
        arr[k++] = leftPart[i++];
    }

    while (j <= state.end)
    {
        arr[k++] = arr[j++];
    }
}

void mergeSortStack (vector<int>& arr)
{
    stack<MergeState> states;
    states.push({0, (int)(arr.size()-1)});

    while (!states.empty())
    {
        MergeState topState = states.top();
        int topStateMiddle = (topState.start + topState.end) / 2;
        states.push({topStateMiddle+1, topState.end});
        states.push({topState.start, topStateMiddle});

        MergeState currentState = states.top();
        if (currentState.start >= currentState.end)
        {
            states.pop();
            currentState = states.top();
            while (!states.empty() && 
                   currentState.start >= states.top().start && currentState.end <= states.top().end)
            {
                merge(arr, states.top());
                states.pop();
            }
        }
    }
}

int main ()
{
    vector<int> arr = {1, 10, 15, 2, 23, 45, 2};

    mergeSortStack(arr);
    for (int element: arr)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
