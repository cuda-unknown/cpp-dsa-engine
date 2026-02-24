#ifndef SOLVER_H
#define SOLVER_H
#include<algorithm>
#include <string>
#include<vector>
#include <unordered_map>
#include<unordered_set>

using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    int count[26] = {0};
    for(int i = 0; i < s.length(); i++) {
        count[s[i]-'a']++;
        count[t[i]-'a']--;
    }
    for(int ans : count) if(ans != 0) return false;
    return true;
}

bool canConstruct(string ransomNote, string magazine) {
    if(ransomNote.length() > magazine.length()) return false;
    int count[26] = {0};
    for(int i=0;i< magazine.length();i++) count[magazine[i]-'a']++;
    for(int i=0;i<ransomNote.length();i++) {
        count[ransomNote[i]-'a']--;
        if(count[ransomNote[i]-'a'] < 0) return false;
    }
    return true;
}

bool binarySearch(int *arr, int s, int e , int k ) {

    if(s>e)
        return false;

    int mid = s + (e-s)/2;

    if(arr[mid] == k)
        return true;

    if(arr[mid] < k) {
        return binarySearch(arr, mid+1, e, k);
    }
    else{
        return binarySearch(arr, s, mid-1, k);
    }
}

void bubbleSort(int arr2[],int n){
    if(n==0||n==1) return ;
    for(int i=0;i<n-1;i++){
        if(arr2[i]>arr2[i+1]){
            swap(arr2[i],arr2[i+1]);
        }
    }
    bubbleSort(arr2,n-1);
}

bool linearSearch(int arr[], int size, int k ) {
   
    if(size == 0) return false;

    if(arr[0] == k) return true;
    
    else {
        bool remainingPart = linearSearch(arr+1, size-1, k );
        return remainingPart;
    }
}

int getSum(int *arr, int size) {

    if(size == 0)  return 0;

    if(size == 1 ) return arr[0];

    int remainingPart = getSum(arr+1, size-1);
    int sum = arr[0] + remainingPart;
    return sum;
}

bool isSorted(int arr[], int size) {

    if(size == 0 || size == 1 )  return true;

    if(arr[0] > arr[1])  return false;
   
    else {
        bool remainingPart = isSorted(arr + 1, size - 1 );
        return remainingPart;
    }
}

// Using Recursion to Reverse String 
void reverseString(string& s, int i, int j) {
    if(i > j) return;
    swap(s[i], s[j]);
    reverseString(s, i + 1, j - 1);
}

 // Fast for Reversing String 
 void reverseStringFast(string&sa){
    reverse(sa.begin(),sa.end());
 }

// Recursive Palindrome Check
bool isPalindrome(string s, int i, int j) {
    if(i > j) return true;
    if(s[i] != s[j]) return false;
    return isPalindrome(s, i + 1, j - 1);
}

// Power Function (a^b)
long long power(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    
    long long ans = power(a, b/2);
    
    if(b % 2 == 0) return ans * ans; 
    else return a * ans * ans;       
}

// Merge Sort
void merge(int arr[], int s, int e) {
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //Merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int s, int e) {
    if(s >= e) return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

// Quick Sort
int partition(int arr[], int s, int e) {
    int pivot = arr[s];

    // step1: count elements smaller than pivot
    int cnt = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            cnt++;
        }
    }

    // step 2: place pivot at its right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // step 3: handle left and right parts (left < pivot, right > pivot)
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    // base case
    if (s >= e) return;

    // partitioning
    int p = partition(arr, s, e);

    // sort left part
    quickSort(arr, s, p - 1);

    // sort right part
    quickSort(arr, p + 1, e);
}

// Subsets
void solveSubsets(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans) {
        //base case
    if(index >= nums.size()) {
        ans.push_back(output);
        return ;
    }
        
        //exclude
    solveSubsets(nums, output, index+1, ans);
        
        //include
    int element = nums[index];
    output.push_back(element);
    solveSubsets(nums, output, index+1, ans);
        
}

// Keypad Problem
void solveletter(string digit, string output, int index, vector<string>& ans, string mapping[] ) {     
    //base case
    if(index >= digit.length()) {
        ans.push_back(output);
        return;
    }
        
    int number = digit[index] - '0';
    string value = mapping[number];
        
    for(int i=0; i<value.length(); i++) {
        output.push_back(value[i]);
        solveletter(digit, output, index+1, ans, mapping);
        output.pop_back();
    }     
}
vector<string> letterCombinations(string digits) {
    
    vector<string> ans;
    
    if(digits.length()==0)
        return ans;

    string output;
    int index = 0;

    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
    solveletter(digits, output, index, ans, mapping);
        
    return ans;
}

// Permutation
void solvepermute(vector<int>& nums, vector<vector<int>>& ans, int index) {
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++) {
        swap(nums[index], nums[j]);      
        solvepermute(nums, ans, index + 1); 
        swap(nums[index], nums[j]);     
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    solvepermute(nums, ans, 0);
    return ans;
}

// Rat in Maze
bool issafe(int x,int y,int n,vector<vector<int>> &visited,vector<vector<int>>& m){
    if( (x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
        return true;
    }else {
        return false;
    }
}
void solveMaze(vector<vector<int>>& m,int n, vector<string> &ans, int x,int y,vector<vector<int>>&visited,string path ){
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y]=1;

    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};

    char dir[] = {'D', 'L', 'R', 'U'};

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (issafe(nextX, nextY, n, visited, m)) {
            path.push_back(dir[i]);
            solveMaze(m, n, ans, nextX, nextY, visited, path);
            path.pop_back();
        }
    }
    visited[x][y]=0;
}
vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    if(m[0][0] == 0 || m[n-1][n-1] == 0)  return ans;

    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    string path = "";

    solveMaze(m, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

//Sieve of E
int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            count++;
            for (long long j = (long long)i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
    return count;
}

// Longest Common Prefix
string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    if(strs.empty()) return ans;
    sort(strs.begin(), strs.end());

    string first = strs[0],last = strs[strs.size() - 1];

    for(int i = 0; i < first.length(); i++) {
        if(first[i] == last[i]) {
            ans += first[i];
        } else {
            break; 
        }
    }
    return ans;
} 

// #13 Roman to Integer #13 
int romanToInt(string s) {
    unordered_map<char, int> m = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int ans = 0;
    for(int i=0; i<s.length(); i++) {
        if(i < s.length()-1 && m[s[i]] < m[s[i+1]]) ans -= m[s[i]];
        else ans += m[s[i]];
    }
    return ans;
}

// #1219
int solveGold(vector<vector<int>>& grid, int x, int y, int r, int c) {
    // Boundary check + no gold (0) check
    if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] == 0) return 0;

    int currentGold = grid[x][y];
    grid[x][y] = 0; // mark visited (Backtracking)

    // check all 4 directions and pick the max
    int d = solveGold(grid, x + 1, y, r, c);
    int u = solveGold(grid, x - 1, y, r, c);
    int r_path = solveGold(grid, x, y + 1, r, c);
    int l = solveGold(grid, x, y - 1, r, c);

    grid[x][y] = currentGold; // restore for other paths
    return currentGold + max({d, u, r_path, l});
}
int getMaximumGold(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();
    int maxGold = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] > 0) {
                maxGold = max(maxGold, solveGold(grid, i, j, r, c));
            }
        }
    }
    return maxGold;
}

// #51 N Queen Problem
 bool isSafe(int row, int col, vector<string>& board, int n) {
        // 1. Check same column (above)
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // 2. Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // 3. Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q'; 
                solve(row + 1, n, board, ans); // Recurse
                board[row][col] = '.'; // Backtrack
            }
        }
    }

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, n, board, ans);
    return ans;
}


// Palindrome #125
bool isPalindrome(string s) {
    int st = 0, e = s.length() - 1;
    while (st <= e) {
        if (!isalnum(s[st])) st++;
        else if (!isalnum(s[e])) e--;
        else if (tolower(s[st]) != tolower(s[e])) return false;
        else { st++; e--; }
    }
    return true;
}

// Move zeroes #283
void moveZeroes(vector<int>& nums) {
    int i=0;
    for(int j=0;j<nums.size();j++){
        if(nums[j]!=0){
        swap(nums[j],nums[i]);
        i++;
        }
    }
}

// Rotate Array #189
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

// #69 sqrt
int mySqrt(int x) {
    if (x == 0) return 0;
    int s = 1, e = x, ans = 0;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (mid <= x / mid) {
            ans = mid;
            s = mid + 1;
        } 
        else e = mid - 1;
    }
    return ans;
}

// #88
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1,j=n-1,k=m+n-1;
    while (i>=0 && j>=0) {
        if (nums1[i]>nums2[j])  nums1[k--]=nums1[i--];
        else  nums1[k--] = nums2[j--];
        }
    while (j>=0) {
        nums1[k--]=nums2[j--];
    }
}

// #217 Contains Duplicate
bool containsDuplicate(vector<int>& nums) {
    if (nums.empty()) return false;
    
    sort(nums.begin(), nums.end());
    
    for (int i=0;i<nums.size()-1;i++) {
        if (nums[i]==nums[i+1]) return true;
    }
    return false;
}

// #443
int compress(vector<char>& chars) {
    int i = 0, ansIndex = 0, n = chars.size();
    while (i < n) {
        int j = i + 1;
        while (j < n && chars[i] == chars[j]) j++;
        chars[ansIndex++] = chars[i];
        int count = j - i;
        if (count > 1) {
            string cnt = to_string(count);
            for (char ch : cnt) chars[ansIndex++] = ch;
        }
        i = j;
    }
    return ansIndex;
}

// #121 Best time to Buy Sell Stocks
int maxProfit(vector<int>& prices){
    int min_price =1e9; 
    int max_profit =0;
        
    for (int i=0;i<prices.size();i++){
        if (prices[i] <min_price){
            min_price= prices[i];
        } 
        
        else{
            int current_profit= prices[i]-min_price;
            if (current_profit> max_profit){
                max_profit= current_profit;
            }
        }
    }   
    return max_profit; 
}

// #1920 Build Array from Permutation
vector<int> buildArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    for (int i=0;i<n;i++) {
        ans[i] =nums[nums[i]]; 
    }
    return ans;
}

// #1480 Running sum of 1 d array
vector<int> runningSum(vector<int>& nums) {
        // Start from 1, so i-1 is always at least 0
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        return nums;
    }

// Two Sum II #167 
vector<int> twoSum(vector<int>& numbers, int target) {
    int l=0;
    int r=numbers.size()-1;
        while(l<r){
            int sum= numbers[l]+numbers[r];
            if(sum==target) return {l+1,r+1};
            if(sum< target) l++;
            else r--;
        }
    return{};
}

// #1365 How Many Numbers Are Smaller Than the Current Number.
 vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> result;
    for(int i = 0; i < nums.size(); i++) {
        int count = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] < nums[i]) {
                count++;
            }
        }
        result.push_back(count);
    }
    return result;
}

//#1470 Shuffle the Array
vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> result(2 * n);
    for (int i = 0; i < n; i++) {
        result[2 * i] = nums[i];         // Place xi
        result[2 * i + 1] = nums[i + n]; // Place yi
    }
    return result;
}

//#771  jewels and stones 
int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> set(jewels.begin(),jewels.end());
    int count=0;
    for(char c:stones){
        if(set.count(c)) count++;
    }
    return count;
}

//#2011
int finalValueAfterOperations(vector<string>& operations) {
    int x=0;
    for(string s : operations){
        if(s[1] == '+') x++;
        else x--;
    }
    return x;
}

//#2114
int mostWordsFound(vector<string>& sentences) {
    int maxwords=0;
        for(string s:sentences){
            int spaces=0;
            for(char c: s){
            if(c==' ') spaces++;
            }
            maxwords=max(maxwords,spaces+1);
        }
    return maxwords;
}

//#2824
int countPairs(vector<int>& nums, int target) {
    int pairs=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i] + nums[j] < target) pairs++;
        }
    }
    return pairs;
}

//#2798
int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int count=0;
    for(int i:hours){
        if(i>=target) count++;
    }
    return count;
}

//#27
int removeElement(vector<int>& nums, int val) {
    sort(nums.begin(),nums.end());
    int l=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=val){
            nums[l]=nums[i];
            l++;
        }
    }
    return l;
}

//#1732: Find the Highest Altitude
int largestAltitude(vector<int>& gain) {
    int ans=0;
    int prev=0;
    for (int i=1;i<=gain.size();i++) {
        int current=prev+gain[i-1];
        ans=max(ans,current);
        prev=current;
    }
    return ans;
}


#endif