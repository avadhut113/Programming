// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sort.hpp"
#include "2. Add Two Numbers.hpp"
#include "4. Median of Two Sorted Arrays.hpp"
#include "5. Longest Palindromic Substring.hpp"
#include "6. ZigZag Conversion.hpp"
#include "12 Integer to Roman.hpp"
#include "14. Longest Common Prefix.hpp"
#include "15. 3Sum.hpp"
#include "17. Letter Combinations of a Phone Number.hpp"
#include "23. Merge k Sorted Lists.hpp"
#include "33. Search in Rotated Sorted Array.hpp"
#include "34. Find First and Last Position of Element in Sorted Array.hpp"
#include "35. Search Insert Position.hpp"
#include "36. Valid Sudoku.hpp"
#include "46. Permutations.hpp"
#include "48. Rotate Image.hpp"
#include "54. Spiral Matrix.hpp"
#include "56. Merge Intervals.hpp"
#include "57. Insert Interval.hpp"
#include "61. Rotate List.hpp"
#include "71. Simplify Path.hpp"
#include "73. Set Matrix Zeroes.hpp"
#include "74. Search a 2D Matrix.hpp"
#include "82. Remove Duplicates from Sorted List II.hpp"
#include "98. Validate Binary Search Tree.hpp"
#include "106. Construct Binary Tree from Inorder and Postorder Traversal.hpp"
#include "108. Convert Sorted Array to Binary Search Tree.hpp"
#include "117. Populating Next Right Pointers in Each Node II.hpp"
#include "121. Best Time to Buy and Sell Stock.hpp"
#include "129. Sum Root to Leaf Numbers.hpp"
#include "134. Gas Station.hpp"
#include "148. Sort List.hpp"
#include "150. Evaluate Reverse Polish Notation.hpp"
#include "151. Reverse Words in a String.hpp"
#include "162. Find Peak Element.hpp"
#include "189. Rotate Array.hpp"
#include "136_190_191.hpp"
#include "199. Binary Tree Right Side View.hpp"
#include "205. Isomorphic Strings.hpp"
#include "209. Minimum Size Subarray Sum.hpp"
#include "215. Kth Largest Element in an Array.hpp"
#include "228. Summary Ranges.hpp"
#include "239. Kth Smallest Element in a BST.hpp"
#include "236. Lowest Common Ancestor of a Binary Tree.hpp"
#include "295. Find Median from Data Stream.hpp"
#include "392. Is Subsequence.hpp"
#include "502. IPO.hpp"
#include "637. Average of Levels in Binary Tree.hpp"
#include "918. Maximum Sum Circular Subarray.hpp"
#include "1021. Remove Outermost Parentheses.hpp"
#include "1114. Print in Order.hpp"
#include "1116. Print Zero Even Odd.hpp"

#include <map>
#include <source_location>

 using namespace std::string_view_literals;

 constexpr void Assert(bool condition, std::string_view msg, std::source_location loc = std::source_location::current())
 {
     if(not std::is_constant_evaluated()) {
         if(not condition) {
             std::println(std::cerr, "{}:{} {}", loc.file_name(), loc.line(), msg);
             std::terminate();
         }
     }
 }

 constexpr auto SomeCalculation(int i)
 {
     Assert(i>0, "i must be greater than zero"sv);

     return 6-i;
 }

class TemplateTypeToString
{
public:
    using SelfType = TemplateTypeToString;

    template<typename Type>
    [[nodiscard]] consteval static inline std::string_view Convert()
    {
        const std::string_view functionDescription{ __FUNCSIG__ };

        //const std::string_view typeDescription{ functionDescription.substr(0, functionDescription.size() - 1)) };

        //Check if the string contains word "type"
        const auto typeDescriptionStart{ functionDescription.find("type = ") + 7 };

        //Check if from the start of the type description to the end of the string exist the character ";"
        const auto typeDescriptionEnd{ functionDescription.find(";", typeDescriptionStart) };

        //chech if the type decription end exist
        if (typeDescriptionEnd != std::string_view::npos) {
            const std::string_view typeDescription{ functionDescription.substr(typeDescriptionStart, typeDescriptionEnd - typeDescriptionStart) };
            return { typeDescription };
        }

        const std::string_view typeDescription{ functionDescription.substr(typeDescriptionStart, functionDescription.size() - typeDescription.size() - typeDescriptionStart - 1UL) };

        return { typeDescription };
    }

private:

    TemplateTypeToString() = delete;
    ~TemplateTypeToString() = delete;
};

int main()
{
    //test2();
    //test4();
    //test5();
    //test_6();
    //test_12();
    //test14();
    //test15();
    //test17();
    //test23();
    //test33();
    //test34();
    //test35();
    //test36();
    test46();
    //test48();
    //test54();
    //test56();
    //test57();
    //test61();
    //test71();
    //test73();
    //test74();
    //test82();
    //test98();
    //test106();
    //test108();
    //test117();
    //test121();
    //test129();
    //test134();
    //test_148();
    //test150();
    //test151();
    //test162();
    //test189();
    //test199();
    //test_136_190_191();
    //test205();
    //test209();
    //test215();
    //test228();
    //test236();
    //test239();
    //test295();
    //test392();
    //test502();
    //test637();
    //test918(); // not completed partially executed
    //test_1114();
    //test_1116();
    //test1021(); 


    //auto a = { std::make_pair('a',1),std::make_pair('b',2),std::make_pair('c',3) };
    //print_sort();
   /* std::map<char, int> a{ {'a',1},{'b',2},{'c',3} };
    decltype(a) b;*/
    //auto a = { {'a',1},{'b',2},{'c',3} };


    /*std::vector v = { 0,1,0,0,1,0,1,0,0,0,0,0,0,0};

    int start = 0;
    int end = v.size() - 1;
    while (start < end)
    {
        if (v[end] == 0 && v[start] == 1) {
            std::swap(v[start++], v[end--]);
        }
        `   
        if (v[start] == 0) start++;
        if (v[end] == 1) end--;
    }*/
}