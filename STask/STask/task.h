#pragma once
#include <iostream>
class task
{
	// This is a class that will be used to store the data of the task

	// The id of the task
	int id;
	// The priority of the task (1-5)
	int priority;
	// The name of the task
	std::string name;

	public:
		// constructor of the task
		task();
		// overloaded constructor of the task
		task(int id, int priority, std::string name);

		// Getters and setters
		int getId();
		void setId(int id);
		int getPriority();
		void setPriority(int priority);
		std::string getName();
		void setName(std::string name);











};
