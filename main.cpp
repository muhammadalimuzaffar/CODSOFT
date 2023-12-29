#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int range = 50;
    int num, n;
    int attempts = 0;

    srand(time(0));
    num = rand()%range;
    cout << "Welcome to the Number Guessing Game!\n\n";
    cout << "Try to guess number between 1 and 50\n\n";

    do{
    cout << "Enter your Guess:\n";
    cin >> n;
    attempts++;

    if (n<num)
        cout << "\nThe guess is too low\n\n";
    else if (n>num)
        cout << "\nThe guess is too high\n\n";
    else if (n=num)
        cout << "\nCongratulations! You guessed the correct number in " << attempts << " attempts.\n";
}
    while (n != num);
    return 0;
}
