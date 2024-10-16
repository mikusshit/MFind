#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void highlightKeyword(const std::string& line, const std::string& keyword) {
    size_t pos = line.find(keyword);
    if (pos != std::string::npos) {
        // Print the part before the keyword
        std::cout << line.substr(0, pos);
        // Highlight the keyword
        std::cout << "\033[31m" << line.substr(pos, keyword.length()) << "\033[0m"; // Red
        // Print the part after the keyword
        std::cout << line.substr(pos + keyword.length()) << std::endl;
    }
}


//ihate my life
int main(int argc, char* argv[]) {
    int argumentCount = argc - 1;
 
    if (argumentCount < 2) {
        std::cout << "Usage: " << argv[0] << " <filename> <keyword>" << std::endl;
        return 1;
    }

    std::vector<std::string> arguments(argv + 1, argv + argc);
    const std::string& filename = arguments[0];
    const std::string& keyword = arguments[1];
    std::cout << "MFind search initiated for " << "\033[31m" << keyword << " in " << "\033[32m" << filename << "\033[0m" << std::endl;

    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        highlightKeyword(line, keyword);
    }
    inputFile.close();
    return 0;
}

