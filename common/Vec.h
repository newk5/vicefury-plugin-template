#pragma once

struct Vec
{
    double X;
    double Y;
    double Z;
    
    Vec(double x, double y, double z)
        : X(x), Y(y), Z(z)
    {
    }

    Vec()
        : X(0), Y(0), Z(0)
    {
    }
};
