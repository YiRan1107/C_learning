#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <sstream>

// [Review 1] Read one complete number; the caller checks the allowed range.
bool read_days(int &value)
{
	std::string line;
	if (!std::getline(std::cin, line))
	{
		return false;
	}

	std::istringstream input(line);

	int days;
	char extra;


	if (!(input >> days))
	{
		std::cout << "Oops, illegal input detected,please try it again.\n";
		return false;
	}
	if (input >> extra)
	{
		std::cout << "Oops, illegal input detected: " << line << ". Please try again.\n";
		return false;
	}
	value = days;
	return true;
}

bool read_distance(float &value)
{
	std::string line;
	if (!std::getline(std::cin, line))
	{
		return false;
	}

	std::istringstream input(line);

	float distance;
	char extra;

	if (!(input >> distance))
	{
		std::cout << "Oops, illegal input detected,please try it again.\n";
		return false;
	}
	if (input >> extra)
	{
		std::cout << "Oops, illegal input detected: " << line << ". Please try again.\n";
		return false;
	}
	value = distance;
	return true;
}


struct WalkDataRecord
{
	int day;
	float distance;
};

// [Review 2] Display only; a const reference avoids copying the records.
void print_distances(const std::vector<WalkDataRecord> &records)
{
	for (const WalkDataRecord &record : records)
	{
		std::cout << "Day " << record.day << ": "
			<< record.distance << " km\n";
	}
}

int main()
{
	int walk_days = 0;
	while (true)
	{
		std::cout << "Enter the number of days you walked: ";
		bool success = read_days(walk_days);

		if (!success)
		{
			if (!std::cin)
			{
				return 0;
			}
			continue;
		}

		if (walk_days <= 0 || walk_days > 1000)
		{
			std::cout << "Please enter a number from 1 to 1000.\n";
			continue;
		}

		break;
	}
	float sum = 0.0f;
	float max_distance = 0.0f;
	int max_day = 1;

	std::vector<WalkDataRecord> records(walk_days);

	for (int i = 1; i <= walk_days; i++)
	{
		while (true)
		{
			std::cout << "please enter the " << i << " day you walk:";
			bool success = read_distance(records[i - 1].distance);
			
			// [Review 3] Invalid input retries; only valid input reaches break.
			if (!success)
			{
				if (!std::cin)
				{
					return 0;
				}
				continue;
			}

			if (records[i - 1].distance < 0 || records[i - 1].distance > 1000)
			{
				std::cout << "please enter a right number form 0 to 1000\n";
				continue;
			}

			break;
		}
		
		records[i - 1].day = i;
		sum += records[i - 1].distance;
		// [Review 4] The first valid record establishes the maximum, even at zero.
		if (i == 1 || records[i - 1].distance > max_distance)
		{
			max_distance = records[i - 1].distance;
			max_day = i;
		}
	}
	
	char response;

	while (true)
	{
		std::cout << "do u want to check the details(y/n):";
		if (!(std::cin >> response))
		{
			if (std::cin.eof())
			{
				return 0;
			}

			std::cout << "please enter y/n\n";

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (response == 'y' || response == 'Y' || response == 'n' || response == 'N')
		{
			break;
		} 
		else
		{
			std::cout << "please enter y or n.\n";
		}
	}
	
	if (response == 'y' || response == 'Y')
	{
		print_distances(records);
	}

	std::cout << "the whole distance you walk is: " << sum << "\n";
	
	float average = sum / walk_days;
	std::cout << "the average distance of the day-walk is: " << average << "\n";
	
	if (average >= 3)
		std::cout << "you have a health habit\n";
	else
		std::cout << "acording to the ststitic,you need to exercise more\n";

	std::cout << "the longest walk is on the" << max_day << " about " << max_distance << "\n";

	return 0;
}

