#include <iostream>
#include <fstream>
#include <string>

std::string generateURL(std::string hash) {
    std::string baseURL = "https://www.chadsoft.co.uk/time-trials/rkgd/";
    std::string url = baseURL + hash.substr(0, 2) + "/" + hash.substr(2, 2) + "/" + hash.substr(4) + ".html";
    return url;
}

int main() {
    std::string line;
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            std::string url = generateURL(line);
            outputFile << url << std::endl;
        }
        inputFile.close();
        outputFile.close();
    }
    else {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    return 0;
}