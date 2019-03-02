#ifndef INTEGRATOR_H
#define INTEGRATOR_H
class Integrator {
protected:
    long double eps {1E-16};
public:
    Integrator() : eps(1E-16) {}
    inline void setEps(long double eps) { this->eps = eps; }
    inline long double getEps() { return this->eps; }
    virtual long double run(math_model * model) = 0;
};

class DormanPrinceIntegrator : public Integrator {
protected:
    static const long double c[7], a[7][6], b1[7], b2[7];
    TVector K[7];
public:
    DormanPrinceIntegrator();
    long double run(math_model *model);
};
#endif // INTEGRATOR_H
