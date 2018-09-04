#include "stdafx.h"
#include "MyEvent.h"


MyEvent::MyEvent() : MyEvent([]() {}) {
	
}

MyEvent::MyEvent(std::function<void()> _function) {
	function = _function;
}


void MyEvent::instructions() {
	std::mutex m;
	while (1) {
		m.lock();
		function();
		m.unlock();
	}
}



MyEventManager::MyEventManager() {

}

void MyEventManager::addEvent(MyEvent _event) {
	eventData.push_back(_event);
}

void MyEventManager::addVectorEvent(std::vector<MyEvent> _eventVector) {
	eventData = _eventVector;
}


void MyEventManager::start() {
	for (auto& e : eventData) {
		std::thread _thread(&MyEvent::instructions, e);
		threadData.push_back(std::move(_thread));
	}
	for (auto&& t : threadData) {
		t.detach();
	}
}