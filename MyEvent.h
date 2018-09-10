#pragma once
#include <vector>
#include <thread>
#include <mutex>
#include <iostream>
#include <memory>
 
class MyEvent {
private:
	std::function<void()> function; 

public:
	MyEvent();
	MyEvent(std::function<void()> _function);

	void instructions(std::mutex& _mutex);
};

class MyEventManager {
private:
	std::vector<MyEvent> eventData;
	std::vector<std::thread> threadData;
	std::mutex mutex;


public:
	MyEventManager();

	void addEvent(MyEvent _event);
	void addVectorEvent(std::vector<MyEvent> _eventVector);
	void start();
};
