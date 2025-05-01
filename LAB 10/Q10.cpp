#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile("data_records.txt", std::ios::binary);
    if (!infile) {
        std::cerr << "Failed to open the file.\n";
        return 1;
    }

    int offset = 20;  
    infile.seekg(offset, std::ios::beg);

    std::string line;
    std::getline(infile, line);

    std::cout << "Third Record: " << line << '\n';

    infile.close();
    return 0;
}
