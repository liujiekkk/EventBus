#include "manager/EventManager.h"
#include "Event.h"
#include "IEventHandler.h"

eventBus::EventManager::EventManager() : m_data()
{
}

bool eventBus::EventManager::attach(const std::string& evName, std::shared_ptr<IEventHandler> pHandler, int priority)
{
	auto ln = ListenerNode{ pHandler, priority };
	// 判断当前事件是否已经有监听器队列(这里set会自动去重).
	auto iter = m_data.find(evName);
	if (iter != m_data.end()) {
		iter->second.insert(ln);
		return true;
	} else {
		// 构建一个新的队列.
		ListenerSet q;
		// 增加新的监听器.
		q.insert(ln);
		auto result = m_data.insert(std::make_pair(evName, q));
		return result.second;
	}
}

bool eventBus::EventManager::detach(const std::string& evName, std::shared_ptr<IEventHandler> pHandler)
{
	auto iter = m_data.find(evName);
	if (iter == m_data.end()) {
		return false;
	}
	for (auto& element : iter->second) {
		// 如果两个智能指针指向同一个handler对象，开始删除set中此节点.
		if (element.handler == pHandler) {
			iter->second.erase(element);
		}
	}
	return true;
}

void eventBus::EventManager::clearListeners(const std::string& evName)
{
	auto iter = m_data.find(evName);
	if (iter != m_data.end()) {
		m_data.erase(iter);
	}
}

void eventBus::EventManager::trigger(const Event& ev) const
{
	auto iter = m_data.find(ev.getName());
	if (iter == m_data.end()) {
		return;
	}
	for (auto& element : iter->second) {
		element.handler->handle(ev);
	}
}
