// Your First C++ Program

#include "generic.h"

// a function to test
int add(int a, int b){
	return a + b;
}

int main() {
    std::cout << "Hello test" << add(0,1) << "!";
    return 0;
}