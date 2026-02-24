#include <iostream>
#include "solver.h"

using namespace std;

void showMenu() {
    cout << "\n--- CPP DSA ENGINE ---" <<endl;
    cout << "1.  Anagram" <<endl;
    cout << "2.  Construct" <<endl;
    cout << "3.  Binary Search" <<endl;
    cout << "4.  Recursive Bubble Sort" <<endl;
    cout << "5.  Lineaar Search" <<endl;
    cout << "6.  Get Sum" <<endl;
    cout << "7.  Check If Sorted" <<endl;
    cout << "8.  Reverse String " <<endl;
    cout << "9.  Fast String Reversal (STL)" <<endl;
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
    cout << "23. Valid Palindrom"<<endl;
    cout << "24. Move Zeroes"<<endl;
    cout << "25. Rotate Array"<<endl;
    cout << "26. Square Root"<<endl;
    cout << "27. Merge Sorted Array"<<endl;
    cout << "28. Contains Duplicate"<<endl;
    cout << "29. Compress"<<endl;
    cout << "30. Best time to buy ans sell stocks"<<endl;
    cout << "31. Build Array from Permutation"<<endl;
    cout << "32. Running Sum of 1D Array"<<endl;
    cout << "33. Two Sum II-Input Array is Sorted"<<endl;
    cout << "34. How Many Numbers Are Smaller Than the Current Number."<<endl;
    cout << "35. Shuffle the Array"<<endl;
    cout << "36. Jewels and Stones "<<endl;
    cout << "37. Find Value of Variables After Perfroming Operations "<<endl;
    cout << "38. Maximum Number of Words Found in Sentence"<<endl;
    cout << "39. Count Pairs Whose Sum is Less Than Target"<<endl;
    cout << "40. Number of Employees Who Met the Target"<<endl;
    cout << "41. Remove Element"<<endl;
    cout << "42. Find the Highest Altitude"<<endl;
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
    cout<<"How many numbers do you want to permute?(Keep it small, e.g., 3): ";
    cin>>count;

    vector<int> nums(count);
    cout<<"Enter the "<<count<<" numbers: ";
    for(int i=0;i<count;i++) cin>>nums[i];

    vector<vector<int>> result =permute(nums);

    cout<<"Total Permutations: " <<result.size()<<endl;
    for (const auto& row : result) {
        cout<<"[ ";
        for (int x : row) cout<< x<<" ";
        cout<<"] "<<endl;
    }
    break;
    }

    case 17: {
    int n;
    cout<<"Enter Maze size (N): "; 
    cin>>n;
    vector<vector<int>> maze(n, vector<int>(n));
    cout<<"Enter Maze (0/1):"<<endl;

    for(int i=0; i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>maze[i][j];
        }
    }

    vector<string> paths = findPath(maze, n);

    if(paths.empty()) cout<<"No paths exist!"<<endl;
    else {
        for(string p : paths) cout<<p<<" ";
        cout<<endl;
    }
    break;
    }

    case 18: {
    int n;
    cout<<"Enter a number to count primes up to: ";
    cin>>n;
    cout<<"Number of primes: "<<countPrimes(n)<<endl;
    break;
    }

    case 19: { 
    int n;
    cout<<"How many strings? ";
    cin>>n;
    vector<string> strs(n);
    cout<<"----Please keep your string lowercase---"<<endl;
    cout<<endl;
    cout<<"Enter the strings:"<<endl;
    for(int i=0;i<n;i++) cin>>strs[i];
    
    string prefix = longestCommonPrefix(strs);
    if(prefix.empty()) cout<<"No common prefix found."<<endl;
    else cout<<"Longest Common Prefix: "<<prefix<<endl;
    break;
    }

    // Roman to Integer #13
    case 20: { 
    string s;
    cout<<"Enter Roman Numeral (e.g., LV): ";
    cin>>s;
    cout<<"Integer Value: "<<romanToInt(s)<<endl;
    break;
    }

    case 21: {
    int r,c;
    cout<<"Enter Grid dimensions (Rows Cols): ";
    cin>>r>>c;
    vector<vector<int>> grid(r, vector<int>(c));
    cout<<"Enter Gold values for each cell:"<<endl;
    for(int i=0;i<r;i++) 
        for(int j=0;j<c;j++) cin>>grid[i][j];

    cout<<"Maximum Gold Collected: "<<getMaximumGold(grid) <<endl;
    break;
    }

    case 22: {
    int n;
    cout<<"Enter Board Size (e.g., 4): ";
    cin>>n;
    vector<vector<string>> solutions = solveNQueens(n); 
    
    cout<<"Found "<<solutions.size()<<" solutions:"<<endl;
    for(auto board : solutions) {
        for(string row : board) {
            cout<<row<<endl;
        }
        cout<<"-----------"<<endl; 
    }
    break;
    }

    // Valid Palindrome #125
    case 23: {
    string s; cout<<"Enter string: "; cin.ignore(); getline(cin, s);
    if(isPalindrome(s)) cout<<"It's a Valid Palindrome!"<<endl;
    else cout<<"Not a Palindrome."<<endl;
    break;
    }

    // Move Zoroes #283
    case 24: {
    vector<int> nums = {0, 1, 0, 3, 12};
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    moveZeroes(nums);
    cout << "Moved Zeroes: ";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    } 
    break;
    }
    
    // Rotate Array #189
    case 25: {
    int n, k;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements:";
    for(int i=0;i<n;i++) cin>>nums[i];
    
    cout<<"Enter rotation steps (k):";
    cin>>k;

    rotate(nums, k);

    cout<<"Rotated Array: ";
    for(int x:nums) cout<<x<<" ";
    cout<<endl;
    break;
    }

    //#69 sqrt
    case 26: {
    int n;
    cout << "Enter a number to find its square root (floor): ";
    
    if (!(cin >> n)) {
        cout << "Invalid input." << endl;
        return 1;
    }

    if (n < 0) cout << "Square root of negative numbers involves 'i' (imaginary numbers)!" << endl;
    else  cout << "The square root of " << n << " is approximately: " << mySqrt(n) << endl;
    
    break;    
    }

    //#88 
    case 27: { 
    int m,n;
    cout<<"Enter size of nums1 (valid elements): ";
    cin>>m;
    cout<<"Enter size of nums2: "; 
    cin>>n;
    
    vector<int> nums1(m+n);
    vector<int> nums2(n);
    
    cout<<"Enter "<<m<<" elements for nums1: ";
    for(int i=0;i<m;i++) 
    cin>>nums1[i];
    
    cout<<"Enter "<<n<<" elements for nums2: ";
    for(int i=0;i<n;i++) 
    cin>>nums2[i];

    merge(nums1,m,nums2,n);

    cout<<"Merged Array: ";
    for(int x : nums1) 
    cout<< x << " ";
    cout<<endl;
    break;
    }
    
    //#217
    case 28: {
    vector<int> nums = {1, 2, 3, 1};

    cout<<"Duplicate Check "<<endl;
    cout<<endl;
    cout<<"The result is:"<<" ";
    
    if (containsDuplicate(nums))   cout<<"Duplicate found"<<endl;
    else   cout <<"All elements are unique"<<endl;
    break;
    }

    // #443 string compress
    case 29: {
    string s; 
    cout << "Enter string to compress: "; 
    cin >> s;

    vector<char> chars(s.begin(), s.end());
    int newSize = compress(chars);

    cout << "Compressed: ";
    for(int i=0; i<newSize; i++){
     cout << chars[i];
    }
    cout << "\nNew Size: " << newSize << endl;
    break;
    }
    
    //#121 
    case 30: {

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    int result = maxProfit(prices);
    
    cout << "Input Prices: [7, 1, 5, 3, 6, 4]" << endl;
    cout << "Maximum Profit: " << result << " (Buy at 1, Sell at 6)" << endl;
    break;
    }
    
    //#1920 Build Array from Permutation
    case 31: {
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    
    cout<<" Array Permutation "<<endl;
    cout<<endl;
    cout<<"Input Array:  ";
    for(int x : nums) 
    cout<<x<<" ";
    cout<<endl;

    vector<int> result = buildArray(nums);

    cout<<"Output Array: ";
    for(int x : result) 
    cout<<x<<" ";
    cout<<endl;
    break;
    }
    
    //#1480
    case 32: {
    vector<int> nums ={1,1,1,1,1};
    
    cout<<" Running Sum Solver "<<endl;
    cout<<"Original Array"<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    vector<int> result =runningSum(nums);
    
    cout<<"Result: ";
    for (int x : result) cout<<x<<" ";
    cout<<endl;
    break;
    }

    //#167 
    case 33: {
        vector<int> numbers = {2,7,11,15};
        int target=9;
        cout<<" Two Sum II "<<endl;
        cout<<" Original Array "<<endl;
        for(int i=0;i<numbers.size();i++){
        cout<<numbers[i]<<" ";
        }
        cout<<endl;
        cout<<"Target is:"<<target<<endl;
        vector<int> result= twoSum(numbers,target);
        cout<<" Result:";
        for(int x:result) cout<<x<<" ";
        cout<<endl;
        break;
    }

    //#1365 
    case 34: {
    vector<int> nums = {8, 1, 2, 2, 3};
    cout<<" Original Array:"<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    vector<int> result = smallerNumbersThanCurrent(nums);

    cout << "Counts of smaller numbers: ";
    cout<<endl;
    for(int x : result) cout << x << " ";
    cout << endl;
    break;
    }

    //#1470 Shuffle the Array
    case 35: {
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;
    cout<<" Original Array "<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    cout<<" Result "<<endl;
    
    vector<int> result = shuffle(nums, n);
    
    for(int x : result) cout << x << " ";
    break;
    }

    //#771
    case 36: {
    string jewels = "aA", stones = "aAAbbbb";
    
    cout << "--- Jewel Counter ---" << endl;
    cout << "Total Jewels found: " << numJewelsInStones(jewels, stones) << endl;
    break;
    }

    //#2011
    case 37: {
    vector<string> ops = {"--X", "X++", "X++"};

    cout << "--- Variable Operation Solver ---" << endl;
    
    int result = finalValueAfterOperations(ops);

    cout << "Input Operations: ";
    for (const string& s : ops) cout << s << " ";
    
    cout << "\nFinal Value of X: " << result << endl;
    break;
    }

    //#2114
    case 38: {
    vector<string> sentences = {
        "alice and bob love leetcode", 
        "i think so too", 
        "this is great thanks very much"
    };

    cout << "--- Word Counter Engine ---" << endl;
    int result = mostWordsFound(sentences);

    cout << "Sentences analyzed: " << sentences.size() << endl;
    cout << "Max words in a single sentence: " << result << endl;

    break;
    }

    //#2824
    case 39: {
        vector<int> nums = {-1,1,2,3,1};
        int target = 2;
        cout<<"---Pair Counter---"<<endl;
        cout<<" Original Array "<<endl;
        for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
        }
        cout<<endl;

        cout<<"Result :"<<" ";
        
        int Result=countPairs(nums,target);
        cout<<Result;
        break;
    }

    //#2798
    case 40: {
        vector<int> hours = {0,1,2,3,4};
        int target = 2;
         cout<<" Number of Hours Employees Worked "<<endl;
        for(int i=0;i<hours.size();i++){
        cout<<hours[i]<<" ";
        }
        cout<<endl;
        cout<<"Employees Who Did Desired Hours Of Work: "<<" ";
        int Result=numberOfEmployeesWhoMetTarget(hours,target);
        cout<<Result;
        break;
    }

    //#27 Remove Element
    case 41: {
    vector<int> nums = {3, 2, 2, 3};
    int val=3;

    cout<<"--- Element Remover---"<<endl;
    int k=removeElement(nums,val);

    cout<<"New Length: "<<k<<endl;
    cout << "Modified Array: ";
    for (int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    break;
    }

    //#1732 Find the Highest Altitude
    case 42: {
    vector<int> gain = {-5, 1, 5, 0, -7};
    cout<<"---Altitude Tracker---"<<endl;
    int result=largestAltitude(gain);
    
    cout<<"Highest Point Reached:"<<result<<endl;
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