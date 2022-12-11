#include <iostream>
#include <vector>
#include "Rearrangements.h"

std::vector<char> blocks[9] = {
        std::vector<char> {'D', 'H', 'N', 'Q', 'T', 'W', 'V', 'B'},
        std::vector<char> {'D', 'W', 'B'},
        std::vector<char> {'T', 'S', 'Q', 'W', 'J', 'C'},
        std::vector<char> {'F', 'J', 'R', 'N', 'Z', 'T', 'P'},
        std::vector<char> {'G', 'P', 'V', 'J', 'M', 'S', 'T'},
        std::vector<char> {'B', 'W', 'F', 'T', 'N'},
        std::vector<char> {'B', 'L', 'D', 'Q', 'F', 'H', 'V', 'N'},
        std::vector<char> {'H', 'P', 'F', 'R'},
        std::vector<char> {'Z', 'S', 'M', 'B', 'L', 'N', 'P', 'H'},
};

int main() {
    Rearrangements rearrangements{};
    rearrangements.readFile("input.txt");
    Rearrangements::moveCrates(blocks, rearrangements);

    return 0;
}
