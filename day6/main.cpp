#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::string> readFile(const std::string &fileName) {
    std::vector<std::string> data;
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) {
                continue;
            }
            data.push_back(line);
        }
    }
    return data;
}

bool areDifferent(std::string &s) {
    for(std::size_t i = 0; i < s.length() - 1; i++){
        for(std::size_t j = i + 1; j < s.length(); j++){
            if(s[i] == s[j]){
                return false;
            }
        }
    }
    return true;
}

int findFirstMarker(std::vector<std::string> &vec, int cnt){
    for(std::size_t i = 0; i < vec.size(); i++){
        std::string fourChars = vec[0].substr(i, cnt);
        if (areDifferent(fourChars)){
            return i + cnt;
        }
        fourChars.clear();
    }
}

int main() {
    std::string fileName{"input.txt"};
    std::vector<std::string> data{readFile(fileName)};
    std::cout << data[0] << std::endl;
    std::cout << "First marker start-of-packet: " << findFirstMarker(data, 4) << std::endl;
    std::cout << "First marker start-of-message: " << findFirstMarker(data, 14) << std::endl;
    return 0;
}
