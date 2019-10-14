#pragma once

#include "Agent.h"

class Wander :
	public Agent::SteeringBehavior
{
private:
	// Maximum Change of Angle in one frame
	const float WanderMaxAngleChange;
	// Distance from Agent to Wander Circle Center
	const float WanderOffset;
	// Radius of Wander Circle
	const float WanderRadius;
	Vector2D DesiredVelocity;
	Vector2D TargetPosition;
	float WanderAngle;
	float TargetAngle;
public:
	Wander();
	~Wander();
	void applySteeringForce(Agent *agent, float dtime);
	Vector2D CalculateSteeringForce(Agent * target, Agent *agent);
	Vector2D CalculateSeekVelocity(Agent *target, Agent* agent);
	void wander(Agent *agent);
	float RandomBinomial();
	float Orientacio(Agent *agent);
};
