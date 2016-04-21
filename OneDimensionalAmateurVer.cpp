#include <iostream>
using namespace std;

bool AllZeros(const int*, int); //the function that checks if maybe all values in the array are 0 so it could save some thinking time

int main(){
	const int size = 5; //size of the array (in the future, the size of the side of the "box"
	int arr[size] = { 2, 2, 2,4, 2}; //edit this for check
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

				for (int i = 0; i < size - 1; i++){ //for every value - 1 because can't collapse last value anyways
					int n = 1;
					if (arr[i] == 0){ //first the collapse. if the value is 0
						n = 1;
						while (arr[i] == 0 && n < (size - i)){ //it will search for the next non-zero value
							if (arr[i + n] != 0){
								arr[i] = arr[i + n]; arr[i + n] = 0; //assign next non-zero value to current, turn that position 0
							}
							else
								n++; //if next value also 0 keep looking further
						}
					}
					n = 1;
					bool quitLoop = false;
					while (!quitLoop && n < (size - i)){ //it will search for the next non-zero value
						if (arr[i + n] == arr[i]){ //if next value same
							arr[i] = 2 * arr[i]; arr[i + n] = 0; //double current value, turn next one 0
							quitLoop = true;
						}
						else if (arr[i + n] == 0)
							n++; //if next value 0 keep looking further
						else
							quitLoop = true; //if next value different, quit
						}
					}
				}
			
			for (int i = 0; i < size; i++) //print new string
				cout << arr[i] << " ";
			cout << endl;
			cout << "Enter a command, master: "; //ask for new command rinse and repeat
			cin >> command;
		}
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
