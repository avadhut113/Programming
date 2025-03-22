// LongestCommonPrefix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution14 {
public:
    //############################################################################################
    //Horizonatal compare
    string longestCommonPrefixHorizontal(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int ans = INT_MAX;
        for (int i = 0; i < strs.size() - 1; i++) {
            ans = min(ans, (int)min(strs[i].size(), strs[i + 1].size()));
            while (strs[i].substr(0, ans) != strs[i + 1].substr(0, ans)) {
                ans--;
            }
            if (ans == 0)return "";
        }
        return strs[0].substr(0, ans);
    }

    //############################################################################################
    //vertical compare
    string longestCommonPrefixVertical(vector<string>& strs) {
        if (strs.size() == 0) return "";
        for (int i = 0; i < strs[0].size(); i++) {
            //i: index of char
            for (int j = 1; j < strs.size(); j++) {
                //j: index of str
                if (i >= strs[j].size() || strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }


    //############################################################################################
    //Divide and conqure Approach
    string commonSubString(string str1, string str2)
    {
        int totalcount = min(str1.size(), str2.size());

        for (int count = 0; count < totalcount; count++) {
            if (str1[count] != str2[count]) {
                return str1.substr(0, count);
            }
        }
        return str1.substr(0,totalcount);
    }

    string longestCommonPrefix(vector<string>& strs, int l, int h)
    {
        if (l == h)
            return strs[l];

        int mid = (l + h) / 2;

        string lstr = longestCommonPrefix(strs, l, mid);
        string rstr = longestCommonPrefix(strs, mid + 1, h);
        return commonSubString(lstr, rstr);
    }

    string longestCommonPrefixDivideConcur(vector<string>& strs) {
        if (strs.size() == 0) return "";

        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }



    //############################################################################################
    //Approach Binary
    bool isCommonPrefix(vector<string>& strs, int len) {
        string str1 = strs[0].substr(0, len);
        //check str1 is the prefix of all strs[1] to strs[n-1]
        for (int i = 1; i < strs.size(); i++) {
            //str1.rfind(str2, 0) == 0: str1.startswith(str2)
            if (strs[i].rfind(str1, 0) != 0) return false;
        }
        return true;
    }
    string longestCommonPrefixBinary(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int _min = INT_MAX;
        for (string str : strs) _min = min(_min, (int)str.size());
        //use binary search to find 
        int low = 1, high = _min;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (isCommonPrefix(strs, middle)) {
                low = middle + 1;
            }
            else {
                high = middle - 1;
            }
        }
        //same result:
        // return strs[0].substr(0, (low+high)/2);
        return strs[0].substr(0, high);
    }
};

void test14()
{
    Solution14 sl;
    vector<string> strs{ "flower", "flow", "flight", "fly"};
    cout << sl.longestCommonPrefixDivideConcur(strs) << endl;
}
