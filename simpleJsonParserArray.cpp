//author:	junqingmark
//date:		2016-05-07
//mail:		junqingmark@163.com

#include <iostream>
#include <json/json.h>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream ifs;
	ifs.open("simpleJsonParserArray.json");

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

	int size = root.size();
	string name;
	int age;

	for (int i = 0; i < size; ++i)
	{
		name = root[i]["name"].asString();
		age = root[i]["age"].asInt();

		cout << "The " << i << " array name:" << name << endl;
		cout << "The " << i << " array age:" << age << endl;
	}

	return 0;

}