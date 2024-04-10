#include <iostream>

using namespace std;

int digitCount(int num){
    int digits = 0;
    
    if (num == 0) {
        digits++;
        return digits;
    }
    
    while (num != 0) {
        digits++;
        num = num/10;
    }
    
    return digits;
}


int main(){
    
    int input;
    
    cout << "Please enter a number: ";
    cin >> input;
    
    
    cout << "The number " << input << " has " << digitCount(input) << " digits" << endl;
    
    return 0;
}
