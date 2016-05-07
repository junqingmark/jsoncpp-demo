//author:	junqingmark
//date:		2016-05-07
//mail:		junqingmark@163.com

#include <iostream>
#include <json/json.h>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	std::ifstream ifs;
	ifs.open("simpleJsonParser.json");

	if (!ifs.is_open())
	{
		std::cout << "fail to open the json file!" << std::endl;
		return 1;
	}

	Json::Reader reader;
	Json::Value root;

	if(false == reader.parse(ifs, root, false) )
	{
		std::cout << "fail to parse the json file!" << std::endl;
		return 1;
	}

	std::string name = root["name"].asString();
	int age = root["age"].asInt();

	std::cout << "Name is: " << name << std::endl;
	std::cout << "Age is: " << age << std::endl;



	return 0;
}