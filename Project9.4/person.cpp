#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Person
{
public:
	Person();
	Person (string p);
	void befriend(Person* p);
	void unfriend(Person* p);
	void getFriendNames();
	int getFriendCount();
private:
	string name;
	vector<Person*> friends;
};

Person::Person() {};
Person::Person(string p)
{
	name = p;
}
void Person::befriend(Person* p)
{
	friends.push_back(p);
	return;
}

void Person::unfriend(Person* p)
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (friends.at(i) == p)
		{
			friends.erase (friends.begin()+i);
		}
	}
	return;
}

void Person::getFriendNames()
{
	for (int i = 0; i < friends.size(); i++)
	{
		cout << friends[i]->name << endl;
	}
	cout << endl;
	return;
}

int Person::getFriendCount()
{	
	int friendCount = (friends.size());
	return friendCount;
}


int main()
{
	Person john("john");
	Person joey("joey");
	Person sam("sam");
	john.befriend(&joey);
	john.befriend(&sam);
	joey.befriend(&john);
	sam.befriend(&john);
	john.getFriendNames();
	joey.getFriendNames();
	
	cout << john.getFriendCount() << " " << joey.getFriendCount() << endl;

	john.unfriend(&joey);
	
	john.getFriendNames();
	sam.getFriendNames();

	return 0;
}