#ifndef SOLVER_H
#define SOLVER_H
#include<algorithm>
#include <string>
#include<vector>

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
 //Fast for Reversing String 
 void reverseStringFast(string&sa){
    reverse(sa.begin(),sa.end());
 }

//  Recursive Palindrome Check
bool isPalindrome(string s, int i, int j) {
    if(i > j) return true;
    if(s[i] != s[j]) return false;
    return isPalindrome(s, i + 1, j - 1);
}

//Power Function (a^b)
long long power(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    
    long long ans = power(a, b/2);
    
    if(b % 2 == 0) return ans * ans; 
    else return a * ans * ans;       
}

void merge(int arr[], int s, int e) {
    int mid = s + (e - s) / 2; // More stable against overflow

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

    // Merge 2 sorted arrays
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

//Merge Sort 
void mergeSort(int arr[], int s, int e) {
    if(s >= e) return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}


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

//Quick Sort
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

 //subsets
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


#endif