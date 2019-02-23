#ifndef TVECTOR_H
#define TVECTOR_H
#include <iostream>
#include <cassert>
#include <cstring>
#include <math.h>
/* Класс, реализующий основные операции векторной алгебры:
 * сложение(вычитание) векторов,
 * произведение вектора на число, скалярное произведение векторов,
 * векторное произведение векторов, нормирование вектора
 * */
using namespace std;
class TVector
{
private:
    int v_length;
    long double* v_data;
public:
  TVector();
  TVector(int length);
  TVector(const TVector& arg);
  virtual ~TVector();
  int size() {return v_length;}
  void resize(int length);
  TVector& operator = (const TVector& arg);
  long double& operator [] (int i)const {return v_data[i];}
  long double operator * (const TVector& arg)const;
  TVector operator * (long double arg)const;
  TVector operator ^ (const TVector& arg)const;
  TVector operator + (const TVector& arg)const;
  TVector operator - (const TVector& arg)const;
  TVector& normalize();
  long double vector_length(bool screen);
  void v_show() const;
  void v_show(int n) const;
};

#endif // TVECTOR_H
