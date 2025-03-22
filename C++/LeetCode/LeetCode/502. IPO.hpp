#include <queue>
#include <vector>

using std::pair;
using std::priority_queue;
using std::vector;

// A pair of integers alias to represent a pair of capital and profit.
using ProfitCapitalPair = pair<int, int>;

class Solution502 {
public:
    // This function maximizes the capital by doing at most 'k' projects starting
    // with initial capital 'w'. Projects have associated profits and capital requirements.
    static int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // A min-heap that stores pairs of capital requirements and profits
        // Such that the project with the least capital requirement is on top.
        priority_queue<ProfitCapitalPair, vector<ProfitCapitalPair>, std::greater<ProfitCapitalPair>> minCapitalHeap;

        // Populate the min-heap with the capital and profits of the projects.
        int numProjects = profits.size();
        for (int i = 0; i < numProjects; ++i) {
            minCapitalHeap.push({ capital[i], profits[i] });
        }

        // A max-heap to store profits of projects we can afford to invest in,
        // so we can always choose the most profitable one next.
        priority_queue<int> maxProfitHeap;

        // Loop to perform up to 'k' investments.
        while (k--) {
            // Move all projects we can afford (with current capital 'w') to a max-heap.
            // This heap will help us to quickly select the next most profitable project.
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= w) {
                maxProfitHeap.push(minCapitalHeap.top().second);
                minCapitalHeap.pop();
            }

            // If we cannot afford any project, break out of the loop.
            if (maxProfitHeap.empty()) {
                break;
            }

            // Pick the most profitable project and increase our capital.
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        // After completing 'k' or the maximum number of profitable investments,
        // 'w' is our maximized capital.
        return w;
    }
};

void test502()
{
    /*std::vector<int> profits{ 1, 2, 3 }, capital{ 0, 1, 1 };
    std::cout << Solution502::findMaximizedCapital(2, 0, profits, capital);*/

    std::vector<int> profits{ 1, 2, 3 }, capital{ 0, 1, 2 };
    std::cout << Solution502::findMaximizedCapital(3, 0, profits, capital);
}

