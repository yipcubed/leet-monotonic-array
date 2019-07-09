#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/monotonic-array/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    enum class Orientation {
        UNKNOWN, INCREASING, DECREASING
    };

    bool isMonotonic(vector<int> &A) {
        Orientation way{Orientation::UNKNOWN};
        for (int i = 1; i < A.size(); ++i) {
            switch (way) {
                case Orientation::INCREASING:
                    if (A[i] < A[i - 1]) return false;
                    break;
                case Orientation::DECREASING:
                    if (A[i] > A[i - 1]) return false;
                    break;
                default:
                    if (A[i] < A[i - 1]) {
                        way = Orientation::DECREASING;
                    } else if (A[i] > A[i - 1]) {
                        way = Orientation::INCREASING;
                    }
            }
        }
        return true;
    }
};

void test1() {
    vector<int> v1{1, 2, 2, 3};

    cout << "1 ? " << Solution().isMonotonic(v1) << endl;

    vector<int> v2{1, 1, 1};

    cout << "1 ? " << Solution().isMonotonic(v2) << endl;

    vector<int> v3{1, 3, 2};

    cout << "0 ? " << Solution().isMonotonic(v3) << endl;
}

void test2() {

}

void test3() {

}