#pragma once

#include "Agent.h"

class Arrive :
	public Agent::SteeringBehavior
{
private :
	const int SlowingRadius;
public:
	Arrive();
	~Arrive();
	void applySteeringForce(Agent *agent, float dtime);
	Vector2D CalculateSteeringForce(Agent * target, Agent *agent);
	Vector2D CalculateSeekVelocity(Agent *target, Agent* agent);
	void arriving(Agent *agent);
};
