//Asif Mahmud 70556749

#include <iostream>
#include <string>
#include "inputs.hpp"
#include "outputs.hpp"



int main()
{
  // INPUTS
  int number_of_artifacts = get_artifact_number();

  double* total_points = new double[number_of_artifacts];
  get_points(total_points, number_of_artifacts);

  double* weighted_points = new double[number_of_artifacts];
  get_weight(weighted_points, number_of_artifacts);

  int number_of_students = get_student_number();

  std::string* student_info = new std::string[number_of_students];
  get_student_name(student_info, number_of_students);


  int number_of_scores = get_number_of_scores();

  double **raw_scores = new double *[number_of_students];
  for (int i = 0; i < number_of_students; i++)
    {
      raw_scores[i] = new double[number_of_artifacts + 1];
    }
  get_raw_scores(raw_scores, number_of_students, number_of_artifacts);

  
//OUTPUTS
  std::string* id = new std::string[number_of_students];
  double* grade = new double[number_of_students];

  print_scores(student_info, total_points, weighted_points, raw_scores,
  	       number_of_students, number_of_artifacts, id, grade);
  
  int cutpoint_number = get_cutpoint_number();
  
  score_generator(cutpoint_number, number_of_students, id, grade);
  

  //Deallocation
  for (int i=0; i < number_of_students; i++)
    {
      delete[] raw_scores[i];
    }

  delete[] id;
  delete[] grade;
  delete[] raw_scores;
  delete[] student_info;
  delete[] weighted_points;
  delete[] total_points;
  return 0;
}
