#pragma once

// Gets the positive integral exponent of a number
constexpr int exponent(const int base, const int power)
{
	int result{ 1 };

	for (int i{ 1 }; i <= power; ++i)
	{
		result *= base;
	}

	return result;
}
