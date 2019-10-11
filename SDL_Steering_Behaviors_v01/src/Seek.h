#pragma once
#include "Agent.h"

class Seek :
	public Agent::SteeringBehavior
{

public:
	
	Seek();
	~Seek();
	void applySteeringForce(Agent *agent, float dtime);
	Vector2D CalculateSteeringForce(Agent * target, Agent *agent);
	Vector2D CalculateSeekVelocity(Agent *target, Agent* agent);
	
};
