#include <iostream>

int main() {
    try {
        // Risky code here. For example:
        int a = 0;
        int b = 10 / a; // Division by zero!
    } catch (const std::exception& e) { // Catching the error
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return -1; // Indicate that the program didn't complete successfully
    }
    return 0; // Indicate that the program completed successfully
}
