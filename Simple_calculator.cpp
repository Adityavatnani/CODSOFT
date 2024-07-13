#include <iostream>

using namespace std;

int main()
{
        int op1, op2, choice;

        cout << "Enter Your First Number: ";

        cin >> op1;

        cout << "\nEnter Your Second Number: ";

        cin >> op2;

        cout << "\n1. Addition" << "\n2. Substration" << "\n3. Multiplication" << "\n4. Division\n";

        cout << "\nEnter the operator (as given above): ";

        cin >> choice;

        // this code print the output
        switch (choice)
        {
        case 1:
                cout << "\nAddition: " << op1 + op2;
                break;

        case 2:
                cout << "\nSubstration: " << op1 - op2;
                break;

        case 3:
                cout << "\nMultiplication: " << op1 * op2;
                break;

        case 4:
                cout << "\nDivision: " << op1 / op2;
                break;

        default:
                cout << "\n!! Invaild Choice !!";
                break;
        }
}