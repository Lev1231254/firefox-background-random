#include "editCSSFile.hpp"
#include "randomPicName.hpp"
#include <fstream>


int main(){
    //open urls.txt
    std::filesystem::path pathToUrls = std::filesystem::current_path();

    while (pathToUrls.filename() != "firefox-background-random"){
        pathToUrls = pathToUrls.parent_path();
    }

    pathToUrls /= "urls.txt";

    
    std::ifstream urls(pathToUrls);

    if (!urls.is_open()) {
        std::cerr << "Error opening urls.txt file!" << std::endl;
        return 1; // Exit if the file cannot be opened
    }

    //set path to css file

    std::string userContentUrl;
    std::getline(urls, userContentUrl);

    

    //set path to image directory
    std::string imgDirStr;
    std::getline(urls, imgDirStr);
    fs::path imgDir = imgDirStr;

    //get all image's names and find random file
    std::vector<std::string> files = getAllPicsNames(imgDir);
    printAllPics(files);
    std::string imgUrl = "img/" + pickRandomFile(files);

    //tweak .css file
    editCSSFile(userContentUrl, imgUrl);

    urls.close();
}