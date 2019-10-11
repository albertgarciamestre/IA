#include "Wander.h"

Wander::Wander() :
	SlowingRadius(5)
{
}

Wander::~Wander()
{
}

void Wander::applySteeringForce(Agent *agent, float dtime)
{
	agent->setSteeringForce(CalculateSteeringForce(agent, agent));
	agent->setAcceleration(agent->getSteeringForce() / agent->getMass());
	agent->setVelocity(agent->getVelocity() + agent->getAcceleration() * dtime);
	agent->setVelocity(agent->getVelocity().Truncate(agent->getArriveSpeed()));
	agent->setPosition(agent->getPosition() + agent->getVelocity() * dtime);
}
Vector2D Wander::CalculateSteeringForce(Agent * target, Agent *agent)
{

	Vector2D DesiredVelocity = CalculateSeekVelocity(agent, target);
	Vector2D VelDelta = (DesiredVelocity - agent->getVelocity());
	VelDelta /= agent->getArriveSpeed();
	Vector2D SteeringForce = VelDelta * agent->getMaxForce();
	return SteeringForce;
}
Vector2D Wander::CalculateSeekVelocity(Agent * target, Agent *agent)
{
	wander(target);
	Vector2D DesiredVelocity = agent->getTarget() - agent->getPosition();
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->getArriveSpeed();
	return DesiredVelocity;
}
void Wander::wander(Agent * agent) {
	Vector2D DistanceToTarget;
	float Distance = DistanceToTarget.Distance(agent->getPosition(), agent->getTarget());
	agent->setArriveSpeed(agent->getMaxVelocity());
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