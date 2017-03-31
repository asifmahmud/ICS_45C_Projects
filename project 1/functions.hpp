#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
using namespace std;
string get_s_loc();
string get_t_loc();
void s_string_parser();
string target_lat(string a);
string target_lon(string a);
string target_loc(string a);
string get_t_num();
double to_rad(double val);
int d_calc(int t_num);
double d_converter(string value);
double calc(double starting_lat, double ending_lat, double starting_lon, double ending_lon);
extern string starting_lat;
extern string starting_lon;
extern string starting_loc;
extern double closest_distance, farthest_distance;
extern string closest_lat, closest_lon, closest_loc, farthest_lat, farthest_lon, farthest_loc, first_lat, first_lon, first_loc;

extern double starting_dis;
void reference_distance();


#endif
