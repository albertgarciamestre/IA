#include "Wander.h"

Wander::Wander() :
	 WanderMaxAngleChange(3),
// Distance from Agent to Wander Circle Center
 WanderOffset(1),
 WanderRadius(2),
	 DesiredVelocity(Vector2D(0,0)),
 WanderAngle(0),
 TargetAngle(0)
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

	 DesiredVelocity = CalculateSeekVelocity(agent, target);
	Vector2D VelDelta = (DesiredVelocity - agent->getVelocity());
	VelDelta /= agent->getArriveSpeed();
	Vector2D SteeringForce = VelDelta * agent->getMaxForce();
	return SteeringForce;
}
Vector2D Wander::CalculateSeekVelocity(Agent * target, Agent *agent)
{
	wander(target);
	//upadte wander angle
	
	 WanderAngle += RandomBinomial() * WanderMaxAngleChange;
	TargetAngle = /*Agent.orientation*/WanderAngle;
	 DesiredVelocity = agent->getTarget() - agent->getPosition();
	DesiredVelocity.Normalize();
	DesiredVelocity *= agent->getArriveSpeed();
	return DesiredVelocity;
}
void Wander::wander(Agent * agent) {
	Vector2D CircleCenter = agent->getPosition() + DesiredVelocity.Normalize() * WanderOffset;
	Vector2D TargetPosition;
	TargetPosition.x = CircleCenter.x +
		WanderRadius * cos(TargetAngle);
	TargetPosition.y = CircleCenter.y +
		WanderRadius * sin(TargetAngle);
}
// Returns a random number between -1 and 1 inclusive
float Wander::RandomBinomial() {
	return (rand() / (RAND_MAX)) - (rand() / (RAND_MAX));
}
float lerp(float a, float b, float f)
{
	return a + f * (b - a);
}
float Wander::Orientacio(Agent *agent) {
	float angleToUpdate = atan2f(agent->getVelocity().x, agent->getVelocity().y);
	float angleDelta = angleToUpdate - WanderAngle;
	if (angleDelta > 180.0f)
		WanderAngle += 360.0f;
	else if (angleDelta < -180.0f)
		WanderAngle -= 360.0f;
	WanderAngle = lerp(WanderAngle, angleToUpdate, 0.1f);
}
/*Vector2D DistanceToTarget;
	float Distance=DistanceToTarget.Dot(agent->getPosition(),agent->getTarget());
	Vector2D ArriveSpeed = agent->getMaxVelocity();
	float SpeedFactor = 1.0f;
	if (Distance < SlowingRadius)
		SpeedFactor = (Distance / SlowingRadius);
	ArriveSpeed *= SpeedFactor;
	return ArriveSpeed;*/