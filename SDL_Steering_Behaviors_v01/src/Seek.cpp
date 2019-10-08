#include "Seek.h"

Seek::Seek()
{
}

Seek::~Seek()
{
}

void Seek::applySteeringForce(Agent *agent, float dtime)
{
	agent->setSteeringForce(CalculateSteeringForce(agent, agent));
	agent->setAcceleration(agent->getSteeringForce() / agent->getMass()) ;
	agent->setVelocity(agent->getVelocity() + agent->getAcceleration() * dtime);
	agent->setVelocity(agent->getVelocity().Truncate(agent->getMaxVelocity()));
	agent->setPosition(agent->getPosition() + agent->getVelocity() * dtime);
}
Vector2D Seek::CalculateSteeringForce(Agent * target, Agent *agent)
{
	Vector2D DesiredVelocity = CalculateSeekVelocity(agent, target);
	Vector2D VelDelta= (DesiredVelocity - agent->getVelocity());
	VelDelta /= agent->getMaxVelocity();
	Vector2D SteeringForce = VelDelta * agent->getMaxForce();
	return SteeringForce;
}
Vector2D Seek::CalculateSeekVelocity(Agent * target, Agent *agent)
{
	Vector2D DesiredVelocity = agent->getTarget() - agent->getPosition();
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->getMaxVelocity();
	return DesiredVelocity;
}
