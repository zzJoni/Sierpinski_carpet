#pragma once
#include <optional>

// Skips over any input left in the input buffer
void ignoreLine();

// Gets a value from the user and handles bad inputs (returns nullopt if failed)
std::optional<int> getIntInput();
