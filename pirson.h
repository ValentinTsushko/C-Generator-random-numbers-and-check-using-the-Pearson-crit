#include "main.h"

//class Pirson : public Main
class Pirson
{
public:
        //int sort(double *n);
        double sample(double * a);
        double dispersion(double * a, double x_b);
        double a(double x_b, double delta);
        double b(double x_b, double delta);
 // take probability of hitting x between x_i and x_i+1
        double * P_i(double * a, double * P_i, double b_a);  // b_a = b - a
        double ksi_observation(double * a, double * P_i);

        bool Run(double * a);
};
