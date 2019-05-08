#include "pch.h"
#include <string>
#include <iostream>
#include <vector>

class Human
{
private:
	std::string name;
	int age;
	char sex;
	Human();

protected:
	Human(std::string n, int a, char s) :name(n), age(a), sex(s) 
	{

	}

	virtual ~Human() 
	{

	}

public:
	std::string getName() 
	{ 
		return name; 
	}

	int getAge() 
	{ 
		return age;
	}
	
	char getSex() 
	{ 
		return sex; 
	}

	void setAge(int a)
	{
		age = a;
	}

	void setSex(int s)
	{
		sex = s;
	}

	void setString(std::string n)
	{
		name = n;
	}
};

class Child : public Human
{
private:
	std::string momName;
	std::string dadName;
	int allowance;
	Child();
	friend class Parent;

public:
	Child(std::string n, int a, char s, std::string mN, std::string dN) :Human(n, a, s), momName(mN), dadName(dN), allowance(0) 
	{
	
	}

	~Child() 
	{ 
	
	}

	int getAllowance() const 
	{ 
		return allowance; 
	}

	void printParent() {
		printf("Mom's Name: %s\n", momName.c_str());
		printf("Dad's Name: %s\n", dadName.c_str());
	}
};

class Parent :public Human
{
private:
	std::vector<std::string> children;
	std::vector<Child> childrens;
	Parent();
public:
	Parent(std::string n, int a, char s) :Human(n, a, s)
	{

	}

	~Parent() 
	{ 
		children.clear(); childrens.clear(); 
	}

	void printChild()
	{
		for (int i = 0; i < children.size(); i++) 
		{
			std::cout << children.at(i) << ' ';
		}
	}

	void setChild(Child c)
	{
		children.push_back(c.getName());
		childrens.push_back(c);
	}

	void setChildAllowance(int a, Child& c)
	{
		c.allowance = a;
	}
};

void printInfo(Human &h)
{
	printf("Name: %s\n", h.getName().c_str());
	printf("Age: %d\n", h.getAge());
	printf("Sex: %c\n", h.getSex());
}

int main()
{
	Parent Homer("Homer", 36, 'M');
	Parent March("March", 34, 'F');
	Child Lisa("Lisa", 12, 'F', "March", "Homer");
	Child Bart("Bart", 10, 'M', "March", "Homer");
	Child Maggie("Maggie", 3, 'F', "March", "Homer");
	Homer.setChild(Lisa);
	Homer.setChild(Bart);
	Homer.setChild(Maggie);
	March.setChild(Lisa);
	March.setChild(Bart);
	March.setChild(Maggie);
	printf("Bart's initial allowance is: %d\n", Bart.getAllowance());
	Homer.setChildAllowance(5, Bart);
	printf("Bart's new allowance is: %d\n", Bart.getAllowance());
	Bart.printParent();
	printInfo(March);
	printInfo(Lisa);

	return 0;
}
