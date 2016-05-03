//
//  edit.cpp
//  FinalProject_2048
//
//  Created by Kionte Brown on 4/22/16.
//  Edited by Vicky Sorokina on 4/26/16
//  Copyright © 2016 Kionte Brown. All rights reserved.
//

// viv
// sap
//need better gameOverCheck function
//still need check for zero's funtion
//need up and down translations
//

//to do:
//up down -vicky DONE
//score count -vicky
//gameover function -kionté DONE
//clear cin buffer -vicky DONE
//make whole thing into class (later)
//callin functions (later)
//save input output (later)- joel
//some way to keep board square (class?) (later)
//commands without using enter (later)

#include<iostream>
#include <ctime>
using namespace std;

int** gameBoard(int); // initilizes  the gameboard
int** tempGameBoard(int**, int); // copy over gameboard to copy
char command(char); // input function to control movements
bool checkMove(int**, int**, int); // checks if move is valid
int leftTranslate(int** arr, int Size); // left movement
int upTranslate(int** arr, int Size); // up movement
int rightTranslate(int** arr, int Size); // right movement
int downTranslate(int** arr, int Size); // down movement
bool gameOverCheck(int**, int); // check if there are no more posibble moves
int randomInput(int** arr, int Size); // finds empty location and inputs a '2'
void update(int** arr, int Size); // out puts new board

int main() {
    srand(time(0)); // starts up random num generator
    char move = ' '; // var for movemet
    int Size = 0; // var for size
    
    
    cout << "What's the size of a side? ";
    cin >> Size; // row input
    
    
    int** arr = gameBoard(Size); // sets the 2d array to the gameboard function
    randomInput(arr, Size); // gets and sets initial number
    int** tempArr = tempGameBoard(arr, Size); // sets up copy of board for later comparison
    while (move != 'q') { // while user doesnt quit
        update(arr, Size);
        tempArr = tempGameBoard(arr, Size); // copys board for later comparison
        if(!(gameOverCheck(arr, Size))) {
            cout << "Game Over. No more remaining moves" << endl;
            return 0;
        }
        switch (command(move)) { // runs the command function and detemrines a case based off return value
                
            case 'a':
                **arr = leftTranslate(arr, Size); // attempts to make move to left
                if (checkMove(arr, tempArr, Size)) { // checks if move is valid if it is contine if not try a different move
                    randomInput(arr, Size); // if all above is true the input another 2 in a random location
                }
                else {
                    cout << "Invalid move. Try again: " << endl; // if invlaid move tell user to try again
                }
                break;
                
            case 'w':
                **arr = upTranslate(arr, Size); // attempts to make move to left
                if (checkMove(arr, tempArr, Size)) { // checks if move is valid if it is contine if not try a different move
                        randomInput(arr, Size); // if all above is true the input another 2 in a random location
                }
                else {
                    cout << "Invalid move. Try again: " << endl; // if invlaid move tell user to try again
                }
                break;
                
            case 'd':
                **arr = rightTranslate(arr, Size); // attempts to make move to left
                if (checkMove(arr, tempArr, Size)) { // checks if move is valid if it is contine if not try a different move
                randomInput(arr, Size); // if all above is true the input another 2 in a random location
                }
                else {
                    cout << "Invalid move. Try again: " << endl; // if invlaid move tell user to try again
                }
                break;
                
            case 's':
                **arr = downTranslate(arr, Size); // attempts to make move to left
                if (checkMove(arr, tempArr, Size)) { // checks if move is valid if it is contine if not try a different move
                randomInput(arr, Size); // if all above is true the input another 2 in a random location
                }
                
                else {
                    cout << "Invalid move. Try again: " << endl; // if invlaid move tell user to try again
                }
                break;
                
            case 'q':
                return 0;
            default:
                cout << "incorrect input" << endl;
                break;
        }
        system("cls");
    }
    return 0;
}

int** gameBoard(int Size) {
    
    int** myGameBoard = new int*[Size]; // setting up 2d array
    
    for (int r = 0; r < Size; r++) { // loop through and initilize the 2d-array and out put
        myGameBoard[r] = new int[Size];
        for (int c = 0; c < Size; c++) {
            myGameBoard[r][c] = 0;
        }
    }
    return myGameBoard; // return the newly initilized 2d array
}
int** tempGameBoard(int** arr, int Size) {
    int** myTempArr = new int*[Size];
    
    for (int r = 0; r < Size; r++) {
        myTempArr[r] = new int[Size];
        for (int c = 0; c < Size; c++) {
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



int leftTranslate(int** arr, int Size) {
    int n;
    bool quitLoop;
    
    for (int r = 0; r < Size; r++) {
        for (int c = 0; c < Size; c++) { // checker to go through the entire array
            if (arr[r][c] == 0) { // if current location is empty
                n = 1;
                while (arr[r][c] == 0 && n < (Size - c)) { // while current location is empty and n is in range of table
                    
                    if (arr[r][c + n] != 0) { // if next location has value put that value in current location
                        arr[r][c] = arr[r][c + n];
                        arr[r][c + n] = 0;
                    }
                    else { //increment n to check next column
                        n++;
                    }
                }
            }
            n = 1;
            quitLoop = false;
            
            while (!quitLoop && n < (Size - c)) { // loop checks if the locations will have same value when moved
                if (arr[r][c + n] == arr[r][c]) {
                    arr[r][c] += arr[r][c + n];
                    arr[r][c + n] = 0;
                    quitLoop = true;
                }
                else if (arr[r][c + n] == 0) { // check next col
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

int upTranslate(int** arr, int Size) {
    
    int n;
    bool quitLoop;
    
    for (int c = 0; c < Size; c++) {
        for (int r = 0; r < Size; r++) { // checker to go through the entire array
            if (arr[r][c] == 0) { // if current location is empty
                n = 1;
                while (arr[r][c] == 0 && n < (Size - r)) { // while current location is empty and n is in range of table
                    
                    if (arr[r + n][c] != 0) { // if next location has value put that value in current location
                        arr[r][c] = arr[r + n][c];
                        arr[r + n][c] = 0;
                    }
                    else { //increment n to check next column
                        n++;
                    }
                }
            }
            n = 1;
            quitLoop = false;
            
            while (!quitLoop && n < (Size - r)) { // loop checks if the locations will have same value when moved
                if (arr[r + n][c] == arr[r][c]) {
                    arr[r][c] += arr[r + n][c];
                    arr[r + n][c] = 0;
                    quitLoop = true;
                }
                else if (arr[r + n][c] == 0) { // check next col
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

int rightTranslate(int** arr, int Size) {
    int n;
    bool quitLoop;
    int g = -1;
    
    for (int r = 0; r < Size; r++) {
        g = -1;
        for (int c = Size - 1; c > 0; c--) { // checker to go through the entire array
            n = 1;
            g++;
            if (arr[r][c] == 0) { // if current location is empty
                n = 1;
                while (arr[r][c] == 0 && n < (Size - g)) { // while current location is empty and n is in range of table
                    
                    if (arr[r][c - n] != 0) { // if next location has value put that value in current location
                        arr[r][c] = arr[r][c - n];
                        arr[r][c - n] = 0;
                    }
                    else { //increment n to check next column
                        n++;
                    }
                }
            }
            n = 1;
            quitLoop = false;
            
            while (!quitLoop && n < (Size - g)) { // loop checks if the locations will have same value when moved
                if (arr[r][c - n] == arr[r][c]) {
                    arr[r][c] += arr[r][c - n];
                    arr[r][c - n] = 0;
                    quitLoop = true;
                }
                else if (arr[r][c - n] == 0) { // check next col
                    n++;
                }
                else {
                    quitLoop = true; // nothing left to check end loop
                }
            }
        }
    }
    return **arr;
}

int downTranslate(int** arr, int Size) {
    int n;
    bool quitLoop;
    int g = -1;
    
    for (int c = 0; c < Size; c++) {
        g = -1;
        for (int r = Size - 1; r > 0; r--) { // checker to go through the entire array
            n = 1;
            g++;
            if (arr[r][c] == 0) { // if current location is empty
                while (arr[r][c] == 0 && n < (Size - g)) { // while current location is empty and n is in range of table
                    
                    if (arr[r - n][c] != 0) { // if next location has value put that value in current location
                        arr[r][c] = arr[r - n][c];
                        arr[r - n][c] = 0;
                    }
                    else { //increment n to check next column
                        n++;
                    }
                }
            }
            n = 1;
            quitLoop = false;
            
            while (!quitLoop && n < (Size - g)) { // loop checks if the locations will have same value when moved
                if (arr[r - n][c] == arr[r][c]) {
                    arr[r][c] += arr[r - n][c];
                    arr[r - n][c] = 0;
                    quitLoop = true;
                }
                else if (arr[r - n][c] == 0) { // check next col
                    n++;
                }
                else {
                    quitLoop = true; // nothing left to check end loop
                }
            }
        }
    }
    return **arr;
}
bool checkMove(int** arr, int** tempArr, int Size) {
    for (int r = 0; r < Size; r++) { // checker to see see if there is a difference between board before and after move
        for (int c = 0; c < Size; c++) {
            if (arr[r][c] != tempArr[r][c]) {
                return true;
            }
        }
    }
    return false;
}
bool gameOverCheck(int** arr, int Size) {
   
    for(int r = 0; r < Size; r++) {
        for(int c = 0; c < Size; c++) {
            if(arr[r][c] == 0) {
                return true;
            }
        }
    }
    
    for(int r = 0; r < Size; r++) {
        for(int c = 0; c < Size; c++) {
            if(c != Size-1) {
                if(arr[r][c] == arr[r][c+1]) {
                    return true;
                }
            }
            if(r != Size-1) {
                if(arr[r][c] == arr[r+1][c]) {
                    return true;
                }
            }
        }
    }
    
    return false;
}
int randomInput(int** arr, int Size) {
    int r, c = 0;
    int num = 2;
    bool foundEmpty = false;
    
    while (foundEmpty == false) { // finds empty location randomly
        r = rand() % Size; //
        c = rand() % Size;
        if (arr[r][c] == 0) { // if random location is empty
            arr[r][c] = num; // random location = num (2)
            foundEmpty = true; // end loop
        }
    }
    
    return **arr; // return new array
}
void update(int** arr, int Size) {
    system("cls");
    for (int r = 0; r < Size; r++) { // output new array
        cout << "----------------------------" << endl; //the following code works... dont question it... or try to read it...
        for (int c = 0; c < Size; c++) {
            if (arr[r][c] == 0)
                cout << "[     ]";
            else
                cout <<"[  "<< arr[r][c] << "  ]";
        }
        
        cout << endl;
    }
    cout << "----------------------------" << endl;
}
