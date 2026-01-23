#ifndef SOLVER_H
#define SOLVER_H

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

#endif