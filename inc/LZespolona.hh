#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>

class LZespolona
{
  
  double rl;
  double im;

  public:

  void set_value_rl(double &arl);
  void set_value_im(double &irl);
  double get_value_rl();
  double get_value_im();
  
  LZespolona operator+ (LZespolona obj_2)const;
  LZespolona operator- (LZespolona obj_2)const;
  LZespolona operator* (double obj_2)const;
  LZespolona operator* (LZespolona obj_2)const;
  LZespolona operator/ (double obj_2)const;
  LZespolona operator/ (LZespolona obj_2)const;
  void operator= (double obj_2);
  bool operator== (LZespolona obj_2)const;
  bool operator!= (int obj_2)const;

  friend std::ostream &operator<< (std::ostream &output, const LZespolona &obj_2);
  friend std::istream& operator>> (std::istream &input, LZespolona &obj_2);

};

std::ostream& operator<< (std::ostream &output, const LZespolona &obj_2); 
std::istream& operator>> (std::istream &input, LZespolona &obj_2);

#endif