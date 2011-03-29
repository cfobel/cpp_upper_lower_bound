// Example from: http://www.cplusplus.com/reference/algorithm/lower_bound/
// lower_bound/upper_bound example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>::iterator checked_upper_bound(vector<int>::iterator begin,
        vector<int>::iterator end, int value) {
    vector<int>::iterator up = upper_bound(begin, end, value);
    if(up == end) {
        cout << value << " is greater than last value: " << *(end - 1) << endl;
    } else {
        cout << "upper_bound at position " << int(up - begin) << endl;
    }
    return up;
}


vector<int>::iterator checked_lower_bound(vector<int>::iterator begin,
        vector<int>::iterator end, int value) {
    vector<int>::iterator low = lower_bound(begin, end, value);
    if(low == end) {
        cout << value << " is greater than last value: " << *(end - 1) << endl;
    } else if(*low != value) {            
        cout << value << " is less than first value: " << *begin << endl;
    } else {
        cout << "lower_bound at position " << int(low - begin) << endl;
    }
    return low;
}


int main () {
    int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};
    vector<int> v(myints, myints + 8);          // 10 20 30 30 20 10 10 20
    vector<int>::iterator low, up;

    sort(v.begin(), v.end());                   // 10 10 10 20 20 20 30 30

    low = lower_bound(v.begin(), v.end(), 20);  //          ^
    up = upper_bound(v.begin(), v.end(), 20);   //                   ^

    cout << "lower_bound at position " << int(low - v.begin()) << endl;
    cout << "upper_bound at position " << int(up - v.begin()) << endl;

    cout << endl;

    checked_lower_bound(v.begin(), v.end(), 5);
    checked_lower_bound(v.begin(), v.end(), 20);
    checked_lower_bound(v.begin(), v.end(), 40);

    cout << endl;

    checked_upper_bound(v.begin(), v.end(), 5);
    checked_upper_bound(v.begin(), v.end(), 20);
    checked_upper_bound(v.begin(), v.end(), 40);

    return 0;
}
