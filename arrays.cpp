#include <iostream>

int main() {

    int A[5] = {1, 5, 3}; // static array

    std::cout << *A << std::endl; //1
    std::cout << *(A + 1) << std::endl; // 5
    std::cout << 2[A] << std::endl; // 2[A] <--> A[2]

    return 0;

}