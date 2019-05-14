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

	return 0;
}