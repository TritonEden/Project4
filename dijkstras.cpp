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
	char tData[tRows * tCols];
	for (int i = 0; i < (tRows * tCols); i++) {
		cin >> tData[i];
	}
	cin >> startRow >> startCol;
	cin >> endRow >> endCol;

	/*for (int i = 0; i < tNum; i++) {
		cout << tName[i] << " " << tCost[i] << endl;
	}*/

    // changing the table of characters to actual numerical weights of each tile
    int tNums[tRows * tCols];
	for (int i = 0; i < (tRows * tCols); i++) {
        for (int k = 0; k < tNum; k++){
            if (tName[k] == tData[i]) {
                tNums[i] = tCost[k];
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

	//cout << "pre initialization" << endl;

	// initialize arrays
	for (int i = 0; i < (tRows * tCols); i++) {
		distance[i] = 999;
		backL[i] = i;
		visited[i] = 0;
	}

	// set distance and backlink of start node manually
	distance[startRow + startCol * tCols] = tNums[startRow + startCol * tCols];
	backL[startRow + startCol * tCols] = -1;

	// making values to check for nearest node
	int minValue;
	int minNode;

    // run dijkstras function to match output from the write-up

	for (int i = 0; i < tRows * tCols; i++) {
		// get minimum reachable univisited
		minValue = 999;
		minNode = 0;
		for (int j = 0; j < tRows * tCols; j++) {
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
		if (distance[minNode+tCols] > tNums[minNode+tCols] + distance[minNode]) {
			if (minNode+tCols < (tCols * tCols)) {
				distance[minNode+tCols] = tNums[minNode+tCols] + distance[minNode];
				backL[minNode+tCols] = minNode;
			}
		}
	}

	// outputing to match the grade scripts
	cout << distance[endRow + (endCol * tCols)] - tNums[endRow + (endCol * tCols)] << endl;
	int back = endRow + (endCol * tCols);
	int it = 0;
	// create array to store location of tiles traveled through
	int tFinal[tRows*tCols];
	int outputR[tRows*tCols];
	int outputC[tRows*tCols];
	for (int i = 0; i < tRows*tCols; i++) {
		outputR[i] = 9999;
		outputC[i] = 9999;
	}
	int tMath;
	for (int i = 0; i < (tRows * tCols); i++) {
		tFinal[i] = 10000;
	}
	while (backL[back] != -1) {
		tFinal[it] = back;
		back = backL[back];
		it++;
	}
	//cout << endRow << " " << endCol << endl;
	outputR[0] = endRow;
	outputC[0] = endCol;
	for (int i = 1; i < tRows*tCols; i++) {
		if(tFinal[i] != 10000) {
			tMath = tFinal[i]/tCols;
			//cout << tMath << " " << tFinal[i] - (tCols*tMath) << endl;
			outputR[i] = tMath;
			outputC[i] = tFinal[i] - (tCols*tMath);
		}
		else {
			i = 999999;
		}
	}
	cout << startRow << " " << startCol << endl;
	for (int i = tRows*tCols - 1; i > 0; i--) {
		if (outputR[i] != 9999 && outputC[i] != 9999) {
			cout << outputR[i] << " " << outputC[i] << endl;
		}
	}
	cout << endRow << " " << endCol << endl;

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
	cout << endl;
	*/

    // input testing
	/*cout << tNum << endl;

	for (int i = 0; i < tNum; i++) {
		cout << tName[i] << " " << tCost[i] << endl;
	}
	cout << tRows << " " << tCols << endl;
	int inc = 0;
	for (int i = 0; i < tRows * tCols; i++) {
		if (inc == tCols) {
			cout << endl;
			inc = 0;
		}
		cout << tData[i] << " ";
		inc++;
	}
	cout << endl;
	cout << startRow << " " << startCol << endl;
	cout << endRow << " " << endCol << endl;

	return 0;*/
}


