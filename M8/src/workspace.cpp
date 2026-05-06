#include "workspace.h"

#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>

namespace workspace {

bool save(const std::string& path, const std::vector<ComplexNumber>& numbers) {
    std::ofstream out(path);
    if (!out.is_open()) return false;
    for (const auto& n : numbers) {
        out << n.name() << ',' << n.real() << ',' << n.imag() << '\n';
    }
    return out.good();
}

LoadResult load(const std::string& path) {
    LoadResult result{{}, 0};
    std::ifstream in(path);
    if (!in.is_open()) return result;  // missing file -> empty, not an error

    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;

        const auto c1 = line.find(',');
        const auto c2 = (c1 == std::string::npos) ? std::string::npos
                                                  : line.find(',', c1 + 1);
        if (c1 == std::string::npos || c2 == std::string::npos) {
            ++result.skippedLines;
            continue;
        }

        std::string name = line.substr(0, c1);
        if (name.empty()) {
            ++result.skippedLines;
            continue;
        }

        try {
            const double r = std::stod(line.substr(c1 + 1, c2 - c1 - 1));
            const double i = std::stod(line.substr(c2 + 1));
            result.numbers.emplace_back(std::move(name), r, i);
        } catch (...) {
            ++result.skippedLines;
        }
    }
    return result;
}

void appendLog(const std::string& path, const std::string& entry) {
    std::ofstream out(path, std::ios::app);
    if (!out.is_open()) return;

    const std::time_t t = std::time(nullptr);
    std::tm tmCopy{};
#if defined(_WIN32)
    localtime_s(&tmCopy, &t);
#else
    if (std::tm* p = std::localtime(&t)) tmCopy = *p;
#endif
    out << std::put_time(&tmCopy, "%Y-%m-%d %H:%M:%S") << ' ' << entry << '\n';
}

std::vector<std::string> loadLog(const std::string& path) {
    std::vector<std::string> result;
    std::ifstream in(path);
    if (!in.is_open()) return result;
    std::string line;
    while (std::getline(in, line)) result.push_back(std::move(line));
    return result;
}

}  // namespace workspace
