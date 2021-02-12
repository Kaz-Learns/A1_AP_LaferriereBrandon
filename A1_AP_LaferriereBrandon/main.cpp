#include <iostream>
#include "Person.h"
using namespace std;

const string Name[] = { "Jack", "Kelly" , "Tim" , "Brandon", "Mike", "Linda" };
const string cName[] = { "Ryerson", "UofT", "GeorgeBrown" };
const string pName[] = { "Animation", "GameProgram", "Business" };
 string Stream[] = { "Netflix", "Crave", "Amazon Prime" };
const string GameD[] = { "Playstation", "Xbox", "Switch", "PC" };

const int Age[99]{};
const int sNumber[] = { 1,2,3,4,5,6 };
 int sHour[100]{};
const int gHour[100]{};


int main()
{
	srand(time(NULL));

	bool running = true;
	int numStudent = 0;
	const int maxStudent = 500;
	Person* students[maxStudent];
	

	

	while (running)
	{
		int gamingStudent = 0;
		int nonGamingStudent = 0;

		cout << "Welcome to the student survey! \n" << endl;

		cout << "How many students will participate in the survey? (max 500) \n" << endl;
		cin >> numStudent;

		if (numStudent <= maxStudent)
		{
			int rStudent;

			for (int i = 0; i < numStudent; i++)
			{
				
				rStudent = (1 + rand() % 2);
				cout << rStudent << endl;
				switch (rStudent)
				{
				case 1:
					students[i] = new NonGamingStudent( Name[rand() % 5] , 
						1 + rand() % 100, cName[rand() % 2], pName[rand() % 2], rand() % 5, 
						Stream[rand() % 2], rand() % 100 + 1);
					nonGamingStudent++;
					break;
				case 2:
					students[i] = new GamingStudent( Name[rand() % 5],
						1 + rand() % 100, cName[rand() % 2], pName[rand() % 2], rand() % 5, 
						GameD[rand() % 2], rand() % 100 + 1);
					gamingStudent++;
					break;
				default:
					break;
				}
			}
		}
		else
		{
			cout << "invalid" << endl;
		}

		Survey survey(*students, numStudent);

		for (int i = 0; i < numStudent; i++)
		{

			students[i]->DisplayInfo();

		}

		cout << "Non Gaming Students: " << nonGamingStudent <<  endl;
		cout << "Average Age: " << survey.GetAvgAge() << "\n" << endl;

		cout << "Gaming Students: " << gamingStudent <<  endl;
		cout << "Average Age: " << survey.GetAvgAge() << "\n" << endl;


		

		

	}

	return 0;
}

