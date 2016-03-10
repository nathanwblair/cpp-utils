//
// Created by nathanwblair on 3/10/2016.
//

#include "DynamicEnum.h"

index_t DynamicEnum::Get(string name) {
	auto result = Find(name);

	if (result != -1)
	{
		return (index_t)result;
	}
	else
	{
		throw std::invalid_argument("name was not valid enumeration");
	}

}

int DynamicEnum::Find(string name) {
	for (index_t index = 0; index < raw.size(); index++)
	{
		if (raw[index] == name)
		{
			return (int)index;
		}
	}

	return -1;
}

string DynamicEnum::Get(index_t enumeration) {
	return raw[enumeration];
}

void DynamicEnum::Set(string name, index_t enumeration) {
	if (enumeration < raw.size())
	{
		raw[enumeration] = name;
	}
	else
	{
		raw.resize(enumeration + 1);
		raw[enumeration] = name;
	}
}

index_t DynamicEnum::Add(string name) {
	auto enumeration = raw.size();

	raw.push_back(name);

	return enumeration;
}

DynamicEnum::DynamicEnum(vector<string> value) : raw(value) {
}

unsigned int DynamicEnum::Size()
{
	return raw.size();
}