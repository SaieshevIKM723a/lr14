#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool is_divisor(int number, int potential_divisor) {
    return number % potential_divisor == 0;
}

int binary_search(vector<int> divisors, int divisor) {
    int low = 0;
    int high = divisors.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (divisors[mid] == divisor) {
            return mid;
        }
        else if (divisor < divisors[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1; 
}

int main() {
    int number;

    
    cout << "Enter a six-digit number: ";
    cin >> number;

    if (number < 100000 || number > 999999) {
        cout << "Incorrect number format. Please enter a six-digit number." << endl;
        return 1;
    }

   
    vector<int> divisors;
    for (int i = 1; i <= sqrt(number); ++i) {
        if (is_divisor(number, i)) {
            divisors.push_back(i);
            if (i != number / i) {
                divisors.push_back(number / i);
            }
        }
    }

    
   sort(divisors.begin(), divisors.end());

 
    int divisor_to_find;
    cout << "Enter the divisor you want to find: ";
    cin >> divisor_to_find;

  
    int index = binary_search(divisors, divisor_to_find);

    if (index != -1) {
        cout << "Divisor " << divisor_to_find << " found by index. " << index << endl;
    }
    else {
        cout << "Divisor " << divisor_to_find << " not founded." << endl;
    }

    return 0;
}
