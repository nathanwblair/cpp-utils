#pragma once 

#include <vector>
#include <string>
#include <exception>
#include <stdexcept>

using std::string;
using std::vector;


typedef unsigned int index_t;


class DynamicEnum
{
	std::vector<std::string> raw;
public:

	DynamicEnum(vector<string> value = vector<string>());

	index_t Get(string name);


	int Find(string name);


	string Get(index_t enumeration);


	void Set(string name, index_t enumeration);


	index_t Add(string name);


	unsigned int Size();
};