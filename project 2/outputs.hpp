#ifndef OUTPUTS_HPP
#define OUTPUTS_HPP

int get_cutpoint_number();
void score_generator(int size, int num_students, std::string* id, double* student_grade);

void print_scores(std::string* student_info, double* total_scores, double* weighted_scores, double** raw_scores, int number_of_students, int number_of_scores, std::string* id, double* grade);









#endif
