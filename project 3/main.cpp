#include <iostream>
#include "inputs.hpp"
//Asif Mahmud


int main()
{
	Commands c;
	while (1)
	{
		std::string s = c.return_input();
		if (s == "QUIT")
		{
			std::cout << "GOODBYE" << std::endl;
			break;
		}
		c.parse_input(s);

	}
	return 0;
}
