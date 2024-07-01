#pragma once

namespace eventBus {

	class Event;

	class IEventHandler {

	public:

		virtual ~IEventHandler() {}

		virtual void handle(const Event&) = 0;
	};
}