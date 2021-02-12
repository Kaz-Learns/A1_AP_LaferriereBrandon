#pragma once
#ifndef _PERSON_
#define _PERSON_
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string m_name;
	int m_age;
	
public:
	Person()
	{
		SetName("");
		SetAge(0);
	}
	Person(string name, int age)
	{
		SetName(name);
		SetAge(age);
	}
	void SetName(string name)
	{
		this->m_name = name;
	}
	string GetName()const
	{
		return m_name;
	}
	void SetAge(int age)
	{
		this->m_age = age;
	}
	int GetAge()const
	{
		return m_age;
	}
	virtual void DisplayInfo() const = 0;
	virtual void GetPrefered() const = 0;
	

	 

};

enum College {Ryerson, UofT, GeorgeBrown };
enum Program {Animation, GameProgram, Business};


class Student : public Person
{
private:
	string m_college;
	string m_program;
	int m_semester = 0;
	int rCollege;
	int rProgram;
public:
	Student(string name, int age, string c, string p, int semester) : Person(name, age)
	{
		SetCollege(c);
		SetProgram(p);
		SetSemester(semester);
	}

	//getters and setters
	virtual void DisplayInfo() const{}

	void SetCollege(string c)
	{
		m_college = c;
	}
	virtual string GetCollege() const
	{
		return m_college;
	}
	void SetProgram(string p)
	{
		
		m_program = p;
	}
	string GetProgram() const
	{

		return m_program;
	}
	void SetSemester(int s)
	{
		this->m_semester = s;
	}
	int GetSemester() const
	{
		return m_semester;
	}
};

//enum StreamService {Netflix, Crave, Amazon_Prime};
//enum GamingDevice {Playstation, Xbox, Switch, PC};

class NonGamingStudent : public Student
{
private:
	const string title = "Non Gaming Student";
	string m_streamS;
	int m_hourE;
	const bool gamingPerson = false;
public:
	NonGamingStudent(string name, int age, string c, string p, int semester, string stream, int hour) : Student(name, age, c, p, semester)
	{
		SetStream(stream);
		SetHourE(hour);
	}
	virtual void GetPrefered() const
	{
		GetStream();
	}
	
	virtual void DisplayInfo() const
	{
		cout << "\n" << endl
			//<< title << endl
			<< "Name: " << Person::GetName() << endl
			<< "Age: " << Person::GetAge() << endl
			<< "College: " << Student::GetCollege() << endl
			<< "Program: " << Student::GetProgram() << endl
			<< "Streaming Service: " << GetStream() << endl
			<< "Hours watched: " << GetHourE() << endl;
	}

	//getters and setters
	void SetStream(string stream)
	{
		this->m_streamS = stream;
	}
	string GetStream()const
	{
		return m_streamS;
	}
	void SetHourE(int hour)
	{
		this->m_hourE = hour;
	}
	int GetHourE() const
	{
		return m_hourE;
	}
	
};

class GamingStudent : public Student
{
private: 
	const string title = "Gaming Student";
	string m_gamingD;
	int m_hourG;
	const bool gamingPerson = true;
public :
	GamingStudent(string name, int age, string c, string p, int semester, string gamed, int hour) : Student(name, age, c, p, semester)
	{
		SetGameD(gamed);
		SetHourG(hour);
	}

	virtual void GetPrefered() const
	{
		GetGameD();
	}

	virtual void DisplayInfo() const
	{
		cout << "\n" << endl
			//<< title << endl
			<< "Name: " << Person::GetName() << endl
			<< "Age: " << Person::GetAge() << endl
			<< "College: " << Student::GetCollege() << endl
			<< "Program: " << Student::GetProgram() << endl
			<< "Streaming Service: " << GetGameD() << endl
			<< "Hours watched: " << GetHourG() << endl;
	}

	//getters and setters
	void SetGameD(string gamed)
	{
		m_gamingD = gamed;
	}
	string GetGameD() const
	{
		return m_gamingD;
	}
	void SetHourG(int hour)
	{
		this->m_hourG = hour;
	}
	int GetHourG()const
	{
		return m_hourG;
	}
	
};

class Survey 
{
private:
	Person* person;
	int NUM_PEOPLE;
public:
	Survey(Person* person, int num)
	{
		SetPerson(person);
		SetNum(num);
	}
	int GetAvgAge()
	{
		float average;
		float aveAge = 0.0;
		
		for (int i = 0; i < NUM_PEOPLE; i++)
		{
			
			aveAge += person[i].GetAge();
		}

		average = aveAge / NUM_PEOPLE;
		return average;
	}
	void GetPrefered()
	{
		
	}
	virtual void GetPrefered() const
	{
		for (int i = 0; i < NUM_PEOPLE; i++)
		{
			person[i].GetPrefered();
		}
	}

	void SetPerson(Person* person)
	{
		this->person = person;
	}
	Person* GetPerson()
	{
		return person;
	}
	void SetNum(int num)
	{
		NUM_PEOPLE = num;
	}
	int GetNun()
	{
		return NUM_PEOPLE;
	}

};

#endif // !_STUDENT_