#include <iostream>

int main(){
    int n;
    std::cout << "num: ";
    std::cin >> n;
    int *ptr = new int[n];
    int **array = &ptr;
    ptr[0] = {3};
    ptr[1] = {1};
    ptr[2] = {2};
    std::cout << ptr << "\n";
    std::cout << ptr[0] << "\n";
    std::cout << *ptr << "\n";
    std::cout << *(ptr + 1) << "\n";
    std::cout << (*ptr) + 1 << "\n";

    std::cout << "arra: \n";
    std::cout << array << "\n";
    std::cout << *array << "\n";
    std::cout << *(array + 1) << "\n";
    std::cout << (array + 1) << "\n";

    delete[] ptr;
    return 0;
}