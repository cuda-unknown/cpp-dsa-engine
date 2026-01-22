#include <iostream>
#include "solver.h"

using namespace std;

int main() {
    cout << "--- DSA Engine: Logic Testing ---" << endl;

    // Test 1: Anagram
    if (isAnagram("anagram", "nagaram")) {
        cout << "[PASS] Anagram Logic Correct" << endl;
    } else {
        cout << "[FAIL] Anagram Logic Error" << endl;
    }

    // Test 2: Ransom Note
    if (canConstruct("aa", "aab")) {
        cout << "[PASS] Ransom Note Logic Correct" << endl;
    } else {
        cout << "[FAIL] Ransom Note Logic Error" << endl;
    }

    return 0;
}