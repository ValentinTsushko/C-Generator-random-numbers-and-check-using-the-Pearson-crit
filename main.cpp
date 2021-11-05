#include "main_classes.cpp"

bool compare(double a, double b )
{
        return (a > b);
}

int main()
{
        setlocale(LC_ALL, "Russian");
        Var app;
        short n;
        cout << "Введите кол-во случайных чисел:  ";
        cin >> n;

        double x_0 = app.first_number();
        double rand_numb[n];

        for(int i = 0; i < n; i++)
        {
                //cout << "x_0 = " << x_0 << endl << endl;

                int lambda = 8 * app.t() - 3;

                double M = fmod((lambda * x_0),  m);

                if(M < 0){
                         M *= (-1);
                }

                //cout << "M = " << M << endl << endl;

              //double x_1 = round((M / m) * 10) / 10; // округление до первого
                double x_1 = M / m;
                //cout << "x_1 = " << x_1 << endl << endl;
                x_0 = x_1;
                rand_numb[i] = x_1;
        }
        for(int i = 0; i < n; i++)
        {
                cout << endl << rand_numb[i];
        }

        sort(rand_numb, rand_numb + n, compare);

/*
        cout << endl << endl << endl;
        for(int i = 0; i < n; i++)
        {
                cout << endl << rand_numb[i];
        }
*/
        Pirson p;
        cout << endl << "По критерию Пирсона эти числа: ";
        p.Run(rand_numb) ? cout << "Равномерно распределены!" << endl : cout << "Неравномерно распределены" << endl;

        //p.Run(rand_numb);

        return 0;
}
