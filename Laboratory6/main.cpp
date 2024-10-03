//
//  main.cpp
//  Laboratory6
//
//  Created by Luke Tinnermeier on 10/3/24.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

void lab6A();
void lab6B();
void lab6C();

int main(int argc, const char * argv[]) {

    int file;
    cout << "File identifier: ";
    cin >> file;
    
    switch(file) {
        case 1:
            lab6A();
            break;
        case 2:
            lab6B();
            break;
        case 3:
            lab6C();
            break;
    }
    
}

void lab6A() {
    int side_length;
    cout << "Enter a side length: ";
    cin >> side_length;
    
    if (side_length >= 3) {
        for (int rows = 0; rows < side_length; rows++) {
            for (int columns = 0; columns < (side_length * 2) + 1; columns++) {
                if (columns == side_length) {
                    cout << " ";
                } else if (columns > side_length && columns < side_length * 2) {
                    if (columns > side_length + 1 && rows > 0 && rows < side_length - 1) {
                        cout << " ";
                    } else {
                        cout << "*";
                    }
                } else {
                    cout << "*";
                }
            }
            cout << endl;
        }
    }
}

void lab6B() {
    int side_length;
    cout << "Enter number of asterisks per side: ";
    cin >> side_length;
    
    string top_triangle = "*";
    
    for (int i = 1; i <= side_length; i++) {
        for (int j = 0; j < side_length - i; j++) {
            cout << " ";
        }
        
        if (i != 1) {
            top_triangle += "**";
            cout << top_triangle;
        } else {
            cout << top_triangle;
        }
        cout << endl;
    }
    
    
    for (int i = 1; i < side_length; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        
    
        top_triangle.erase(top_triangle.length() - 2);
        
        cout << top_triangle;
        cout << endl;
    }
}

void lab6C() {
    double user_input_counter = 0;
    
    double user_input;
    double total_sum = 0;
    double total_sum_squared = 0;
    double user_average;
    double standard_deviation = 0;
    
    while(cin) {
        cout << "Enter a number (Press Q to quit): ";
        cin >> user_input;
        
        if (cin.fail()) {
            if (user_input_counter == 0) {
                
                cout << "No data to process - exiting." << endl;
                
            } else {
                
                user_average = total_sum / user_input_counter;
                
                standard_deviation = total_sum_squared - (1/user_input_counter) * (pow(total_sum, 2));
                standard_deviation = sqrt(standard_deviation / (user_input_counter - 1));
                
                cout << "Times ran: " << user_input_counter << " | Average: " << user_average << " | Standard Deviation: " << standard_deviation << endl;
            }
        } else {
            
            user_input_counter++;
            total_sum += user_input;
            total_sum_squared += pow(user_input, 2);
            
        }
     }
}
