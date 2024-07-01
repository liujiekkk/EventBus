#include "InitListenner.h"
#include "Event.h"
#include <iostream>

void eventBus::InitListenner::handle(const eventBus::Event& ev)
{
	auto tuple = ev.getParams<int, char>();
	action(std::get<0>(tuple), std::get<1>(tuple));
}

void eventBus::InitListenner::action(int i, char c)
{
	std::cout << "init listenner action. int:" << i << " char:" << c << std::endl;
}
