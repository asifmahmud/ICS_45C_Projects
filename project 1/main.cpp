#include <iostream>
#include <vector>
#include <functions.hpp>
using namespace std;
//Asif Mahmud 70556749


int main()
{
  s_string_parser();
  string t = get_t_num();
  reference_distance();
  int a = stoi(t);
  d_calc(a);

  cout << "Start Location: " << starting_lat << " " << starting_lon << " " << "(" << starting_loc << ")" << endl;
  cout << "Closest Location: " << closest_lat << " " << closest_lon << " " << "(" << closest_loc << ") " << "(" << closest_distance << " miles)" << endl;
  cout << "Farthest Location: " << farthest_lat << " " << farthest_lon << " " << "(" << farthest_loc << ") " << "(" << farthest_distance << " miles)" << endl;
  return 0;
 } 

