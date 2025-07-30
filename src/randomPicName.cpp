#include <filesystem>
#include "randomPicName.hpp"



bool endsWith(const std::string& str, const std::string& suffix) {
    if (str.length() >= suffix.length()) {
        return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
    }
    return false;
}


bool isImg(const std::string& filename) {
    return endsWith(filename, ".png") || endsWith(filename, ".jpg") || endsWith(filename, ".PNG") || endsWith(filename, ".jpeg");
}



std::vector<std::string> getAllPicsNames(const fs::path imgDir){

    std::vector<std::string> files;
    std::string filename;


    // Iterate through the directory
    int len = 0;
    for (const auto& entry : fs::directory_iterator(imgDir)) {
        if (entry.is_regular_file()) {
            filename = entry.path().filename().string();
            // Check for .png and .jpg extensions
            if (isImg) len++;
        }
    }

    // Create list of image files


    int i = 0;
    for (const auto& entry : fs::directory_iterator(imgDir)) {
        if (entry.is_regular_file()) {
            filename = entry.path().filename().string();
            // Check for .png and .jpg extensions
            if (isImg) {
                files.push_back(filename);
                i++;
            }
        }
    }


    if (len == 0) std::cout << "Cant find file: " << filename << std::endl;
    else std::cout << "Found " << len << " files succesfully" << std::endl;


    //print found files
   

    return files;
}


void printAllPics(const std::vector<std::string> pics){
     for (int i = 0; i < pics.size(); i++) {
        std::cout << "file " << i << ": " << pics[i] << std::endl;
    }
}


std::string pickRandomFile(const std::vector<std::string> pics){
    if (pics.empty()) {
        std::cout << "No pictures found, but tried to pick random" << std::endl;
        return ""; // Return an empty string if the vector is empty
    }

    // Create a random number generator
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 eng(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(0, pics.size() - 1); // Define the range

    // Pick a random index
    int randomIndex = distr(eng);
    return pics[randomIndex]; // Return the randomly selected element
}




