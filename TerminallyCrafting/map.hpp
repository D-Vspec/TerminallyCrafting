#ifndef MAP
#define MAP

#include "vector"

using namespace std;

const unsigned int BLOCKS_X = 20;
const unsigned int BLOCKS_Y = 20;
const unsigned int BLOCKS_Z = 10;

class map {
private:
	vector<vector<vector<char>>> blockList;

public:

	map() {
		for (int i = 0; i < BLOCKS_Z; i++) {
			for (int j = 0; j < BLOCKS_Y; j++) {
				for (int k = 0; k < BLOCKS_X; k++) {
					blockList[i][j][k] = ' ';
				}
			}
		}
	}
};

#endif 