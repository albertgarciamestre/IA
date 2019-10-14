#include "Flocking.h"

Flocking::Flocking():
	NEIGHBOR_RADIUS(200),
	K_SEPARATION_FORCE(200),
	K_COHESION_FORCE(100),
	K_ALIGNMENT_FORCE(400)
{
}

Flocking::~Flocking()
{
}

void Flocking::applySteeringForce(Agent *agent, float dtime)
{
	agent->setSteeringForce(CalculateSteeringForce(agent, agent));
	agent->setAcceleration(agent->getSteeringForce() / agent->getMass());
	agent->setVelocity(agent->getVelocity() + agent->getAcceleration() * dtime);
	agent->setVelocity(agent->getVelocity().Truncate(agent->getMaxVelocity()));
	agent->setPosition(agent->getPosition() + agent->getVelocity() * dtime);
}
Vector2D Flocking::CalculateSteeringForce(Agent * target, Agent *agent)
{
	DesiredVelocity = CalculateSeekVelocity(agent, target);
	Vector2D VelDelta = (DesiredVelocity - agent->getVelocity());
	VelDelta /= agent->getMaxVelocity();
	Vector2D SteeringForce = VelDelta * agent->getMaxForce();
	return SteeringForce;
}
Vector2D Flocking::CalculateSeekVelocity(Agent * target, Agent *agent)
{
	DesiredVelocity = agent->getTarget() - agent->getPosition();
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->getMaxVelocity();
	return DesiredVelocity;
}

Vector2D Flocking::CalculateSeparation(Agent*agent) {
	int neighborCount = 0;
	Vector2D separationVector = { };
	Vector2D separationDirection = { };

	for (int i = 0; i < 8; i++)
	{
		Vector2D DistanceToTarget;
		float Distance = DistanceToTarget.Distance(agent->getPosition(), agent->getTarget());
		if (Distance < NEIGHBOR_RADIUS) {
			separationVector += (agent->getPosition(), agent->getTarget());
			++neighborCount;
		}
		separationVector /= neighborCount;
		return separationDirection= separationVector.Normalize();
	}
}
Vector2D Flocking::CalculateCohesion(Agent*agent) {
	int neighborCount = 0;
	Vector2D averagePosition = { };
	Vector2D cohesionDirection = { };

	for (int i = 0; i < 8; i++)
	{
		Vector2D DistanceToTarget;
		float Distance = DistanceToTarget.Distance(agent->getPosition(), agent->getTarget());
		if (Distance < NEIGHBOR_RADIUS) {
			averagePosition += agent->getPosition();
			++neighborCount;
		}
		averagePosition /= neighborCount;
		averagePosition -= agent->getTarget();
		return cohesionDirection= averagePosition.Normalize();
	}

}
Vector2D Flocking::CalculateAlignment(Agent*agent) {
	int neighborCount = 0;
	Vector2D averagePosition = { };
	Vector2D alignmentDirection = { };

	for (int i = 0; i < 8; i++)
	{
		Vector2D DistanceToTarget;
		float Distance = DistanceToTarget.Distance(agent->getPosition(), agent->getTarget());
		if (Distance < NEIGHBOR_RADIUS) {
			averagePosition += agent->getVelocity();
			++neighborCount;
		}
		averagePosition /= neighborCount;
		return alignmentDirection = averagePosition.Normalize();
	}
}
Vector2D Flocking::flockingSuma(Agent*agent) {
	flockingForce = separationDirection * K_SEPARATION_FORCE
		+ cohesionDirection * K_COHESION_FORCE
		+ alignmentDirection * K_ALIGNMENT_FORCE;
	return flockingForce;
}
