/*Ian Delgado
Joseph Jess
CS 260
January 5th 2020 */
#include <iostream>
#include <string>

using namespace std;
using std::cout;
using std::cin;
using std::string;

//create a arrary based bag of marbles 



int main(){
    int marbles = 0;
    int marblesOut = 0;
    int bagOfMarbles[100];
    cout << "How many marbles would you like to add to the bag? ";
    cin >>  marbles;
    bagOfMarbles[0] = marbles;
    cout << "How many marbles you like to take out of the bag? ";
    cin >> marblesOut;
    bagOfMarbles[0] = marbles - marblesOut;
    cout << "You have " << bagOfMarbles[0] << " " << "marbles";
    return 0;

} 

