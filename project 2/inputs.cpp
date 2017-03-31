#include <iostream>
#include <string>
#include "inputs.hpp"


//Getting graded artifacts
//#################################################

int get_artifact_number()
{
	int artifact_num;
	std::cin >> artifact_num;
	return artifact_num;
	
}

double* get_points(double points[], int size)
{
	double p;
	for (int i = 0; i < size; i++)
	{
		std::cin >> p;
		points[i] = p;
	}
	return points;

}

double* get_weight(double weight[], int size)
{
	double w;
	for (int i = 0; i < size; i++)
	{
		std::cin >> w;
		weight[i] = w;
	}
	return weight;
}



//Getting Student Information
//##################################################

int get_student_number()
{
	int student_num;
	std::cin >> student_num;
	return student_num;
}

void get_student_name(std::string* info, int size)
{

	for (int i = 0; i < size; i++)
	{
	  std::string id, name = "";
	  std::cin >> id;
	  std::getline(std::cin, name);
	  std::string student = id + " " + name;
	  info[i] = student;
	}
}



//Getting raw scores
//################################################

int get_number_of_scores()
{
	int scores;
	std::cin >> scores;
	//student.number_of_scores = scores;
	return scores;
}


void get_raw_scores(double** score_list, int num_of_students, int num_of_scores)
{
  double score;

	for (int i = 0; i < num_of_students; i++)
	{
	  for (int j = 0; j < num_of_scores + 1; j++)
	    {
    
		std::cin >> score;
		score_list[i][j] = score;
	    }	
	}

}













