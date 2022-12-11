//
// Created by Elitsa on 08/12/2022.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "Rearrangements.h"

Rearrangements::Rearrangements()
        : m_rearrangements{{0, 0, 0}}, m_size{0} {

}

bool Rearrangements::readFile(const std::string &fileName) {
    std::fstream file{fileName};
    std::string line;
    if (file) {  // proceed if file open
        while (!file.eof()) {
            std::getline(file, line);
            int count, moveFrom, moveTo;
            std::string strToSkip1, strToSkip2, strToSkip3;
            std::istringstream iss{line};
            iss >> strToSkip1 >> count >> strToSkip2 >> moveFrom >> strToSkip3 >> moveTo;
            if (!iss.fail()) {
                addRearrangement(count, moveFrom, moveTo);
            }
        }
        return true;
    }
    return false;
}

void Rearrangements::addRearrangement(int count, int moveFrom, int moveTo) {
    m_rearrangements[m_size].count = count;
    m_rearrangements[m_size].moveFrom = moveFrom;
    m_rearrangements[m_size].moveTo = moveTo;
    m_size++;
}

void Rearrangements::moveCrates(std::vector<char> vec[9], Rearrangements &rearrangements) {
    for (int i = 0; i < rearrangements.m_size; i++){
        std::vector<char> temp{};
        int count{getCount(rearrangements, i)};
        int indexTo{getMoveTo(rearrangements, i)};
        int indexFrom{getMoveFrom(rearrangements, i)};
        if(count == 1) {
            char c = getLastChar(vec, indexFrom - 1);
            vec[indexTo - 1].push_back(c);
        }
        else{
            for(int j = 0; j < count; j++){ // iterate through the count
                char c = getLastChar(vec, indexFrom - 1);
                temp.push_back(c);
            }
            for(std::size_t j = temp.size(); j > 0; j--){
                char c = temp.back();
                temp.pop_back();
                vec[indexTo - 1].push_back(c);
            }
        }
    }
    printCrates(vec);
}

int Rearrangements::getCount(Rearrangements &rearrangements, int index) {
    return rearrangements.m_rearrangements[index].count;
}

int Rearrangements::getMoveFrom(Rearrangements &rearrangements, int index) {
    return rearrangements.m_rearrangements[index].moveFrom;
}

int Rearrangements::getMoveTo(Rearrangements &rearrangements, int index) {
    return rearrangements.m_rearrangements[index].moveTo;
}

void Rearrangements::printCrates(std::vector<char> vec[9]) {
    for (std::size_t j = 0; j < 9; j++) {
        for (char i : vec[j]) {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}

char Rearrangements::getLastChar(std::vector<char> *vec, int index) {
    char c = vec[index][vec[index].size() - 1];
    vec[index].pop_back();
    return c;
}
