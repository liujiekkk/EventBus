#include "Event.h"


std::string eventBus::Event::getName() const
{
	return m_name;
}

void eventBus::Event::setName(const std::string& name)
{
	m_name = name;
}