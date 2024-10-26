#include <iostream>

int main() {

    int A[5] = {1, 5, 3};
    std::cout << *A << std::endl;
    std::cout << *(A + 1) << std::endl;
    std::cout << 2[A] << std::endl;
    return 0;

}