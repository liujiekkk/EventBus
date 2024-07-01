#pragma once

#include "Event.h"
#include <string>
#include <memory>

namespace eventBus {

	class IEventHandler;

	class IEventManager {

	public:

		virtual ~IEventManager() {}


		virtual bool attach(const std::string& event, std::shared_ptr<IEventHandler>, int priority = 0) = 0;

		virtual bool detach(const std::string& event, std::shared_ptr<IEventHandler>) = 0;

		virtual void clearListeners(const std::string& evName) = 0;

		virtual void trigger(const Event&) const = 0;

		template<typename Target, typename ...Args>
		void trigger(const std::string&, Target&&, Args&& ...);

	};

	template<typename Target, typename ...Args>
	inline void IEventManager::trigger(const std::string& evName, Target&& target, Args && ...args)
	{
		// 构造 Event 对象，触发实际的监听器.
		Event ev;
		ev.setName(evName);
		// 智能指针指向对象.
		ev.setTarget<Target>(std::make_shared(std::forward<Target>(target)));
		ev.setParams<Args...>(std::forward<Args>(args)...);
		trigger(ev);
	}
}