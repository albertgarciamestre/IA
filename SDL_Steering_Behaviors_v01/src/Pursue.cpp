#include "Pursue.h"

Pursue::Pursue() :
	MaxLookAheadTime(5),
	PredictedTarget(0,0)
{
}

Pursue::~Pursue()
{
}

void Pursue::applySteeringForce(Agent *agent, float dtime)
{
	agent->setSteeringForce(CalculateSteeringForce(agent, agent));
	agent->setAcceleration(agent->getSteeringForce() / agent->getMass());
	agent->setVelocity(agent->getVelocity() + agent->getAcceleration() * dtime);
	agent->setVelocity(agent->getVelocity().Truncate(agent->getArriveSpeed()));
	agent->setPosition(agent->getPosition() + agent->getVelocity() * dtime);
}
Vector2D Pursue::CalculateSteeringForce(Agent * target, Agent *agent)
{

	Vector2D DesiredVelocity = CalculateSeekVelocity(agent, target);
	Vector2D VelDelta = (DesiredVelocity - agent->getVelocity());
	VelDelta /= agent->getArriveSpeed();
	Vector2D SteeringForce = VelDelta * agent->getMaxForce();
	return SteeringForce;
}
Vector2D Pursue::CalculateSeekVelocity(Agent * target, Agent *agent)
{
	pursue(target);
	Vector2D DesiredVelocity = PredictedTarget - agent->getPosition();
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->getArriveSpeed();
	return DesiredVelocity;
}
void Pursue::pursue(Agent * agent) {
	
	Vector2D DistanceToTarget;
	float Distance = DistanceToTarget.Distance(agent->getPosition(), agent->getTarget());
	float T =  Distance/ agent->getMaxVelocity();
	PredictedTarget = agent->getTarget() + agent->getTargetVelocity()*T;
	
}
/*Vector2D DistanceToTarget;
	float Distance=DistanceToTarget.Dot(agent->getPosition(),agent->getTarget());
	Vector2D ArriveSpeed = agent->getMaxVelocity();
	float SpeedFactor = 1.0f;
	if (Distance < SlowingRadius)
		SpeedFactor = (Distance / SlowingRadius);
	ArriveSpeed *= SpeedFactor;
	return ArriveSpeed;*/