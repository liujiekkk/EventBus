#pragma once

#include "IEventHandler.h"
#include <string>

namespace eventBus {

	class TestListener : public IEventHandler {

	public:

		void handle(const Event&);

	private:

		void action(const std::string& msg);
	};
}