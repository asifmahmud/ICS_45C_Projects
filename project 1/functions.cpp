#include <iostream>
#include <cmath>
#include <sstream>
#include <tuple>
#include <vector>
#include"functions.hpp"

using namespace std;


string starting_lat;
string starting_lon;
string starting_loc;
double starting_dis;

string get_s_loc()
{
  string n;
  getline(cin, n);
  return n;
}

string get_t_loc()
{
  string a;
  getline(cin, a);
  return a;
}

void s_string_parser()
{
  string a = get_s_loc();
  istringstream stm(a);
  string word;
  vector<string> v;
  while (stm >> word)
    {
      v.push_back(word);
    }
  starting_lat = v[0];
  starting_lon = v[1];
  string c;
  for (unsigned i = 2; i < v.size(); ++i)
    {
      c = c + " " + v[i];
    }
  starting_loc = c;
}

string target_lat(string a)
{
  istringstream stm(a);
  string word;
  vector<string> v;
  while (stm >> word)
    {
      v.push_back(word);
    }
  return v[0];
}

string target_lon(string a)
{
  istringstream stm(a);
  string word;
  vector<string> v;
  while (stm >> word)
    {
      v.push_back(word);
    }
  return v[1];
}

string target_loc(string a)
{
  istringstream stm(a);
  string word;
  vector<string> v;
  while (stm >> word)
    {
      v.push_back(word);
    }
  string c;
  for (unsigned i = 2; i < v.size(); ++i)
    {
      c = c + " " + v[i];
    }
  return c;
}

string get_t_num()
{
  string a;
  getline(cin, a);
  return a;
}

double closest_distance, farthest_distance;
string closest_lat, closest_lon, closest_loc, farthest_lat, farthest_lon, farthest_loc, first_lat, first_lon, first_loc = "";



void reference_distance()
{
  string target;
  target = get_t_loc();
  string tar_lat = target_lat(target);
  string tar_lon = target_lon(target);
  string tar_loc = target_loc(target);
  double distance = calc(d_converter(starting_lat),
				d_converter(tar_lat),
				d_converter(starting_lon),
				d_converter(tar_lon));
  starting_dis = distance;
  first_lat = tar_lat;
  first_lon = tar_lon;
  first_loc = tar_loc;
}


int d_calc(int t_num)
{
  string t, t_lat, t_lon, t_loc;
  double distance_so_far;
  closest_distance = starting_dis;
  farthest_distance = starting_dis;
  for (unsigned i = 0; i < t_num - 1; i++)
    {
      distance_so_far = 0;
      t = get_t_loc();
      t_lat = target_lat(t);
      t_lon = target_lon(t);
      t_loc = target_loc(t);
      distance_so_far = calc(d_converter(starting_lat),
				    d_converter(t_lat),
				    d_converter(starting_lon),
				    d_converter(t_lon));

      if (distance_so_far < starting_dis && distance_so_far < closest_distance)
	{
	  closest_distance = distance_so_far; 
	  closest_lat = t_lat;
	  closest_lon = t_lon;
	  closest_loc = t_loc;
	  
	}
      else if (distance_so_far > starting_dis && distance_so_far > farthest_distance)
	{
	  farthest_distance = distance_so_far;
	  farthest_lat = t_lat;
	  farthest_lon = t_lon;
	  farthest_loc = t_loc;
	}
    }
    

  if (closest_lat == "")
    {
      closest_lat = first_lat;
      closest_lon = first_lon;
      closest_loc = first_loc;
    }

  else if (farthest_lat == "")
    {
      farthest_lat = first_lat;
      farthest_lon = first_lon;
      farthest_loc = first_loc;
    }
	
  return 0;
}


double calc(double start_lat, double end_lat, double start_lon,
		double end_lon)
{
  double dlat = to_rad( end_lat) - to_rad( start_lat);
  double dlon = to_rad(end_lon)  - to_rad( start_lon);
  double a = pow(sin(dlat/2), 2)+ cos(to_rad(start_lat)) * cos(to_rad(end_lat)) * pow(sin(dlon/2), 2);
  double c = 2 * atan2(sqrt(a), sqrt(1-a));
  double radius = 3959.9;
  double distance = radius * c;
  return distance;
}

double d_converter(string value)
{
  double val = stod(value);
  char a = value.back();
  if (a == 'W' || a == 'S')
    {
      return -val;
    }
  return val;
}


double to_rad(double val)
{
  double rad = val *((atan(1)*4)/180);
  return rad;
}



















