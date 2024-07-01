#pragma once

#include "IEventManager.h"
#include <set>
#include <unordered_map>

namespace eventBus {

	class EventManager : public IEventManager {
	
	public:

		struct ListenerNode
		{
			std::shared_ptr<IEventHandler> handler;
			int priority;
		};

		struct CompFunc {

			bool operator()(const ListenerNode& lhs, const ListenerNode& rhs) const
			{
				return lhs.priority < rhs.priority;
			}
		};

		// �����ȶ�������������ֹ�Ժ��м�����ȥ�ص�����
		using ListenerSet = std::set<ListenerNode, CompFunc> ;

		using IEventManager::trigger;

		EventManager();

		bool attach(const std::string& evName, std::shared_ptr<IEventHandler> pHandler, int priority = 0);

		virtual bool detach(const std::string& evName, std::shared_ptr<IEventHandler> pHandler);

		virtual void clearListeners(const std::string& evName);

		void trigger(const Event& ev) const;

	private:

		std::unordered_map<std::string, ListenerSet> m_data;
	};
}