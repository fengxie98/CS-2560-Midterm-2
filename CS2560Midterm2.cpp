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

	const int getAllowance() {
		std::cout << "Allowance: " << getAllowance() << std::endl;
	}

	void printParent() {
		std::cout << "Mom: " << getmomName() << "and Dad's: " << getdadName() << std::endl;
	}

};

int main()	
{
	std::cout << "hello" << std::endl;
	std::cout<<"Parents: " <<
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
