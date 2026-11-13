#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#pragma once
#include "Matrix.hpp"
#include <string>

class FileHandler {
public:
    static void saveGameResult(const Matrix& matrix, const std::string& outcome, const std::string& fileName);
};

#endif // !FILEHANDLER_HPP