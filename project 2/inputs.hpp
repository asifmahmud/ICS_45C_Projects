#ifndef INPUTS_HPP
#define INPUTS_HPP
/*
struct student_info
{
  int number_of_scores;
}student;
/**/
int get_artifact_number();
double* get_points(double points[], int size);
double* get_weight(double weight[], int size);
int get_student_number();
void get_student_name(std::string* info, int size);
int get_number_of_scores();
void get_raw_scores(double** score_list, int num_of_students, int num_of_scores);

#endif
