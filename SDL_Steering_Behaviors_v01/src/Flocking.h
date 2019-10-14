#pragma once
#pragma once
#include "Agent.h"

class Flocking :
	public Agent::SteeringBehavior
{
private:
	Vector2D DesiredVelocity;
	const int NEIGHBOR_RADIUS;
	const int K_SEPARATION_FORCE;
	const int K_COHESION_FORCE;
	const int K_ALIGNMENT_FORCE;
	Vector2D separationDirection;
	Vector2D cohesionDirection;
	Vector2D alignmentDirection;
	Vector2D flockingForce;

public:

	Flocking();
	~Flocking();
	void applySteeringForce(Agent *agent, float dtime);
	Vector2D CalculateSteeringForce(Agent * target, Agent *agent);
	Vector2D CalculateSeekVelocity(Agent *target, Agent* agent);
	Vector2D CalculateSeparation(Agent*agent);
	Vector2D CalculateCohesion(Agent*agent);
	Vector2D CalculateAlignment(Agent*agent);
	Vector2D flockingSuma(Agent*agent);

};
