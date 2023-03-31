// dijsktras.cpp
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {

    int tNum, tRows, tCols, startRow, startCol, endRow, endCol;

	// read in input
	cin >> tNum;

	char tName[tNum];
	int tCost[tNum];

	for (int i = 0; i < tNum; i++) {
		cin >> tName[i] >> tCost[i];
	}
	cin >> tRows >> tCols;
	// matrix to input tile values
	char tData[tRows][tCols];
	for (int i = 0; i < tRows; i++) {
		for (int j = 0; j < tCols; j++) {
			cin >> tData[i][j];
		}
	}
	cin >> startRow >> startCol;
	cin >> endRow >> endCol;

    // changing the table of characters to actual numerical weights of each tile
    int tNums[tRows * tCols];
    for (int i = 0; i < tCols; i++) {
        for (int j = 0; j < tRows; j++) {
            for (int k = 0; k < tNum; k++){
                if (tName[k] == tData[i][j]) {
                    tNums[j + (i * 10)] = tCost[k];
                }
            }
        }
    }

    // 2D array initialized to false storing what nodes have been visited
    //bool visited[tRows][tCols] = {false};

	// a 2D array that stores the distances of each node from the starting node
	// all distances are initialized to infinity (99)
	int distance[tRows * tCols];

	// create previous 2D array that stores backlinks
	int backL[tRows * tCols];

	// visited array initialized to false
	int visited[tRows * tCols];

	// initialize arrays
	for (unsigned char i = 0; i < (tRows * tCols); i++) {
		distance[i] = 999;
		backL[i] = i;
		visited[i] = 0;
	}

	// set distance and backlink of start node manually
	distance[startRow + startCol * 10] = tNums[startRow + startCol * 10];
	backL[0] = -1;

	// making vectors to print the gradescripts
	vector<int> outputRow;
	vector<int> outputCol;

	// making values to check for nearest node
	int minValue;
	int minNode;

    // run dijkstras function to match output from the write-up

	for (int i = 0; i < tRows * tCols; i++) {
		// get minimum reachable univisited
		minValue = 99;
		minNode = 0;
		for (int j = 0; j < (tRows * tCols) - 1; j++) {
			if (visited[j] == 0 && distance[j] < minValue) {	
				minValue = distance[j];
				minNode = j;
			}
		}
		visited[minNode] = 1;
		// update the distance cost for all of minNode's adjacent nodes
		// this update occurs only if the adjacent node distance < current distance
		// keep track of backlinks
		// account for the last column and row using if statements
		// minNode+1 != 10 && minNode+1 != 20 && minNode+1 != 30 && minNode+1 != 40 && minNode+1 != 50 && minNode+1 != 60 && minNode+1 != 70 && minNode+1 != 80 && minNode+1 != 90 && minNode+1 < 100
		if (distance[minNode+1] > tNums[minNode+1] + distance[minNode]) {
			if (minNode+1 < tRows * tCols) {
				distance[minNode+1] = tNums[minNode+1] + distance[minNode];
				backL[minNode+1] = minNode;
			}
		}
		if (distance[minNode+10] > tNums[minNode+10] + distance[minNode]) {
			if (minNode+10 < (tCols * 10)) {
				distance[minNode+10] = tNums[minNode+10] + distance[minNode];
				backL[minNode+10] = minNode;
			}
		}
	}
	
	// outputing to match the grade scripts
	cout << distance[endRow + (endCol * 10)] - tNums[endRow + (endCol * 10)] << endl;
	int back = endRow + (endCol * 10);
	int it = 0;
	// create array to store location of tiles traveled through
	int tFinal[tRows*tCols];
	int tMath;
	for (unsigned char i = 0; i < (tRows * tCols); i++) {
		tFinal[i] = 10000;
	}

	while (backL[back] != -1) {
		tFinal[it] = back;
		back = backL[back];
		it++;
	}
	for (int i = 0; i < tRows*tCols; i++) {
		if(tFinal[i] != 10000) {
			tMath = tFinal[i]/10;
			cout << tFinal[i] - (10*tMath) << " " << tMath << endl;
		}
		else {
			i = 1000;
		}
	}
	cout << "0 0" << endl;

	// checking stuff

	/*int inc = 0;
	for (int i = 0; i < tRows * tCols; i++) {
		if (inc == tCols) {
			cout << endl;
			inc = 0;
		}
		cout << backL[i] << " ";
		inc++;
	}
	cout << endl;*/

	/*for (int i = 0; i < tNum; i++) {
		cout << tFinal[i] << " ";
	}
	cout << endl;*/

	// checking final distance vector
	/* 	
	int inc = 0;
	for (int i = 0; i < tRows * tCols; i++) {
		if (inc == tCols) {
			cout << endl;
			inc = 0;
		}
		cout << distance[i] << " ";
		inc++;
	}
	cout << endl;*/
	

    // input testing
	/*cout << tNum << endl;

	for (int i = 0; i < tNum; i++) {
		cout << tName[i] << " " << tCost[i] << endl;
	}
	cout << tRows << " " << tCols << endl;
	for (unsigned char i = 0; i < tRows; i++) {
		for (unsigned char j = 0; j < tCols; j++) {
			cout << tData[i][j] << " ";
		}
		cout << endl;
	}
	cout << startRow << " " << startCol << endl;
	cout << endRow << " " << endCol << endl;*/

	return 0;
}
