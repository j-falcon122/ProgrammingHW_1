//Write a program that implements the following disk scheduling algorithms:
//FCFS, SSTF, SCAN, C-SCAN, LOOK, C-LOOK

#include <stdio.h>
#include <stdlib.h>

#define cylinders 5000
#define requests 1000

int startPosition = 0;

int ranArray[requests];

//FCFS
int fcfs(int *ranArray) {

    int i = 0;
    int headMoves = 0;
    int thisStart = ranArray[startPosition];

    for(i = startPosition; i < requests; i++) {
        headMoves += abs(ranArray[i] - thisStart);
    }

    for(i = 0; i < startPosition; i++) {
        headMoves += abs(thisStart - ranArray[i]);
    }

    return headMoves;
}

//a sorting array for scan and c-scan
int* sortArray() {

	int temp = 0;
	for (int i = 0; i < requests; ++i) {
       	for (int j = i + 1; j < requests; ++j) {

            if (ranArray[i] > ranArray[j]) {
                temp =  ranArray[i];
                ranArray[i] = ranArray[j];
                ranArray[j] = temp;
            }
        }
    }

    return ranArray;
}

//SCAN
int scan(int *ranArray) {

    //(must be sorted first)
    ranArray = sortArray();

    int currentValue = 0;
    int savValue = ranArray[startPosition];
    int difference = 0;
    int headMoves = 0;
    int currIndex = 0;

    for(int i = startPosition-1; i >= 0; --i) {
        currentValue = ranArray[i];
		difference = abs(savValue - currentValue);
		headMoves += difference;
		savValue = currentValue;
    }

    headMoves += savValue;
    savValue = 0;

    for(int i = startPosition+1; i < requests; i++) {
        currentValue = ranArray[i];
		difference = abs(currentValue - savValue);
		headMoves += difference;
		savValue = currentValue;
    }

    return headMoves;
}

//LOOK
int look(int *ranArray) {
    int currentValue = 0;
    int savValue = ranArray[startPosition];
    int difference = 0;
	int headMoves = 0;

    for(int i = startPosition+1; i < requests; i++) {
		currentValue = ranArray[i];
		difference = abs(savValue - currentValue);
		headMoves += difference;
		savValue = currentValue;
	}

    for(int i = startPosition-1; i >= 0; --i) {
		currentValue = ranArray[i];
		difference = abs(currentValue - savValue);
		headMoves += difference;
		savValue = currentValue;
	}

	return headMoves;
}

// SSTF
int sstf(int *ranArray) {

	// sort array first
	ranArray = sortArray();

	int startSmall = startPosition-1;
	int startLarge = startPosition+1;
	int differenceSmall = 0;
	int differenceLarge = 0;
	int headMoves = 0;
	int total = requests-2;
	int newHead = startPosition;
	int headVal = ranArray[startPosition];
	
	while(total >= 0) {

		differenceSmall = abs(ranArray[newHead] - ranArray[startSmall]);
		differenceLarge = abs(ranArray[startLarge] - ranArray[newHead]);

		if(differenceSmall < differenceLarge) {

			headMoves += differenceSmall;
			newHead = startSmall;
			startSmall--;
			
		} else {

			headMoves += differenceLarge;
			newHead = startLarge;
			startLarge++;
		}

		total--;

	}

	return headMoves;

}

// CSCAN
int cscan(int *ranArray) {

	int i = 0;
	int currentValue = 0;
	int savedValue= ranArray[startPosition];
	int difference = 0;
	int headMoves = 0;
	int upperBound = 4999;

	for(i = startPosition + 1; i < requests; i++) {

		currentValue = ranArray[i];
		difference = abs(savedValue - currentValue);
		headMoves += difference;
		savedValue = currentValue;

	}

	headMoves += upperBound - savedValue;
	savedValue= 0;
	headMoves += 4999;

	for(i = 0; i < startPosition; i++) {

		currentValue = ranArray[i];
		difference = abs(currentValue - savedValue);
		headMoves += difference;
		savedValue = currentValue;

	}

	return headMoves;
}

// C-LOOK
int clook(int *ranArray) {

	int i = 0;
	int currentValue = 0; 
	int savedValue = ranArray[startPosition];
	int difference = 0;
	int headMoves = 0;

	for(i = startPosition + 1; i < requests; i++) {

		currentValue = ranArray[i];
		difference = abs(savedValue - currentValue);
		headMoves += difference;
		savedValue = currentValue;

	}

	for(i = 0; i < startPosition; i++) {

		currentValue = ranArray[i];
		difference = abs(currentValue - savedValue);
		headMoves += difference;
		savedValue = currentValue;

	}	

	return headMoves;
}


int main (int argc, char *argv[]) {

	startPosition = atoi(argv[1]);

	if(argc != 2) {

		printf("Compile the program using `gcc -o [name executable] question1` then run the executable with a number to start with i.e. `./diskAlgorithms 423`\n");
		exit(-1);
	}

	for(int i = 0; i < requests; i++) {
        
		ranArray[i] = rand() % 5000;
	}

	printf("\nStarting Index: %d, Starting Value: %d\n\n", startPosition, ranArray[startPosition]);

    //running functions
	printf("FCFS head movements: %d\n", fcfs(ranArray));
	printf("SCAN head movements: %d\n", scan(ranArray));
	printf("LOOK head movements: %d\n", look(ranArray));
	printf("C-SCAN head movements: %d\n", cscan(ranArray));
	printf("SSTF head movements: %d\n", sstf(ranArray));
	printf("C-LOOK head movements: %d\n", clook(ranArray));

	return 0;
}

// CSCAN

// SSTF

// CLOOK