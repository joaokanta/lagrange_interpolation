// C program for implementation of Lagrange's Interpolation
// Adapted from C++ implementation on https://www.geeksforgeeks.org/lagranges-interpolation/

#include <stdio.h>

// To represent a data point corresponding to x and y = f(x)
struct point
{
    int x;
    double y;
};

double interpolate(struct point data[], int xi, int size)
{
    double result = 0; // Initialize result

    for (int i=0; i < size; i++)
    {
        // Compute individual terms
        double term = data[i].y;
        for (int j=0; j < size; j++)
        {
            if (j!=i)
                term = term * (xi - data[j].x) / (double)(data[i].x - data[j].x);
        }

        // Add current term to result
        result += term;
    }

    return result;
}

int main()
{
    // creating an array of Usain Bolt's international competition performances
    struct point f[] = {
            {2008, 9.69},
            {2009, 9.58},
            {2012, 9.63},
            {2013, 9.77},
            {2015, 9.79},
            {2016, 9.81},
            {2017, 9.95}
    };

    // Using the interpolate function to obtain a data point
    printf("Had Usain Bolt competed for the 100 meters in the 2011 olympics his time would be approximate to: %f", interpolate(f, 2011, 7));
    return 0;
}
