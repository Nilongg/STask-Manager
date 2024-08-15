#pragma once
#include <iostream>
struct Task
{
	// A simple struct to represent a task
	
	private:
		int id;
		int priority;
		std::string name;
	
	public:
		Task();
		Task(int id, int priority, std::string name) {
			this->name = name;
			this->id = id;
			this->priority = priority;
		}
		int GetID() {
			return id;
		}
		int GetPriority() {
			return priority;
		}
		std::string GetName() {
			return name;
		}
};
