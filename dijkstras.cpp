// dijsktras.cpp
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

/*void dijsktras(int tRows, int tCols, int tNums[][], int startRow, int startCol, int endRow, int endCol) {

    

}*/

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
    int tNums[tRows][tCols];
    for (int i = 0; i < tRows; i++) {
        for (int j = 0; j < tCols; j++) {
            for (int k = 0; k < tNum; k++){
                if (tName[k] == tData[i][j]) {
                    tNums[i][j] = tCost[k];
                }
            }
        }
    }

    // 2D array initialized to false storing what nodes have been visited
    //bool visited[tRows][tCols] = {false};

    // run dijkstras function to match output from the write-up
    
    

    // output testing
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
	cout << endRow << " " << endCol << endl;
    */ 

	return 0;
}


