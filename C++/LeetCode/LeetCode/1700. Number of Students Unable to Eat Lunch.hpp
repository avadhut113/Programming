#pragma once
#include <vector>
#include <array>

class Solution1700 {
public:
    static int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        std::array<int, 2> count{ 0 };

        for (const auto& stud : students)
            count[stud]++;


        for (auto& sandwitch : sandwiches) {
            if (count[sandwitch] == 0)
                return count[1 - sandwitch];

            count[sandwitch]--;
        }
        return 0;
    }
};

void test1700()
{
    std::vector<int> students{ 1,1,1,0,0,1 };
    std::vector<int> sandwitches{ 1,0,0,0,1,1 };
    std::cout << Solution1700::countStudents(students, sandwitches);
}
