#include <iostream>
#include "Event.h"
#include "manager/EventManager.h"
#include "TestListener.h"
#include "InitListenner.h"

using namespace std;

int main()
{
	eventBus::Event event;
	event.setName("ev.test");
	event.setParams<std::string>("hello lj");
	event.setTarget(std::make_shared<int>(2024));

	eventBus::Event event2;
	event2.setName("ev.test2");
	event2.setParams<int, char>(99, 'z');
	event2.setTarget(std::make_shared<int>(2024));

	eventBus::EventManager manager;
	manager.attach(event.getName(), std::make_shared<eventBus::TestListener>(), 3);
	manager.attach(event2.getName(), std::make_shared<eventBus::InitListenner>(), 1);
	manager.trigger(event);
	manager.trigger(event2);
	return 0;
}