#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <SDL.h>
#include <vector>
#include "Texture.h"
#include "Enemy.h"

class Player
{
public:
	//Initializes the variables
	Player();

	//Takes key presses and adjusts the player's velocity
	void handleEvent(SDL_Event& e);

	//Moves the player and checks collision
	void move(Enemy* enemies);

	//Centers the camera over the player
	void setCamera(SDL_Rect& camera);

	//Shoots bullets
	void shoot();

	//Loads player texture
	bool loadTexture();

	//Frees player texture
	void free();

	//Shows the player on the screen
	void render(SDL_Rect& camera);

	//Get player's collision box
	SDL_Rect getBox();

	//Get player's position
	float getX();
	float getY();

private:
	//The dimensions of the player
	const int PLAYER_WIDTH = 20;
	const int PLAYER_HEIGHT = 20;

	//Maximum axis velocity of the player
	const float PLAYER_VEL = 5;

	//Player texture
	Texture _playerTexture;

	//Collision box of the player
	SDL_Rect _box;

	//Position of the player
	float _playerX, _playerY;

	//Position of the mouse cursor
	float _mouseX, _mouseY;

	//The velocity of the player
	float _velX, _velY;

	//Distance vector between the player and the mouse cursor
	glm::vec2 _distVec;

	//Length of the distance vector
	float _distLen;

};

#endif
