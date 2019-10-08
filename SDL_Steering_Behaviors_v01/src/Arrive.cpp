#include "Arrive.h"

Arrive::Arrive() : 
	SlowingRadius(2)
{
}

Arrive::~Arrive()
{
}

void Arrive::applySteeringForce(Agent *agent, float dtime)
{
	agent->setSteeringForce(CalculateSteeringForce(agent, agent));
	agent->setAcceleration(agent->getSteeringForce() / agent->getMass());
	agent->setVelocity(agent->getVelocity() + agent->getAcceleration() * dtime);
	agent->setVelocity(agent->getVelocity().Truncate(agent->getArriveSpeed().x));
	agent->setPosition(agent->getPosition() + agent->getVelocity() * dtime);
}
Vector2D Arrive::CalculateSteeringForce(Agent * target, Agent *agent)
{
	
	Vector2D DesiredVelocity = CalculateSeekVelocity(agent, target);
	Vector2D VelDelta = (DesiredVelocity - agent->getVelocity());
	VelDelta /= agent->getArriveSpeed().x;
	Vector2D SteeringForce = VelDelta * agent->getMaxForce();
	return SteeringForce;
}
Vector2D Arrive::CalculateSeekVelocity(Agent * target, Agent *agent)
{
	arriving(agent);
	Vector2D DesiredVelocity = agent->getPosition() - agent->getTarget();
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->getMaxVelocity();
	return DesiredVelocity;
}
void Arrive::arriving(Agent * agent) {
	Vector2D DistanceToTarget;
	float Distance = DistanceToTarget.Dot(agent->getPosition(), agent->getTarget());
	agent->setArriveSpeed (agent->getMaxVelocity());
	float SpeedFactor = 1.0f;
	if (Distance < SlowingRadius)
		SpeedFactor = (Distance / SlowingRadius);
	agent->setArriveSpeed(agent->getArriveSpeed()*SpeedFactor);
}
/*Vector2D DistanceToTarget;
	float Distance=DistanceToTarget.Dot(agent->getPosition(),agent->getTarget());
	Vector2D ArriveSpeed = agent->getMaxVelocity();
	float SpeedFactor = 1.0f;
	if (Distance < SlowingRadius)
		SpeedFactor = (Distance / SlowingRadius);
	ArriveSpeed *= SpeedFactor;
	return ArriveSpeed;*/