
/*
 -->>What is memory leak? And what is a dangling pointer?

A memory leak occurs when dynamically allocated memory is not properly deallocated,
resulting in a loss of available memory over time. This can happen when a program fails-
to release dynamically allocated memory, causing it to become inaccessible and unusable.

A dangling pointer, on the other hand, is a pointer that points to a memory location-
that has been deallocated or freed. Accessing or dereferencing a dangling pointer can lead-
to undefined behavior, as the memory it points to may have been reused for other purposes.
*/
#include <iostream>

void memoryLeakExample()
{
    int *value = new int(5);
    // Dynamically allocated memory not deallocated
    // Uncomment the following line to fix the memory leak:
    // delete value;
}

void danglingPointerExample()
{
    int *ptr = new int(10);
    int *anotherPtr = ptr;
    delete ptr;
    // ptr is now a dangling pointer as the memory it points to has been freed
    std::cout << *anotherPtr << std::endl; // Accessing a dangling pointer leads to undefined behavior
}

int main()
{
    memoryLeakExample();
    danglingPointerExample();

    return 0;
}
