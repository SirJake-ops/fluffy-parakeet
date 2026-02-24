#include <iostream>

int main() {

    const auto Print = [](const std::string& message){std::cout << message << std::endl;};

    Print("Hello World!");

}