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

    int arr[] = {2, 4, 6, 10, 14, 18};
    int size = 6;
    int key = 10;

    if(binarySearch(arr, 0, size - 1, key)) {
        cout << "Binary Search: Element " << key << " FOUND!" << endl;
    } else {
        cout << "Binary Search: Element " << key << " NOT found." << endl;
    }

    // 2. Linear Search
    if(linearSearch(arr, size, key)) {
        cout << "Linear Search: Element " << key << " FOUND!" << endl;
    } else {
        cout << "Linear Search: Element " << key << " NOT found." << endl;
    }

    //3. getsum
    int totalSum = getSum(arr, size);
    cout << "Sum of Array: " << totalSum << endl;

    // 4. isSorted
    if(isSorted(arr, size)) {
        cout << "Array Status: The array is SORTED." << endl;
    } else {
        cout << "Array Status: The array is NOT sorted." << endl;
    }

    string name = "abcde";
    string original = name; 
    
    reverseString(name, 0, name.length() - 1);
    cout << "Original: " << original << "  Reversed: " << name << endl;

    if(isPalindrome(name, 0, name.length() - 1)) {
        cout << name << " is a Palindrome" << endl;
    } else {
        cout << name << " is NOT a Palindrome" << endl;
    }
    
    int a = 2, b = 10;
    long long ans = power(a, b);
    cout << a << " to the power of " << b << " is: " << ans << endl;

    return 0;
}