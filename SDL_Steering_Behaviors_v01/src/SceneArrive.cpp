#include "SceneArrive.h"
#include "Arrive.h"
#include <math.h>

using namespace std;

SceneArrive::SceneArrive()
{
	Agent *agent = new Agent;
	agent->setBehavior(new Arrive);
	agent->setPosition(Vector2D(740,560));
	agent->setMass(0.01);
	agent->setTarget(Vector2D(640, 360));
	agent->loadSpriteTexture("../res/soldier.png", 4);
	agents.push_back(agent);
	target = Vector2D(640, 360);
}

SceneArrive::~SceneArrive()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneArrive::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			agents[0]->setTarget(target);
		}
			/*distance= sqrt(pow(agents[0]-> getPosition.x- event->button.x) +
				pow(agents[0]->getPosition.x - event->button.y, 2) * 1.0);
			if (distance > radius) {
				target = Vector2D((float)(event->button.x), (float)(event->button.y));
				agents[0]->setTarget(target);
			}
			else {
				factor = distance / radius;
				agents[0]->setVelocity(agents[0]->getVelocity*factor);
				agents[0]->setTarget(target);
			}*/
			
		
		break;
	default:
		break;
	}
	agents[0]->update(dtime,event);
}

void SceneArrive::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	agents[0]->draw();
}

const char* SceneArrive::getTitle()
{
	return "SDL Steering Behaviors :: Flee Demo";
}