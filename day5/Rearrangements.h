//
// Created by Elitsa on 08/12/2022.
//

#ifndef DAY5_REARRANGEMENTS_H
#define DAY5_REARRANGEMENTS_H

#include <string>
#include <vector>

const static int MAX = 501;

struct Rearrangement {
    int count;
    int moveFrom;
    int moveTo;
};

class Rearrangements {
public:
    Rearrangements();
    bool readFile(const std::string &fileName);
    void addRearrangement(int count, int moveFrom, int moveTo);
    static void moveCrates(std::vector<char> vec[9], Rearrangements &rearrangements);
    static int getCount(Rearrangements &rearrangements, int index) ;
    static int getMoveFrom(Rearrangements &rearrangements, int index) ;
    static int getMoveTo(Rearrangements &rearrangements, int index) ;
    static void printCrates(std::vector<char> vec[9]) ;
    static char getLastChar(std::vector<char> vec[9], int index) ;

private:
    Rearrangement m_rearrangements[MAX];
    int m_size{};
};


#endif //DAY5_REARRANGEMENTS_H
