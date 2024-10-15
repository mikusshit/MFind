#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    // Check for the correct number of arguments
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <filename> <keyword>" << endl;
        return 1;
    }

    // Use pointers to access filename and keyword directly
    const char* filename = argv[1];  // Pointer to filename argument
    const char* keyword = argv[2];   // Pointer to keyword argument

    // Open the file
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open file '" << filename << "'" << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;
    bool found = false;

    // Read the file line by line
    while (getline(inputFile, line)) {
        // Check for the keyword in the current line
        if (line.find(keyword) != string::npos) {
            cout << "Line " << lineNumber << ": " << line << endl;
            found = true;
        }
        lineNumber++;
    }

    // Close the file
    inputFile.close();

    // If the keyword was not found, print a message
    if (!found) {
        cout << "Keyword '" << keyword << "' not found." << endl;
    }

    return 0;
}

