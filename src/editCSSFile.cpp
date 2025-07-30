#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include "editCSSFile.hpp"

void editCSSFile(const std::string& filename, const std::string& imgUrl) {


    // Step 1: Read the CSS file
    std::ifstream inputFile(filename);

    std::cout << "Current path: " << std::filesystem::current_path() << std::endl;
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    

    std::stringstream buffer;
    buffer << inputFile.rdbuf(); // Read the file into a stringstream
    std::string cssContent = buffer.str(); // Get the content as a string
    inputFile.close();

    // Step 2: Modify the CSS content
    // Example: Replace a color value
    std::string startingPosWord = "background:";

    int pos = cssContent.find(startingPosWord) + startingPosWord.length();
    bool isReplaced = 0;

    while (!isReplaced){

        if (pos >= cssContent.length()) {
            std::cout << "Went outside of boundaries of file: " << filename << std::endl;
            return;
        }

        if (cssContent.substr(pos, 4) == "url("){

            int first = pos + 4;

            while (cssContent[pos] != ')') pos++;

            int originalUrlLen = pos - first;

            cssContent.replace(first, originalUrlLen, imgUrl);
            isReplaced = true;
        }

        else pos++;
    }

    // Step 3: Write back to the CSS file
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    outputFile << cssContent; // Write the modified content back to the file
    outputFile.close();

    std::cout << "File edited succesfully\n";
}
