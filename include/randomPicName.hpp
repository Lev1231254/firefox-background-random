#pragma once

#include <iostream>
#include <vector>
#include <filesystem>
#include <string>
#include <random>

namespace fs = std::filesystem;


bool endsWith(const std::string& str, const std::string& suffix);
bool isPic(const std::string& filename);

std::vector<std::string> getAllPicsNames(const fs::path imgDi);

void printAllPics(const std::vector<std::string> files);

std::string pickRandomFile(const std::vector<std::string> pics);

