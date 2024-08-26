#pragma once
#include <iostream>
struct Task
{
	// A simple struct to represent a task
	
	private:
		DWORD id;
		int priority;
		std::wstring name;
	
	public:
		Task();
		Task(DWORD id, std::wstring name, int priority) {
			this->name = name;
			this->id = id;
			this->priority = priority;
		}
		DWORD GetID() {
			return id;
		}
		int GetPriority() {
			return priority;
		}
		std::wstring GetName() {
			return name;
		}
};
