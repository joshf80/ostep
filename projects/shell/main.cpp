#include <iostream>
#include <cstdlib>
#include <string_view>
#include <memory>

struct shellState {
    std::string path{"/bin"};
};

// enum class 

void handleInput(std::string_view argument, std::shared_ptr<shellState> state) {
    if(argument.starts_with("exit")) { exit(0); }
    else if (argument.starts_with("ls")) {
        std::cout << state->path << std::endl;
    }
}

int main(int argc, char* argv[]) {
    std::shared_ptr state = std::make_shared<shellState>();
    std::string input;
    while(input != "exit") {
        std::cout << "shell> ";
        std::getline(std::cin, input);
        handleInput(input, state);
    }
}       
