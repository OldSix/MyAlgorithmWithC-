//
// Created by Queen on 2017/2/19.
//

#ifndef INC_01_BINARY_SEARCH_FILEOPS_H
#define INC_01_BINARY_SEARCH_FILEOPS_H

#include <string>
#include <cassert>
#include <vector>
#include <fstream>

namespace FileOps
{
    int firstCharacterIndex(const std::string& s, int start) {
        for (int i = start; i < s.length(); ++i) {
            if (isalpha(s[i]))
                return i;
        }
        return s.length();
    }

    std::string lowerS(const std::string& s) {
        std::string ret = "";
        for (int i = 0; i < s.length(); ++i) {
            ret += tolower(s[i]);
        }
        return ret;
    }

    bool readFile(const std::string& filename, std::vector<std::string> &words) {
        std::string line;
        std::string contents = "";
        std::ifstream file(filename);

        if (file.is_open()) {
            while (getline(file, line))
                contents += (line + "\n");
            file.close();
        } else {
            std::cout << "Can not open " << filename << "!!!" << std::endl;
            return false;
        }

        int start = firstCharacterIndex(contents, 0);
        for (int i = start+1; i <= contents.length(); ) {
            if (i == contents.length() || !isalpha(contents[i])) {
                words.push_back(lowerS(contents.substr(start, i-start)));
                start = firstCharacterIndex(contents, i);
                i = start + 1;
            } else {
                i++;
            }
        }

        return true;
    }

}

#endif //INC_01_BINARY_SEARCH_FILEOPS_H
