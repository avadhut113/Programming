#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;


class Solution71 {
public:
    // Function to simplify the given Unix-like file path.
    static string simplifyPath(string path) {
        deque<string> directoryNames; // Use a deque to store the directory names after parsing.
        stringstream ss(path); // Create a stringstream to separate the elements by '/'.
        string token; // String to store the separated elements.

        // Process each part of the path separated by '/'.
        while (getline(ss, token, '/')) {

            // Continue if the element is empty or a dot, which means stay in the current directory.
            if (token == "" || token == ".") {
                continue;
            }

            // If element is a double dot, move up to the parent directory if possible.
            if (token == "..") {
                // Only pop if the stack is not empty (cannot go above root).
                if (!directoryNames.empty()) {
                    directoryNames.pop_back();
                }
            }
            else {
                // Otherwise, it's a valid directory name; add to our list.
                directoryNames.push_back(token);
            }
        }

        // If directory stack is empty, we're at root.
        if (directoryNames.empty()) {
            return "/";
        }

        // Build the simplified path from the directory stack.
        string result;
        for (const auto& dirName : directoryNames) {
            result += "/" + dirName; // Prefix each directory name with a slash.
        }

        // Return the final simplified path.
        return result;
    }
};

void test71()
{
    std::cout << Solution71::simplifyPath("/home/") << "\n";
    std::cout << Solution71::simplifyPath("/home//foo/") << "\n";
    std::cout << Solution71::simplifyPath("/home/user/Documents/../Pictures") << "\n";
    std::cout << Solution71::simplifyPath("/../") << "\n";
    std::cout << Solution71::simplifyPath("/.../a/../b/c/../d/./") << "\n";
}