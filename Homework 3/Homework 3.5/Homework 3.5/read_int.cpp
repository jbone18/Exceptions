#include <iostream>
#include <stdexcept>
#include "readint.h"
using namespace std;

int read_int(const string &prompt, int low, int high)
{
	if (low >= high)
	{
		throw invalid_argument("The low integer must be a smaller value than high. ");
	}

	cin.exceptions(ios_base::failbit);

	int num = 0;
	while (true)
	{
		try 
		{
			cout << prompt;
			cin >> num;
			if (num >= high || num <= low)
			{
				throw range_error("Entered value isn't within the specified range.");
			}
			else
			{
				return num;
			}
		}

		catch (ios_base::failure& ex)
		{
			cout << "Bad numeric string -- try again." << endl;
			cin.clear();

			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (range_error)
		{
			cout << "Bad numeric string -- try again." << endl;
			cin.clear();

			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}
}

int main()
{
	do
	{
		int low, high;
		cout << "Enter the range of values to read.\n";
		cout << "high: ";
		cin >> high;
		cout << "low: ";
		cin >> low;
		try
		{
			int number = read_int("Please enter a number within the range: ", low, high);
			cout << "You entered " << number << endl;
		}

		// Rangeof integer values is empty
		catch (invalid_argument &e)
		{
			cerr << "The 'low' integer must be a smaller value than the 'high' integer. ";
		}

		// Number entered excceds the data type 
		catch (range_error &re)
		{
			cout << re.what() << endl;
		}

		//Looks for a specific invalid input
		catch (ios_base::failure &ex)
		{
			cout << "Invalid input." << endl;
			//Clears the cin so a new value can be entered
			cin.clear();
			//Ignores the variables inputted
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	} while (true);
}