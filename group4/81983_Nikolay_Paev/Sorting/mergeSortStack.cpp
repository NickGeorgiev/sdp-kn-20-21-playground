#include <iostream>
#include <vector>
#include <stack>

void merge(std::vector<int>& arr, size_t start, size_t middle, size_t end) {
    std::vector<int> left_part, right_part;
    size_t left_part_size = middle - start + 1;
    size_t right_part_size = end - middle;
    int i, j, k;

    for(i = 0; i < left_part_size; i++) {
        left_part.push_back(arr[start + i]);
    }

    for(j = 0; j < right_part_size; j++) {
        right_part.push_back(arr[middle + 1 + j]);
    }

    i = 0, j = 0, k = start;

    while(i < left_part_size && j < right_part_size) {
        if(left_part[i] < right_part[j]) {
            arr[k] = left_part[i++];
        } else {
            arr[k] = right_part[j++];
        }
        k++;
    }

    while(i < left_part_size) {
        arr[k++] = left_part[i++];
    }

    while(j < right_part_size) {
        arr[k++] = right_part[j++];
    }
}

struct Positions {
	size_t start;
	size_t end;
};

void mergeSort(std::vector<int>& arr) {
    std::stack<Positions> s;

	s.push({0,arr.size()-1});
	Positions current = s.top();

	while(!s.empty() && current.start < current.end) {
		current = s.top(); s.pop();

		size_t currentMiddle = (current.end + current.start) / 2;

		s.push({currentMiddle + 1, current.end});
		s.push({current.start, currentMiddle});
		merge(arr, current.start, currentMiddle, current.end);
	}
}

//T(n) = 2T(n/2) + O(n)
//T(n) = O(n*logn)

int main() {
	std::vector<int> arr = {1,3,4,12,2,3,4,5};
	mergeSort(arr);
	//merge(arr,0,4,7);

	for(int elem : arr) {
		std::cout << elem << ' ';
	}
}