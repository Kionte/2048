#include <iostream>
using namespace std;

bool AllZeros(const int*, int); //the function that checks if maybe all values in the array are 0 so it could save some thinking time

int main(){
	const int size = 4; //size of the array (in the future, the size of the side of the "box"
	int arr[size] = { 2, 4, 0, 2 }; //edit this for check
	char command = ' '; //command needed for inputting a command
	/*Let's check if there's a way to not have to press enter every single time*/

	for (int i = 0; i < size; i++) //cout the initial array
		cout << arr[i] << " ";
	cout << endl; 
	cout << "Enter a command, master: "; //as for the command (currently a (aka dump to the left) is the only option
	cin >> command;


	while (command != 'q'){ //there's also q for quit

		if (command == 'a'){
			if (!AllZeros(arr, size)){ //if all values are zeroes there's no point to bother with this line
				bool fusionHappened = false; //there can only be one "fusion" per line per command so 2 2 4 0 would become 4 4 0 0 not 8 0 0 0
				
				for (int i = 0; i < size - 1; i++){ //for every value - 1 because can't collapse last value anyways

					if (arr[i] == 0){ //first the collapse. if the value is 0
						int n = 1;
						while (arr[i] == 0 && n < (size - i)){ //it will search for the next non-zero value
							if (arr[i + n] != 0){
								arr[i] = arr[i + n]; arr[i + n] = 0; //assign next non-zero value to current, turn that position 0
							}
							else
								n++; //if next value also 0 keep looking further
						}
					}
					if (arr[i] != 0 && !fusionHappened){ //unless somewhere something has already added up and these are 0s
						if (arr[i] == arr[i + 1]){ //if the next value is the sane
							arr[i] = 2 * arr[i]; arr[i + 1] = 0; //current value doubles, next value turns 0 to be collapsed at next iteration
							fusionHappened = true; //fusion has happened once
						}
					}
				}
			}
		}
		for (int i = 0; i < size; i++) //print new string
			cout << arr[i] << " ";
		cout << endl;
		cout << "Enter a command, master: "; //ask for new command rinse and repeat
		cin >> command;
	}

	return 0;

}

bool AllZeros(const int* arr, int sz){ //returns false if even one value is different from 0
	for (int i = 0; i<sz; i++){
		if (arr[i] != 0)
			return false;
	}
	return true;
}