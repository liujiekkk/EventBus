#include "TestListener.h"
#include "Event.h"
#include <iostream>

void eventBus::TestListener::handle(const Event& ev)
{
	auto params = ev.getParams<std::string>();
	action(std::get<0>(params));
	
}

void eventBus::TestListener::action(const std::string& msg)
{
	std::cout << "Test listener. msg:" << msg << std::endl;
}
