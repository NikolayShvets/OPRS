#include "tvector.h"
using namespace std;

TVector::TVector()
{
    v_length = 0;
    v_data = NULL;
}
TVector::TVector(int length)
{
    v_length = 0;
    v_data = NULL;
    resize(length);
}
void TVector::resize(int length)
{
    long double *new_data = new long double[length];
    if(v_data)
    {
        int min_length = (this->v_length < length) ? this->v_length : length;
        memcpy(new_data, this->v_data, sizeof(long double)*min_length);
        v_data = NULL;
    }
       this->v_data = new_data;
       v_length = length;
}
void TVector::v_show() const
{
    int counter = 0;
    if(v_data == NULL)
        cout<<"Vector is not inicialize!"<<endl;
    for (counter = 0; counter < v_length ; counter++ ){
        cout <<"  "<< v_data[counter] << "|";
    }
    cout<<endl;
}
void TVector::v_show(int n) const
{
    if (n > v_length)
        cout<<"В векторе меньше элементов, чем требуется вывести!"<<endl;
    for(int i = 0; i <= n - 1; i++)
    {
        cout<<v_data[i]<<"|";
    }
    cout<<endl;
}
TVector& TVector::operator = (const TVector& arg)
{
    if(v_length != arg.v_length)
    {
        if(v_data)
            v_data = NULL; //delete[]v_data; v_data = nullptr; // ~TVector();
        v_data = new long double(arg.v_length);
        v_length = arg.v_length;
    }

    memcpy(v_data,arg.v_data, sizeof(long double)*v_length);
    return *this;
}
TVector::~TVector()
{
    if(v_data)
        v_data = NULL; //delete[]v_data; v_data = nullptr;
    v_length = 0;
}
TVector TVector::operator *(long double arg) const
{
    TVector res;
    for(int i = 0; i < v_length; i++)
    {
        res[i] = v_data[i] * arg;
    }
    return res;
}
long double TVector::operator *(const TVector& arg) const
{
    assert(v_length == arg.v_length);
    long double res = 0;
    for(int i = 0; i < arg.v_length; i++)
    {
        res += v_data[i]*arg[i];
    }
    return res;
}
TVector TVector::operator ^ (const TVector& arg) const
{
    assert(v_length == arg.v_length);
    TVector res(3);
    res[0] = v_data[1]*arg[2] - arg[1]*v_data[2];
    res[1] = v_data[2]*arg[0] - arg[2]*v_data[0];
    res[2] = v_data[0]*arg[1] - arg[0]*v_data[1];
    return res;
}
long double TVector::vector_length(bool screen)
{
    long double res = 0;
    for(int i = 0 ; i < v_length; i++)
    {
        res+=v_data[i]*v_data[i];
    }
    if (screen)
        cout<<"vector's length = "<<sqrt(res)<<endl;
    return sqrt(res);
}
TVector& TVector::normalize()
{
    long double length = vector_length(false);
    for(int i = 0; i < v_length; i++)
    {
        v_data[i] /=length;
    }
    return *this;
}
