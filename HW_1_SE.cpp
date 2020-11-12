#include <iostream>
using namespace std;
#include <cmath> //Required to use pi as M_PI
#include <ctime> //Required to generate different random numbers in the table of Ex. 2


void circumference(){
    /* Exercise 1
    Compute area and perimeter of a circle given the radius */
    cout << "....... Exercise 1 .......\n\n";

    float r;
    cout << "Enter the radius of the circle: ";

    // To check that the user input is a number
    while (!(cin >> r)) {
        cout << "Please, enter a number: ";
        cin.clear();
        cin.ignore(100, '\n');
}
    // Output
    cout << "\nThe perimeter of the circle is: " << (2.0*M_PI*r);
    cout << "\nThe area of the circle is: " << (M_PI*pow(r, 2));

    cout << "\n\n....... End of Exercise 1 .......\n\n";
}

// Define the dimensions of the table used in exercise 2
#define rows 2
#define cols 4
// Complementary functions to fill and display the table
void fill_array(int arr[rows][cols]);
void display_array(int arr[rows][cols]);

void find_min_max(int arr[rows][cols]) {
    /* Exercise 2
    Calculate min and max of a given table */
    cout << "....... Exercise 2 .......\n\n";

    int min_v = arr[0][0];
    int max_v = min_v;
    // Main loop
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            if (arr[i][j] > max_v) {
                max_v = arr[i][j];
            } else if (arr[i][j] < min_v) {
                min_v = arr[i][j];
            }
        }
    }
    // Output
    cout << "\nThe maximum value of the table is: " << max_v;
    cout << "\nThe minimum value of the table is: " << min_v;

    cout << "\n\n....... End of Exercise 2 .......\n\n";
}

void fib_seq(){
     /* Exercise 3
    Generate Fibonnaci sequence */
    cout << "....... Exercise 3 .......\n\n";

    int rank;
    cout << "Introduce the rank of the Fibonacci sequence: ";

    // To check that the user input is a number
    while (!(cin >> rank)) {
        cout << "Please, enter a number: ";
        cin.clear();
        cin.ignore(100, '\n');}

    // Main loop
    int arr[rank] = {};
    if (rank>=1) {
        arr[1] = 1;
        for (int i=2; i<rank; i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }
    }
    // Output
    for (int i=0; i<rank; i++){
        cout << arr[i] << " ";
    }
    cout << "\n\n....... End of Exercise 3 .......\n\n";
}

void mult_table(){
     /* Exercise 4
    Generate multiplication tables */
    cout << "....... Exercise 4 .......\n\n";

    int numb;
    cout << "Introduce the number of the multiplication table: ";

    // To check that the user input is a number
    while (!(cin >> numb)) {
        cout << "Please, enter a number: ";
        cin.clear();
        cin.ignore(100, '\n');}

    // Main Loop & Output
    for (int i=0; i<=10; i++){
        cout << "\n" << numb << " * " << i << " = " << numb*i;
    }
    cout << "\n\n....... End of Exercise 4 .......\n\n";
}

void truth_table(){
     /* Exercise 5
    Generate truth tables for 3 inputs */
    cout << "....... Exercise 5 .......\n\n";

    bool type;
    cout << "Introduce the type of truth table (0 for AND, 1 for OR): ";

    // To check that the user input is either 0 or 1
    while (!(cin >> type)) {
        cout << "Please, enter a valid number (either 0 or 1): ";
        cin.clear();
        cin.ignore(100, '\n');}

    cout << "\nA\tB\tC\tY\n";
    bool a, b, c;
    // Main loop & Output
    for (int i=0; i<8; i++){
        a = i>=4;
        b = (i%4)>=2;
        c = (i%2)!=0;
        cout << a << "\t" << b << "\t" << c << "\t";
        switch(type) {
        case 0:
            cout << (a&&b&&c) << "\n";
            break;
        case 1:
            cout << (a||b||c) << "\n";
        }
    }
    cout << "\n\n....... End of Exercise 5 .......\n\n";
}


int main(){
    // Exercise 1
    circumference();

    // Exercise 2
    int array_n[rows][cols];
    fill_array(array_n);
    display_array(array_n);
    find_min_max(array_n);

    // Exercise 3
    fib_seq();

    // Exercise 4
    mult_table();

    // Exercise 5
    truth_table();

    return 0;
}


void fill_array(int arr[rows][cols]) {
    srand((int) time(0));
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            arr[i][j] = rand() % 542 + 1;
        }
    }
}

void display_array(int arr[rows][cols]){
    cout << "Table display:\n\n";
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}
