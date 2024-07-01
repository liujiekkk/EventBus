#pragma once

#ifndef _EVENT_H
#define _EVENT_H

#include <string>
#include <vector>
#include <memory>
#include <tuple>
#include <type_traits>

namespace eventBus {

	class Event {

	public:

		Event(): m_name(), m_data(nullptr) {};

		~Event() {}

		std::string getName() const;

		void setName(const std::string& name);

		template<typename Object>
		std::shared_ptr<Object> getTarget() const;

		template<typename Object>
		void setTarget(std::shared_ptr<Object>);

		template<typename ...Args>
		void setParams(Args&& ...args);

		template<typename ...Args>
		std::tuple<Args...> getParams() const;

	private:

		std::string m_name;

		std::shared_ptr<void> m_target;

		std::shared_ptr<void> m_data;
	};

	template<typename Object>
	inline std::shared_ptr<Object> Event::getTarget() const
	{
		return std::static_pointer_cast<Object>(m_target);
	}

	template<typename Object>
	inline void Event::setTarget(std::shared_ptr<Object> ptr)
	{
		m_target = ptr;
	}

	template<typename ...Args>
	inline void Event::setParams(Args&& ...args)
	{
		m_data = std::make_shared<std::tuple<Args...>>(std::forward<Args>(args)...);
	}

	template<typename ...Args>
	inline std::tuple<Args...> Event::getParams() const
	{
		if (m_data == nullptr) {
			return std::tuple<Args...>();
		}
		return *std::static_pointer_cast<std::tuple<Args...>>(m_data);
	}
}

#endif // !_EVENT_H