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
	vector<string> raw;

	index_t BaseGet(int findResult)
	{
		if (findResult == -1)
		{
			throw std::invalid_argument("name was not valid enumeration");
		}
		else
		{
			return (index_t)findResult;
		}
	}
public:

	DynamicEnum(vector<string> value = vector<string>());


	index_t Get(string name);


	int Find(string name, index_t start=0);


	int Find(string name, string scope, int start=-1)
	{
		if (start == -1)
		{
			start = First(scope);

			if (start == -1)
				return -1;
		}

		for (index_t index = (index_t)start; index < raw.size(); index++)
		{
			auto currentName = raw[index];

			if (currentName.find(scope) != -1)
			{
				if (currentName.find(name) != -1)
				{
					return (int)index;
				}
			}
		}

		return -1;
	}

	int Get(string name, string scope, int start=-1)
	{
		auto result = Find(name, scope, start);

		return BaseGet(result);
	}


	int First(string substring)
	{
		for (index_t index = 0; index < raw.size(); index++)
		{
			if (raw[index].find(substring) != -1)
			{
				return (int)index;
			}
		}

		return -1;
	}

	int LocalFind(string scope, string name)
	{
		auto rootIndex = First(scope);

		if (rootIndex == -1)
		{
			return -1;
		}

		auto globalResult = Find(name, scope, rootIndex);

		if (globalResult == -1)
		{
			return -1;
		}
		else
		{
			return globalResult - rootIndex;
		}
	}


	index_t LocalGet(string scope, string name)
	{
		auto findResult = LocalFind(scope, name);

		return BaseGet(findResult);
	}


	string Get(index_t enumeration);


	bool Has(index_t enumeration)
	{
		if (enumeration < raw.size())
			return Get(enumeration) != "";
	}


	void Set(string name, index_t enumeration);


	index_t Add(string name);


	unsigned int Size();
};