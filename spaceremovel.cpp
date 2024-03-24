#include <iostream>
using namespace std;

string remover_internal(string str) {
    string temp;
    int left = 0;
    int right = str.length() - 1;
    bool l1 = false;
    bool r1 = false;
    
    while (left <= right) {
        if (str[left] == ' ' && !l1) {
            left++;
        } else {
            temp += str[left];
            l1 = true;
        }
        
        if (str[right] == ' ' && !r1) {
            right--;
        } else {
            temp += str[right];
            r1 = true;
        }
        
        left++;
        right--;
    }
    
    return temp;
}

int main() {
    string str = "   usman is back  ";
    string remove_space = remover_internal(str);
    cout << remove_space << endl;
    return 0;
}
