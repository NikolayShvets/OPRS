#include "tvector.h"
#include "tmatrix.h"

using namespace std;

int main()
{
    //просто последний тест с методом Гаусса, тест-прогу не делал
    TMatrix M(3,3);
    TMatrix N(2,8);
    M.fillMatrix('M');
    N = M;
    N = !N;
    N.m_show();
    N = !N;
    N.m_show();
    cout<<N.det()<<endl;
}
