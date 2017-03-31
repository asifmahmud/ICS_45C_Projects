#include <iostream>
#include <string>
#include <sstream>
#include "inputs.hpp"



Commands::Commands()
	:main_commands(true), debug_commands(false)
{
	HashMap hm;
}

std::string Commands::return_input()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}

void Commands::handle_debug(const std::string &input1,
							const std::string &input2,
							const std::string &input3)
{
	if (input1 == "DEBUG" && input2 == "ON" && debug_commands)
	{
		std::cout << "ON ALREADY" << std::endl;
		
	}

	else if (input1 == "DEBUG" && input2 == "ON" && !debug_commands)
	{
		debug_commands = true;
		std::cout << "ON NOW" << std::endl;
		
	}
	else if (input1 == "DEBUG" && input2 == "OFF" && !debug_commands)
	{
		std::cout << "OFF ALREADY" << std::endl;
	
	}
	else if (input1 == "DEBUG" && input2 == "OFF" && debug_commands)
	{
		debug_commands = false;
		std::cout << "OFF NOW" << std::endl;
		
	}

	else if (!debug_commands && ((input1 == "LOGIN"	&& input2 == "COUNT")  ||
							(input1 == "BUCKET" && input2 == "COUNT")  ||
							(input1 == "LOAD"	&& input2 == "FACTOR") ||
							(input1 == "MAX"	&& input2 == "BUCKET" && input3 == "SIZE")))
	{
		std::cout << "INVALID" << std::endl;
		
	}
	else
	{
		hd_inv = "INVALID";
	}

}

void Commands::handle_main_commands(const std::string &input1,
									const std::string &input2,
									const std::string &input3)
{
	//CREATE
	if (input1 == "CREATE" && input2 != "none" && input3 != "none")
	{
		if (hm.contains(input2))
		{
			std::cout << "EXISTS" << std::endl;
			
		}
		else
		{
			hm.add(input2, input3);
			std::cout << "CREATED" << std::endl;
			
			
		}
	}

	//REMOVE
	else if (input1 == "REMOVE" && input2 != "none")
	{
		if (hm.contains(input2))
		{
			hm.remove(input2);
			std::cout << "REMOVED" << std::endl;
			
		}
		else
		{
			std::cout << "NONEXISTENT" << std::endl;
			
		}
	}

	//LOGIN
	else if (input1 == "LOGIN" && input2 != "none" && input3 != "none")
	{
		if (hm.contains(input2) && (hm.value(input2) == input3))
		{
			std::cout << "SUCCEEDED" << std::endl;
			
		}
		else
		{
			std::cout << "FAILED" << std::endl;
			
		}
	}

	//CLEAR
	else if (input1 == "CLEAR")
	{
		hm.clear();
		std::cout << "CLEARED" << std::endl;
		
	}

	else
	{
		main_inv = "INVALID";
	}



}

void Commands::handle_debug_commands(const std::string &input1,
									 const std::string &input2,
									 const std::string &input3)
{
	if (debug_commands)
	{
		if (input1 == "LOGIN" && input2 == "COUNT")
		{
			std::cout << hm.size() << std::endl;
			
		}
		else if (input1 == "BUCKET" && input2 == "COUNT")
		{
			std::cout << hm.bucketCount() << std::endl;
			
		}
		else if (input1 == "LOAD" && input2 == "FACTOR")
		{
			std::cout << hm.loadFactor() << std::endl;
			
 		}
		else if (input1 == "MAX"	&& input2 == "BUCKET" && input3 == "SIZE")
		{
			std::cout << hm.maxBucketSize() << std::endl;
			
		}
		else
		{
			hdc_inv = "INVALID";
		}

	}
	
}



void Commands::parse_input(const std::string& input)
{
	
	std::istringstream i(input);
	i >> input1 >> input2 >> input3;
	
	
	if (input1 == "" || input1 == "none")
	{
		input1 = "none";
	}
	else if (input2 == "" || input2 == "none")
	{
		input2 = "none";
	}
	else if (input3 == "" || input3 == "none")
	{
		input3 = "none";
	}


	handle_debug_commands(input1, input2, input3);
	handle_debug(input1, input2, input3);
	handle_main_commands(input1, input2, input3);
	

	if (hd_inv == "INVALID" && main_inv == "INVALID" && !debug_commands)
	{
		std::cout << "INVALID" << std::endl;
	}
	if (hd_inv == "INVALID" && main_inv == "INVALID" && hdc_inv == "INVALID")
	{
		std::cout << "INVALID" << std::endl;
	}

	input1 = "none"; input2 = "none"; input3 = "none";
	hd_inv = ""; main_inv = ""; hdc_inv = "";


}
