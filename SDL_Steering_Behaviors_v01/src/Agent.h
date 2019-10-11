#pragma once
#include <iostream>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_SimpleApp.h"
#include "Vector2D.h"
#include "utils.h"


class Agent
{
public:
	class SteeringBehavior
	{
	public:
		SteeringBehavior() {};
		virtual ~SteeringBehavior() {};
		virtual void applySteeringForce(Agent *agent, float dtime) {
			
		};
	};
private:
	SteeringBehavior *steering_behaviour;
	Vector2D position;
	Vector2D velocity;
	float targetVelocity;
	Vector2D target;


	Vector2D acceleration;
	Vector2D steeringForce;

	float mass;
	float orientation;
	const float max_force;
	const float max_velocity;
	float ArriveSpeed;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

public:
	Agent();
	~Agent();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	float getTargetVelocity();
	Vector2D getAcceleration();
	Vector2D getSteeringForce();
	float getArriveSpeed();
	float getMaxVelocity();
	float getMaxForce();
	float getMass();
	void setBehavior(SteeringBehavior *behavior);
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void setTargetVelocity(float targetVelocity);
	void setAcceleration(Vector2D acceleration);
	void setSteeringForce(Vector2D steeringForce);
	void setArriveSpeed(float arriveSpeed);
	void setMass(float mass);
	void update(float dtime, SDL_Event *event);
	void draw();
	bool Agent::loadSpriteTexture(char* filename, int num_frames=1);
	
};
