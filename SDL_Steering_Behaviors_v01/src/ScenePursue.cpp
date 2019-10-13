#include "ScenePursue.h"
#include "Pursue.h"
#include "Evade.h"

using namespace std;

ScenePursue::ScenePursue()
{
	Agent *agent = new Agent;
	agent->setBehavior(new Pursue);

	agent->setTarget(Vector2D(100, 100));
	agent->setPosition(Vector2D(100, 500));
	agent->loadSpriteTexture("../res/zombie1.png", 8);
	agents.push_back(agent);
	agent = new Agent();
	agent->setBehavior(new Pursue);
	agent->setPosition(Vector2D(600, 50));
	agent->setTarget(Vector2D(100, 650));
	agent->loadSpriteTexture("../res/soldier.png", 4);
	agents.push_back(agent);
	target = Vector2D(100, 100);
}

ScenePursue::~ScenePursue()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void ScenePursue::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
		}
		break;
	default:
		break;
	}
	target = agents[1]->getPosition();
	agents[0]->setTarget(target);
	for (int i = 0; i < (int)agents.size(); i++)
	{
		agents[i]->update(dtime, event);
	}

}

void ScenePursue::draw()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		agents[i]->draw();
	}
}

const char* ScenePursue::getTitle()
{
	return "SDL Steering Behaviors :: Seek and Flee Demo";
}