#include <iostream>
#include <string>
#include "outputs.hpp"
#include "inputs.hpp"

int get_cutpoint_number()
{
	int cutpoint;
	std::cin >> cutpoint;
	return cutpoint;
}

//################################################################

std::string grade_calculator(double* cutpoint, double score)
{
  std::string grade;
  if (score >= cutpoint[0]) { grade = "A";}
  else if (score < cutpoint[0] && score >= cutpoint[1]){ grade = "B";}
  else if (score < cutpoint[1] && score >= cutpoint[2]){ grade = "C";}
  else if (score < cutpoint[2] && score >= cutpoint[3]){ grade = "D";}
  else 	{ grade = "F";}
  return grade;
}

//################################################################

void score_generator(int size, int num_students, std::string* id, double* student_grade)
{
	double cutpoints;
	typedef double* doubleptr;
	doubleptr p = new double[4];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cin >> cutpoints;
			p[j] = cutpoints;
		}
		std::cout << "CUTPOINT SET " << i+1 << std::endl;
		for (int k = 0; k < num_students; k++)
		{
		  std::cout << id[k] << " " << grade_calculator(p, student_grade[k]) << std::endl;
		}
		
	}
	delete[] p;
}
//################################################################


double percentage_calculator(double* total_scores, double* weighted_scores, double* raw_scores, int size)
{
	double score = 0.0;
	double* d;
        d = new double[size];
	for (int i = 0; i < size; i++)
	{
		d[i] = (raw_scores[i+1]/total_scores[i])*weighted_scores[i];
	}
	for (int j = 0; j < size; j++)
	{
		score += d[j];
	}
	delete[] d;
	return score;
}


//################################################################

std::string find_id(std::string student_info)
{
	std::size_t pos;
	pos = student_info.find(' ',0);
	std::string s = student_info.substr(0,pos); 
	return s;
}

//#################################################################
double d_converter(std::string value)
{
  double val = std::stod(value);
  return val;
}

//#################################################################

void print_scores(std::string* student_info, double* total_scores, double* weighted_scores, double** raw_scores, int number_of_students, int number_of_scores, std::string* id, double* grade)
{
	std::cout << "TOTAL SCORES" << std::endl;
	for (int i = 0; i < number_of_students; i++)
	{
	  double* score_list = raw_scores[i];
	  for (int j = 0; j < number_of_students; j++)
	    {
	      if (score_list[0] == d_converter(find_id(student_info[j])))
		{
		 double g = percentage_calculator(total_scores, weighted_scores, score_list, number_of_scores);
		  std::cout << student_info[j] << " " << g << std::endl;
		  id[j] = student_info[j];
		  grade[j] = g;
		  
		}
	    }
	}
}


















