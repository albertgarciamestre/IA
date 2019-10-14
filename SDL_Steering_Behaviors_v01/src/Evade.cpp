#include "Evade.h"
#include <iostream>
Evade::Evade() :
	MaxLookAheadTime(5),
	PredictedTarget(0, 0)
{
}

Evade::~Evade()
{
}

void Evade::applySteeringForce(Agent *agent, float dtime)
{
	agent->setSteeringForce(CalculateSteeringForce(agent, agent));
	agent->setAcceleration(agent->getSteeringForce() / agent->getMass());
	agent->setVelocity(agent->getVelocity() + agent->getAcceleration() * dtime);
	agent->setVelocity(agent->getVelocity().Truncate(agent->getMaxVelocity()));
	agent->setPosition(agent->getPosition() + agent->getVelocity() * dtime);
}
Vector2D Evade::CalculateSteeringForce(Agent * target, Agent *agent)
{

	DesiredVelocity = CalculateSeekVelocity(agent, target);
	Vector2D VelDelta = (DesiredVelocity - agent->getVelocity());
	VelDelta /= agent->getMaxVelocity();
	Vector2D SteeringForce = VelDelta * agent->getMaxForce();	std::cout << DesiredVelocity.x << DesiredVelocity.y << std::endl;
	return SteeringForce;
}
Vector2D Evade::CalculateSeekVelocity(Agent * target, Agent *agent)
{
	evade(agent,target);
	DesiredVelocity = agent->getPosition()-PredictedTarget  ;
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->getMaxVelocity();
	return DesiredVelocity;
}
void Evade::evade(Agent * agent, Agent * target) {

	Vector2D DistanceToTarget;
	float Distance = DistanceToTarget.Distance(agent->getPosition(), agent->getTarget());
	float T = Distance / agent->getMaxVelocity();
	PredictedTarget = agent->getTarget() + target->getVelocity()*T;

}
/*Vector2D DistanceToTarget;
	float Distance=DistanceToTarget.Dot(agent->getPosition(),agent->getTarget());
	Vector2D ArriveSpeed = agent->getMaxVelocity();
	float SpeedFactor = 1.0f;
	if (Distance < SlowingRadius)
		SpeedFactor = (Distance / SlowingRadius);
	ArriveSpeed *= SpeedFactor;
	return ArriveSpeed;*/