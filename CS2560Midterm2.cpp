// CS2560Midterm2Real.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

class Human {
private:
	std::string name;
	int age;
	char sex;

	//private def cons
	Human() {

	}

protected:
	Human(std::string n, int ag, char sx) :name(n), age(ag), sex(sx) {}

	//under protected
	virtual ~Human() {
		std::cout << "Destructing" << std::endl;
	}

public:
	std::string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	char getSex() {
		return sex;
	}
};

class Parent : public Human {
private:
	std::string Children;

public:
	friend void Parent(std::string n, int ag, char sx) {
		name = n;
		age = ag;
		sex = sx;
	}

	void printChild() {
		std::cout << "Child's Name: Lisa" << std::endl;
		std::cout << "Name: March" << std::endl;
		std::cout << "Name: Bart" << std::endl;
		std::cout << "Name: Maggie" << std::endl;
	}

	void setChild() {

	}

	void setAllowance() {
		int bart = 5;
	}
};

class Child : public Human {
private:
	std::string momName, dadName;
	int allowance;

	friend void Child() {
	}

public:
	friend void Child(std::string n, int ag, char sx, std::string mN, std::string dN){
		name = n;
		age = ag;
		sex = sx;
		momName = mN;
		dadName = dN;
	}

	friend void Child(Parent m, Parent d) {
		mom = m;
		dad = d;
	}

	int setAge() {
		int Maggie = 3;
		int	Bart = 10;
		int Lisa = 12;
	}

	const int getAllowance() {
		std::cout << "Allowance: " << getAllowance() << std::endl;
	}

	void printParent() {
		std::cout << "Mom: " << getmomName() << "and Dad's: " << getdadName() << std::endl;
	}

};

int main()	
{
	Parent par;
	Child chi;
	std::cout << "Parent: " << par.printParentsName();
	std::cout << "Parent: " << par.printParentsAge();
	std::cout << "Parent: " << par.printParentsSex();
	std::cout << "Children: " << par.printChildName();
	std::cout << "Children: " << par.printChildAge();
	std::cout << "Children: " << par.printChildSex();
	
}

//Disclaimer, program does not compile, I couldn't finish the main so basically almost everything is in pseudocode