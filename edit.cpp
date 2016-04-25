//
//  edit.cpp
//  FinalProject_2048
//
//  Created by Kionte Brown on 4/22/16.
//  Copyright © 2016 Kionte Brown. All rights reserved.
//

// viv
// sap

#include<iostream>
#include <ctime>
using namespace std;

int** gameBoard(int,int); // initilizes  the gameboard
int** tempGameBoard(int**,int,int); // copy over gameboard to copy
char command(char); // input function to control movements
bool checkMove(int**,int**,int,int); // checks if move is valid
int leftTranslate(int** arr,int rSize,int cSize); // left movement
int upTranslate(int** arr,int rSize,int cSize); // up movement
int rightTranslate(int** arr,int rSize,int cSize); // right movement
int downTranslate(int** arr,int rSize,int cSize); // down movement
bool gameOverCheck(int** arr,int rSize,int cSize); // check if there are no more posibble moves
int randomInput(int** arr,int rSize,int cSize); // finds empty location and inputs a '2'
void update(int** arr,int rSize,int cSize); // out puts new board

int main() {
    srand(time(0)); // starts up random num generator
    char move = ' '; // var for movemet
    int rSize = 0; // var for row size
    int cSize = 0; // var for column size
    
    cout << "How many rows? ";
    cin >> rSize; // row input
    cout << "How many columns? ";
    cin >> cSize; // col input
    
    int** arr = gameBoard(rSize,cSize); // sets the 2d array to the gameboard function
    randomInput(arr, rSize, cSize); // gets and sets initial number
    update(arr, rSize, cSize); // output initial board
    int** tempArr = tempGameBoard(arr, rSize, cSize); // sets up copy of board for later comparison
    while(move != 'q') { // while user doesnt quit
        switch (command(move)) { // runs the command function and detemrines a case based off return value
            case 'a':
                tempArr = tempGameBoard(arr, rSize, cSize); // copys board for later comparison
                **arr = leftTranslate(arr,rSize,cSize); // attempts to make move to left
                if(checkMove(arr, tempArr, rSize, cSize)) { // checks if move is valid if it is contine if not try a different move
                    if(gameOverCheck(arr, rSize, cSize)) { // checks if there are anymore possible moves
                        randomInput(arr, rSize, cSize); // if all above is true the input another 2 in a random location
                        update(arr, rSize, cSize); // output new board
                    }
                    else {
                        return 0; // if no moves end prgram
                    }
                }
                else{
                    cout << "Invalid move. Try again: " << endl; // if invlaid move tell user to try again
                }
                break;
            case 'w':
                **arr = upTranslate(arr, rSize, cSize);
                if(gameOverCheck(arr, rSize, cSize)) {
                    **arr = randomInput(arr, cSize, rSize);
                    update(arr,rSize, cSize);
                }
                else {
                    return 0;
                }
                break;
            case 'd':
                **arr = rightTranslate(arr, rSize, cSize);
                if(gameOverCheck(arr, rSize, cSize)) {
                    **arr = randomInput(arr, cSize, rSize);
                    update(arr, rSize, cSize);
                }
                else {
                    return 0;
                }
                break;
            case 's':
                **arr = downTranslate(arr, rSize,cSize);
                if(gameOverCheck(arr, rSize, cSize)) {
                    **arr = randomInput(arr, cSize, rSize);
                    update(arr, rSize, cSize);
                }
                else {
                    return 0;
                }
                break;
            default:
                cout << "incorrect input" << endl;
                break;
        }
    }
    return 0;
}

int** gameBoard(int rSize, int cSize) {
    
    int** myGameBoard = new int*[rSize]; // setting up 2d array
    
    for(int r = 0; r < rSize; r++) { // loop through and initilize the 2d-array and out put
        myGameBoard[r] = new int[cSize];
        for(int c = 0; c < cSize; c++) {
            myGameBoard[r][c] = 0;
        }
    }
    return myGameBoard; // return the newly initilized 2d array
}
int** tempGameBoard(int** arr, int rSize, int cSize) {
    int** myTempArr = new int*[rSize];
    
    for(int r = 0; r < rSize; r++) {
        myTempArr[r] = new int[cSize];
        for(int c = 0; c < cSize; c++) {
            myTempArr[r][c] = arr[r][c];
        }
    }
    return myTempArr;
}


char command(char move) { // input move and return move
    cout << "make a move: ";
    cin >> move;
    return move;
}
bool checkMove(int** arr,int** tempArr,int rSize,int cSize) {
    for(int r =0; r < rSize; r++) {
        for(int c = 0; c < cSize; c++) {
            if(arr[r][c] != tempArr[r][c]) {
                return true;
            }
        }
    }
    return false;
}

int leftTranslate(int** arr, int rSize, int cSize) {
    int n;
    bool quitLoop;
    
    for(int r = 0; r < rSize; r++) {
        for(int c = 0; c < cSize; c++) { // checker to go through the entire array
            n = 1;
            if(arr[r][c] == 0) { // if current location is empty
                n = 1;
                while(arr[r][c] == 0 && n < (cSize - c)) { // while current location is empty and n is in range of table
                    
                    if(arr[r][c+n] != 0) { // if next location has value put that value in current location
                        arr[r][c] = arr[r][c+n];
                        arr[r][c+n] = 0;
                    }
                    else { //increment n to check next column
                        n++;
                    }
                }
            }
            n = 1;
            quitLoop = false;
            
            while(!quitLoop && n < (cSize - c)) { // loop checks if the locations will have same value when moved
                if(arr[r][c+n] == arr[r][c]) {
                    arr[r][c] += arr[r][c+n];
                    arr[r][c+n] = 0;
                    quitLoop = true;
                }
                else if(arr[r][c+n] == 0) { // check next col
                    n++;
                }
                else {
                    quitLoop = true; // nothing left to check end loop
                }
            }
        }
    }
    return **arr; // return the array after left translation
}
int upTranslate(int** arr, int rSize, int cSize) {
    return **arr;
}
int rightTranslate(int** arr, int rSize, int cSize) {
    return **arr;
}
int downTranslate(int** arr, int rSize, int cSize) {
    return **arr;
}
bool gameOverCheck(int** arr, int rSize, int cSize) {
    for(int r = 0; r < rSize; r++) { // goes through 2d array to see if any moves are possible
        for(int c = 0; c < cSize; c++) {
            if(arr[r][c] == 0) {
                return true;
            }
        }
    }
    cout << "Game Over No More Moves" << endl;
    return false;
}
int randomInput(int** arr, int rSize, int cSize) {
    int r,c = 0;
    int num = 2;
    bool foundEmpty = false;
    
    while(foundEmpty == false) { // finds empty location randomly
        r = rand() % rSize; //
        c = rand() % cSize;
        if(arr[r][c] == 0) { // if random location is empty
            arr[r][c] = num; // random location = num (2)
            foundEmpty = true; // end loop
        }
    }
    
    return **arr; // return new array
}
void update(int** arr, int rSize, int cSize) {
    for(int r =0; r < rSize; r++) { // output new array
        for(int c = 0; c < cSize; c++) {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
}