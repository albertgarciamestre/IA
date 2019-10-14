#include "SceneFlocking.h"
#include "Flocking.h"
#include <iostream>

using namespace std;

SceneFlocking::SceneFlocking()
{
	
	Agent *agent;
	for (int i = 0; i < 8; i++) {
		
		agent = new Agent();
		agent->setBehavior(new Flocking);
		agent->setPosition(Vector2D(rand()%700+1, rand()%700+1));
		agent->setMass(0.01);
		agent->setTarget(Vector2D(640, 360));
		agent->loadSpriteTexture("../res/soldier.png", 4);
		agents.push_back(agent);
	}
	
	target = Vector2D(640, 360);
}

SceneFlocking::~SceneFlocking()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneFlocking::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			agents[0]->setTarget(target);
			for (int i = 1; i < 8; i++) {
				agents[i]->setTarget(agents[0]->getPosition());
			}
		}
		break;
	default:
		break;
	}
	for (int i = 0; i < 8; i++) {
		agents[i]->update(dtime, event);
	}
}

void SceneFlocking::draw()
{

	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	for (int i = 0; i < 8; i++) {
		agents[i]->draw();
	}

}

const char* SceneFlocking::getTitle()
{
	return "SDL Steering Behaviors :: Seek Demo";
}