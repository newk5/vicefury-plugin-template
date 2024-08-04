#pragma once

struct VecWithAngle
{
    double X;
    double Y;
    double Z;
    double YawAngle;
    
    VecWithAngle(double x, double y, double z, double yawAngle)
        : X(x), Y(y), Z(z), YawAngle(yawAngle)
    {
    }

    VecWithAngle()
        : X(0), Y(0), Z(0), YawAngle(0)
    {
    }
};
