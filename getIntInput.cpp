#include "getIntInput.h"
#include <iostream>
#include <optional>

// Skips over any input left in the input buffer
void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Gets a value from the user and handles bad inputs (returns nullopt if failed)
std::optional<int> getIntInput()
{
	int input{};
	std::cin >> input;

	// Ends program if end of file character is entered or the input stream irrevocably fails 
	if (std::cin.eof() || std::cin.bad())
	{
		exit(0);
	}

	// Handles failed input stream
	if (!std::cin)
	{
		std::cin.clear();
		ignoreLine();
		return std::nullopt;
	}

	ignoreLine();
	return input;
}
