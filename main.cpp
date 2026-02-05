#include <iostream>
#include "solver.h"

using namespace std;

void showMenu() {
    cout << "\n--- CPP DSA ENGINE ---" <<endl;
    cout << "1. Anagram" <<endl;
    cout << "2. Construct" <<endl;
    cout << "3. Binary Search" <<endl;
    cout << "4. Recursive Bubble Sort" <<endl;
    cout << "5. Lineaar Search" <<endl;
    cout << "6. Get Sum" <<endl;
    cout << "7. Check If Sorted" <<endl;
    cout << "8. Reverse String " <<endl;
    cout << "9. Fast String Reversal (STL)" <<endl;
    cout << "10. Palindrome " <<endl;
    cout << "11. Power of X Check" <<endl;
    cout << "12. Merge Sort" <<endl;
    cout << "13. Quick Sort" <<endl;
    cout << "14. Subsets" <<endl;
    cout << "15. Keypad PRoblem" <<endl;
    cout << "16. Permutation" <<endl;
    cout << "17. Rat in a maze" << endl;
    cout << "18. Count Prime" <<endl;
    cout << "19. Longest Common Prefix"<<endl;
    cout << "20. Roman to Integers"<<endl;
    cout << "21. Max Gold "<<endl;
    cout << "22. N Queen Poblem"<<endl;
    cout << "0. Exit" <<endl;
    cout << "Enter choice: ";
}

int main() {

    int choice;
   do{
        showMenu();
        cin >> choice;
    if(choice ==0) break;
        switch(choice) {
    case 1:{
    if (isAnagram("anagram", "nagaram")) {
        cout << "[PASS] Anagram Logic Correct" << endl;
    } else {
        cout << "[FAIL] Anagram Logic Error" << endl;
    }
    break;
    }

    case 2:{
    if (canConstruct("aa", "aab")) {
        cout << "[PASS] Ransom Note Logic Correct" << endl;
    } else {
        cout << "[FAIL] Ransom Note Logic Error" << endl;
    }
    break;
    }

    case 3:{
    int arr[] = {2, 4, 6, 10, 14, 18};
    int size = 6;
    int key = 10;
    if(binarySearch(arr, 0, size - 1, key)) {
        cout << "Binary Search: Element " << key << " FOUND!" << endl;
    } else {
        cout << "Binary Search: Element " << key << " NOT found." << endl;
    }
    break;
    }

    case 4:{
    int arr2[]={4,9,7,3,5,2,0,1};
    int n=8;
    bubbleSort(arr2,n);
    cout<<"Sorted Array is :"<<endl;
    for(int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    break;
    }
    case 5:{
    int arr[] = {2, 4, 6, 10, 14, 18};
    int size = 6;
    int key = 10;
    if(linearSearch(arr, size, key)) {
        cout << "Linear Search: Element " << key << " FOUND!" << endl;
    } else {
        cout << "Linear Search: Element " << key << " NOT found." << endl;
    }
    break;
    }
    
    case 6:{  
    int arr[] = {2, 4, 6, 10, 14, 18};
    int size = 6;
    int totalSum = getSum(arr, size);
    cout << "Sum of Array: " << totalSum << endl;
    break;
    }

    case 7:{
    int arr[] = {2, 4, 6, 10, 14, 18};
    int size = 6;
    if(isSorted(arr, size)) {
        cout << "Array Status: The array is SORTED." << endl;
    } else {
        cout << "Array Status: The array is NOT sorted." << endl;
    }
    break;
    }

    case 8:{
    string name = "abcde";
    string original = name; 
    reverseString(name, 0, name.length() - 1);
    cout << "Original: " << original << "  Reversed: " << name << endl;
    break;
    }
 
    case 9:{
    string sa="abcdeedcb";
    string Real=sa;
    reverseStringFast(sa);
    cout<<"Real string is:"<<Real<<" "<<"Fast reverse is:"<<sa <<endl;
    break;
    }

    case 10:{
    string name = "abcde";
    if(isPalindrome(name, 0, name.length() - 1)) {
        cout << name << " is a Palindrome" << endl;
    } else {
        cout << name << " is NOT a Palindrome" << endl;
    }
    break;
    }

    case 11:{
    int a = 2, b = 10;
    long long ans = power(a, b);
    cout << a << " to the power of " << b << " is: " << ans << endl;
    break;
    }

    case 12: {
    int arr[] = {3, 41, 52, 26, 38, 57, 9, 49};
    int n = 8;
    mergeSort(arr, 0, n - 1);
    cout << "Merge Sorted Array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    break;
    }

    case 13:{
        int arr[]={24, 18, 38, 43, 14, 40, 1, 54};
        int n=8;
        quickSort(arr, 0, n - 1);
        cout << "Quick Sorted Array: ";
        for(int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
        break;
    }
    
    case 14: {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;
    solveSubsets(nums, output, 0, ans);
    
    cout << "Subsets are: " << endl;
    for (const auto& subset : ans) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "} ";
    }
    cout << endl;
    break;
    }

    case 15: {
    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> combinations = letterCombinations(digits);

    cout << "Possible combinations for '" << digits << "':" << endl;
    if (combinations.empty()) {
        cout << "[Empty Input or No Combinations]" << endl;
    } else {
        for (int i = 0; i < combinations.size(); i++) {
            cout << combinations[i] << (i == combinations.size() - 1 ? "" : ", ");
            // Adding a newline every 6 combinations to keep it readable
            if ((i + 1) % 6 == 0) cout << endl;
        }
    }
    cout << "\nTotal combinations: " << combinations.size() << endl;
    break;
    }
    
    case 16:{
    
    int count;
    cout << "How many numbers do you want to permute? (Keep it small, e.g., 3): ";
    cin >> count;

    vector<int> nums(count);
    cout << "Enter the " << count << " numbers: ";
    for(int i = 0; i < count; i++) cin >> nums[i];

    vector<vector<int>> result = permute(nums);

    cout << "Total Permutations: " << result.size() << endl;
    for (const auto& row : result) {
        cout << "[ ";
        for (int x : row) cout << x << " ";
        cout << "] " << endl;
    }
    break;
    }

    case 17: {
    int n;
    cout << "Enter Maze size (N): "; 
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter Maze (0/1):" << endl;

    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> maze[i][j];

    vector<string> paths = findPath(maze, n);

    if(paths.empty()) cout << "No paths exist!" << endl;
    else {
        for(string p : paths) cout << p << " ";
        cout << endl;
    }
    break;
    }

    case 18: {
    int n;
    cout << "Enter a number to count primes up to: ";
    cin >> n;
    cout << "Number of primes: " << countPrimes(n) << endl;
    break;
    }

    case 19: { 
    int n;
    cout << "How many strings? ";
    cin >> n;
    vector<string> strs(n);
    cout<<"----Please keep your string lowercase---"<<endl;
    cout<<endl;
    cout << "Enter the strings:" << endl;
    for(int i=0; i<n; i++) cin >> strs[i];
    
    string prefix = longestCommonPrefix(strs);
    if(prefix.empty()) cout << "No common prefix found." << endl;
    else cout << "Longest Common Prefix: " << prefix << endl;
    break;
    }

    // Roman to Integer
    case 20: { 
    string s;
    cout << "Enter Roman Numeral (e.g., LV): ";
    cin >> s;
    cout << "Integer Value: " << romanToInt(s) << endl;
    break;
    }

    case 21: {
    int r, c;
    cout << "Enter Grid dimensions (Rows Cols): ";
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    cout << "Enter Gold values for each cell:" << endl;
    for(int i=0; i<r; i++) 
        for(int j=0; j<c; j++) cin >> grid[i][j];

    cout << "Maximum Gold Collected: " << getMaximumGold(grid) << endl;
    break;
    }

    case 22: {
    int n;
    cout << "Enter Board Size (e.g., 4): ";
    cin >> n;
    vector<vector<string>> solutions = solveNQueens(n); 
    
    cout << "Found " << solutions.size() << " solutions:" << endl;
    for(auto board : solutions) {
        for(string row : board) {
            cout << row << endl;
        }
        cout << "-----------" << endl; 
    }
    break;
    }

    default: {
        cout<<"Invalid choice!"<<endl;
        break;
    }
  
    }  
    
    }  while(choice>0);

    return 0;
}