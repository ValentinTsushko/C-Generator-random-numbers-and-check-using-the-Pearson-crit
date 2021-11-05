#include "pirson.h"

double Pirson::sample(double * a)
{
        double x_b = 0.0;
        for(int i = 0; i <= sizeof(a) + 1; i++)
        {
                x_b += a[i];
        }
        return (x_b / 10);
}

double Pirson::dispersion(double * a, double x_b)
{
        double del = 0.0;
        for(int i = 0; i <= sizeof(a) + 1; i++)
        {
        //double tmp = (a[i] - x_b);
        del += (a[i] - x_b) * (a[i] - x_b);
        }
        del /= 10;
        del = sqrt(del);
        return del;
}

double Pirson::a(double x_b, double delta)
{
 double tmp;
 double kr3 = 1.73205;  // sqrt from 3
        tmp = kr3 * delta;
        tmp = x_b - tmp;
 return tmp;
double Pirson::b(double x_b, double delta)
{
double tmp;
double kr3 = 1.73205;
        tmp = kr3 * delta;
        tmp = x_b + tmp;
 return tmp;
}

double *  Pirson::P_i(double * a, double * P_i, double b_a)
{
int n = (sizeof(a) + 2);
        for(int i = 0; i < n; i++)
        {
                P_i[i] = (a[i] - a[i + 1]) / b_a;
        }

 return P_i;
}

double Pirson::ksi_observation(double * a, double * P_i)
{
double sum = 0.0;
int n = (sizeof(a) + 2);
double n_i[n];

        for(int i = 0; i < n; i++)
        {
                //cout << i+1 << "  " << P_i[i] << " * " << n  << " --> ";
                n_i[i] = P_i[i] * 10;
                //cout << " " << P_i[i] << endl;
                //cout << i+1 << "  " << a[i] << " - " << P_i[i]  << " --> ";
                P_i[i] = a[i] - n_i[i];
                //cout << "" << P_i[i] << endl;

                //cout << i+1 << "  " << P_i[i] << " * " << P_i[i]  << " --> ";
                P_i[i] *= P_i[i];
                //cout << P_i[i] << endl;

                //cout << i+1 << "  " << P_i[i] << " / " << n_i[i]  << " --> ";
                P_i[i] /= n_i[i];
                //cout << P_i[i] << endl;

                //cout << i+1 << "  " << sum << " + " << P_i[i]  << " --> ";
                sum += P_i[i];
                //cout << sum << endl;

                //sum += (a[i] - (P_i[i] * (n + 1) ) ) *  (a[i] - (P_i[i] * (n + 1) ) ) / (P_i[i] * (n + 1) );
        }
return sum;
}

bool Pirson::Run(double * a)
{
        //double a[] = {0.9276, 0.859, 0.85, 0.66, 0.65, 0.6, 0.5, 0.4638, 0.405, 0.147};
        int n = (sizeof(a) + 2);
        double P_i[n]; // probability of hitting x between x_i and x_i+1

        Pirson p;
        double x_b = p.sample(a),  // sample mean over empirical distribution
         delta = p.dispersion(a, x_b),  // dispersion
 a_ = p.a(x_b, delta), b_ = p.b(x_b, delta),
        answer = 0;

        double b_a = b_ - a_;
        //cout << endl << endl << endl << b_a;
        p.P_i(a, P_i, b_a);  // take probability of hitting x between x_i and x_i+1

        //cout << endl << endl << endl << endl << p.ksi_observation(a, P_i);

        //cout << endl << "x_b = " << x_b << endl << "Delta = " << delta << endl
        // << "a = " << a_ << endl << "b = " << b_;

        answer = p.ksi_observation(a, P_i);

        //cout << endl << endl << "I'm OK!" << endl << endl;
        cout << endl << answer << " < 18.307038" << endl;

        return (answer < 18.307038);
}
