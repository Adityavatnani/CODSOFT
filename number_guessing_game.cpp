#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand(time(0));

    // generate random number from 0 to 10
    int ran = rand() % 10 + 1;

    int guess, i = 1;

    cout<<"\n" << "\t" <<"!!! Let's Beginning The Game !!!"<< endl;

    // this gives the chances to the user and print the output
    while(i <= 3)
    {
        cout << "Enter Your Guess: " ;

        cin >> guess;

        cout << "\n";

        if(guess < ran)
        {
            cout << "!! Too Small !! \n" << endl;
        }

        if(guess > ran)
        {
            cout << "!! Too Large !! \n" << endl;
        }

        if(guess == ran){
            cout << "!! Correct !! \n" << endl;
            break;
        }

        i++;

        if(i == 4)
        {
            cout <<"\n" << "!! Better Luck Next Time !! \n" ;
            break;
        }
    }
}