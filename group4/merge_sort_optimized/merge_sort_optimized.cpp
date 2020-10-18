#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, size_t start, size_t middle, size_t end) {
    
    int* temp = new int(end-start+1);
    size_t i= start, j = middle + 1, k = 0;

    while (i <= middle && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= middle) {
        temp[k++] = arr[i++];
    }

    while (j <= end) { 
        temp[k++] = arr[j++];
    }

    for (i = start, k = 0; i <= end; i++, k++){
        arr[i] = temp[k];
    }


    delete temp;
}

void merge_split_sort(std::vector<int>& arr, size_t start, size_t end){
    if (start >= end) {
        return;
    }
    size_t middle = (end + start) / 2;
    merge_split_sort(arr, start, middle);
    merge_split_sort(arr, middle + 1, end);
    merge(arr, start, middle, end);
}

void merge_sort(std::vector<int>& arr){
    merge_split_sort(arr, 0, arr.size()-1);
}
 
int main()
{
std::vector<int> A = {1,15,10,2,45,23};

merge_sort(A);

    for (int element : A) { 
        std::cout << element << " ";
    }

    return 0;
}