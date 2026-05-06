#pragma once

#include <string>
#include <vector>

#include "ComplexNumber.h"

namespace workspace {

// Workspace file format: one number per line, "name,real,imag".
bool save(const std::string& path, const std::vector<ComplexNumber>& numbers);

struct LoadResult {
    std::vector<ComplexNumber> numbers;
    int skippedLines;  // count of malformed lines for status-bar warning
};
LoadResult load(const std::string& path);

// Append-only operation log. One line per entry; timestamp prepended by impl.
void appendLog(const std::string& path, const std::string& entry);
std::vector<std::string> loadLog(const std::string& path);

}  // namespace workspace
