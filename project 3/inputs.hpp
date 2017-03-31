#ifndef INPUTS_HPP
#define INPUTS_HPP
#include "HashMap.hpp"
#include <string>


class Commands
{
public:
	Commands(); //Constructor
	std::string return_input();
	void parse_input(const std::string& input);

private:
	HashMap hm;
	bool main_commands;
	bool debug_commands;
	std::string input1, input2, input3;
	std::string hd_inv, main_inv, hdc_inv;

	void handle_main_commands(const std::string &input1,
							  const std::string &input2,
						      const std::string &input3);

	void handle_debug_commands(const std::string &input1,
							   const std::string &input2,
							   const std::string &input3);

	void handle_debug(const std::string &input1, 
					  const std::string &input2, 
					  const std::string &input3);


};












#endif //INPUTS_HPP