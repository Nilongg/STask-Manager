#include "task.h"


task::task(int id, int priority, std::string name)
{
	this->id = id;
	this->priority = priority;
	this->name = name;
}
int task::getId()
{
	return id;
}
void task::setId(int id)
{
	this->id = id;
}
int task::getPriority()
{
	return priority;
}
void task::setPriority(int priority)
{
	this->priority = priority;
}
std::string task::getName()
{
	return name;
}
void task::setName(std::string name)
{
	this->name = name;
}
task::task()
{
	this->id = 0;
	this->priority = 0;
	this->name = "";
}

