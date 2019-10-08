#include "Flee.h"

Flee::Flee()
{
}

Flee::~Flee()
{
}

void Flee::applySteeringForce(Agent *agent, float dtime)
{
	agent->setSteeringForce(CalculateSteeringForce(agent, agent));
	agent->setAcceleration(agent->getSteeringForce() / agent->getMass());
	agent->setVelocity(agent->getVelocity() + agent->getAcceleration() * dtime);
	agent->setVelocity(agent->getVelocity().Truncate(agent->getMaxVelocity()));
	agent->setPosition(agent->getPosition() + agent->getVelocity() * dtime);
}
Vector2D Flee::CalculateSteeringForce(Agent * target, Agent *agent)
{
	Vector2D DesiredVelocity = CalculateSeekVelocity(agent, target);
	Vector2D VelDelta = (DesiredVelocity - agent->getVelocity());
	VelDelta /= agent->getMaxVelocity();
	Vector2D SteeringForce = VelDelta * agent->getMaxForce();
	return SteeringForce;
}
Vector2D Flee::CalculateSeekVelocity(Agent * target, Agent *agent)
{
	Vector2D DesiredVelocity =  agent->getPosition() - agent->getTarget();
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->getMaxVelocity();
	return DesiredVelocity;
}
