#pragma once

#include "Agent.h"

class Wander :
	public Agent::SteeringBehavior
{
private:
	const int SlowingRadius;
public:
	Wander();
	~Wander();
	void applySteeringForce(Agent *agent, float dtime);
	Vector2D CalculateSteeringForce(Agent * target, Agent *agent);
	Vector2D CalculateSeekVelocity(Agent *target, Agent* agent);
	void wander(Agent *agent);
};
