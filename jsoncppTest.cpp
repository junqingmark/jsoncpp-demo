//author:	junqingmark
//date:		2016-05-07
//mail:		junqingmark@163.com

#include <iostream>
#include <json/json.h>

using namespace std;

void readJson()
{
	std::string strValue = "{\"name\":\"json\",\"array\":[{\"cpp\":\"jsoncpp\"},{\"java\":\"jsoninjava\"},{\"php\":\"support\"}]}";

	Json::Reader reader;
	Json::Value root;

	if (false != reader.parse(strValue, root))
	{
		string name = root["name"].asString();
		cout << name << endl;

		Json::Value array = root["array"];
		for (int i = 0; i < array.size(); ++i)
		{
			if (false == array[i].isMember("cpp"))
			{
				continue;
			}
			string cpp = array[i]["cpp"].asString();
			//string java = array[i]["java"].asString();
			//string php = array[i]["php"].asString();

			cout << cpp << endl;
		}
	}
} 


void writeJson()
{
	Json::Value root;
	Json::Value array;
	Json::Value item;

	item["cpp"] = "cppjson";
	item["java"] = "javajson";
	item["php"] = "support";

	array.append(item);

	root["name"] = "json";
	root["array"] = array;

	//root.toStyledString();

	string result = root.toStyledString();

	cout << result << endl;
}


int main(int argc, char* argv[])
{
	readJson();
	writeJson();
	return 0;
}