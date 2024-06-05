#ifndef MOVE
#define MOVE

#include "vectorMath.hpp"
const enum {UP, DOWN, LEFT, RIGHT};

float const EYE_HEIGHT = 1.5;

float const START_X = 5;
float const START_Y = 5;
float const START_Z = 4 + EYE_HEIGHT;

class playerPosView {
private:
	float const tiltSpeed = 0.03;
	float const moveSpeed = 0.15;
public:
	vector pos;
	polarVector view;

	void lookUp() {
		view.psi += tiltSpeed;
	}

	void lookDown() {
		view.psi -= tiltSpeed;
	}

	void lookLeft() {
		view.phi -= tiltSpeed;
	}

	void lookRight() {
		view.phi += tiltSpeed;
	}
	
	void moveFor() {
		vector dir = view.toCartVec();
		pos.x += moveSpeed * dir.x;
		pos.y += moveSpeed * dir.y;
	}

	void moveBack() {
		vector dir = view.toCartVec();
		pos.x -= moveSpeed * dir.x;
		pos.y -= moveSpeed * dir.y;
	}

	void moveLeft() {
		vector dir = view.toCartVec();
		pos.x += moveSpeed * dir.y;
		pos.y += moveSpeed * dir.x;
	}

	void moveRight() {
		vector dir = view.toCartVec();
		pos.x -= moveSpeed * dir.y;
		pos.y -= moveSpeed * dir.x;
	}

	playerPosView() {
		this->pos.x = START_X;
		this->pos.y = START_Y;
		this->pos.z = START_Z;
		this->view.psi = 0;
		this->view.phi = 0;
	}
};

#endif