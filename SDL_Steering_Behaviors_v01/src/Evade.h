#pragma once
#pragma once

#include "Agent.h"

class Evade :
	public Agent::SteeringBehavior
{
private:
	const float MaxLookAheadTime;
	Vector2D PredictedTarget;
	Vector2D DesiredVelocity;
public:
	Evade();
	~Evade();
	void applySteeringForce(Agent *agent, float dtime);
	Vector2D CalculateSteeringForce(Agent * target, Agent *agent);
	Vector2D CalculateSeekVelocity(Agent *target, Agent* agent);
	void evade(Agent *agent, Agent * target);
};
