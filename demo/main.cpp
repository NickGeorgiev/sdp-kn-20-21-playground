#include<iostream>
#include "vector.h"

int main() {
    Vector v = {1,2,3,4};
    for(int i=0;i<4;i++) {
        std::cout << v[i] << " ";
    }
}