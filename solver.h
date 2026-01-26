#ifndef SOLVER_H
#define SOLVER_H
#include<algorithm>
#include <string>
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

//  Optimized Power Function (a^b)
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

void mergeSort(int arr[], int s, int e) {
    if(s >= e) return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

#endif