#include <iostream>
#include "solver.h"

using namespace std;

void showMenu() {
    cout << "\n--- CPP DSA ENGINE ---" << endl;
    cout << "1. Anagram" << endl;
    cout << "2. Construct" << endl;
    cout << "3. Binary Search" << endl;
    cout << "4. Recursive Bubble Sort" << endl;
    cout << "5. Lineaar Search" << endl;
    cout << "6. Get Sum" << endl;
    cout << "7. Check If Sorted" << endl;
    cout << "8. Reverse String " << endl;
    cout << "9. Fast String Reversal (STL)" << endl;
    cout << "10. Palindrome " << endl;
    cout << "11. Power of X Check" << endl;
    cout << "0. Exit" << endl;
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

    default: {
        cout<<"Invalid choice!"<<endl;
        break;
    }
  
    }  
}  while(choice>0);

    return 0;
}