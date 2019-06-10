// stringSwitch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

uint64_t constexpr mix(char m, uint64_t s)
{
	return ((s << 7) + ~(s >> 3)) + ~m;
}

uint64_t constexpr hash(const char* m)
{
	return (*m) ? mix(*m, hash(m + 1)) : 0;
}
void switch_test(const char* str)
{
	switch (hash(str)) // run-time
	{
	case hash("tatatututoto"): // compile-time

		std::cout << "tutu!" << std::endl;
		break;

	case hash("tatatititoto"): // compile-time

		std::cout << "titi!" << std::endl;
		break;

	case hash("tutu"):
	case hash("TUTU"):
		std::cout << "1!" << std::endl;
		break;

	case hash("utut"):

		std::cout << "2!" << std::endl;
		break;

	default:

		std::cout << "wut?" << std::endl;
		break;
	};
}

int main()
{
	switch_test("tatatititoto");
	switch_test("tatatututoto");
	switch_test("abababubabub");
	switch_test("TUTU");
	switch_test("utut");
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
