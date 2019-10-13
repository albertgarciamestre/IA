#pragma once

#include "Agent.h"

class Pursue :
	public Agent::SteeringBehavior
{
private:
	const float MaxLookAheadTime;
	Vector2D PredictedTarget;
	Vector2D DesiredVelocity;
public:
	Pursue();
	~Pursue();
	void applySteeringForce(Agent *agent, float dtime);
	Vector2D CalculateSteeringForce(Agent * target, Agent *agent);
	Vector2D CalculateSeekVelocity(Agent *target, Agent* agent);
	void pursue(Agent *agent, Agent * target);
};
