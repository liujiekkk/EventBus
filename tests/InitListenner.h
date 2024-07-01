#pragma once

#include "IEventHandler.h"

namespace eventBus {

	class Event;

	class InitListenner : public IEventHandler {

	public:

		void handle(const Event&);

	private:

		void action(int, char);
	};
}