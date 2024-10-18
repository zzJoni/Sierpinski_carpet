#pragma once

// Calculates what a number raised to a certain positive power is
constexpr int exponent(const int base, const int power)
{
	int result{ 1 };

	for (int i{ 1 }; i <= power; ++i)
	{
		result *= base;
	}

	return result;
}
