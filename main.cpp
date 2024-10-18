#include "SierpinskiCarpet.h"
#include "getIntInput.h"
#include <iostream>

// Determines how detailed the carpet should be 
// (levels of detail higher than 4 work but do not display well on the terminal)
int getLevelOfDetail()
{
	int levelOfDetail{ 0 };
	
	while (levelOfDetail < 1 || levelOfDetail > 4)
	{
		std::cout << "Enter the level of detail you want the sierpinski carpet to have (1-4): ";
		levelOfDetail = getIntInput().value_or(0);
	}
	
	return levelOfDetail;
}

int main()
{
	SierpinskiCarpet carpet{ getLevelOfDetail()};
	std::cout << '\n';
	carpet.print();

	return 0;
}
