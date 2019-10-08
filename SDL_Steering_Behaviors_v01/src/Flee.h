#pragma once
#include "Agent.h"

class Flee :
	public Agent::SteeringBehavior
{
public:
	Flee();
	~Flee();
	void applySteeringForce(Agent *agent, float dtime);
	Vector2D CalculateSteeringForce(Agent * target, Agent *agent);
	Vector2D CalculateSeekVelocity(Agent *target, Agent* agent);
};
