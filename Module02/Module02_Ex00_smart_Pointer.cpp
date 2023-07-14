/*
Using smart pointers can help avoid both memory leaks and dangling pointers by automating-
memory management. Let me show you how to modify the program to use smart pointers:
*/
#include <iostream>
#include <memory>

void memoryLeakExample()
{
    std::unique_ptr<int> value(new int(5));
    // No need to manually deallocate memory
}

void danglingPointerExample()
{
    std::unique_ptr<int> ptr(new int(10));
    std::unique_ptr<int> anotherPtr = std::move(ptr); // Ownership transferred
    // ptr is automatically set to nullptr, preventing a dangling pointer
    std::cout << *anotherPtr << std::endl; // Safe to access anotherPtr
}

int main()
{
    memoryLeakExample();
    danglingPointerExample();

    return 0;
}
