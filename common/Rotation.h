#pragma once

struct Rotation
{
    double Yaw;
    double Pitch;
    double Roll;

    Rotation() : Yaw(0),
                 Pitch(0),
                 Roll(0)
    {
    }

    Rotation(double yaw, double pitch, double roll)
        : Yaw(yaw),
          Pitch(pitch),
          Roll(roll)
    {
    }
};
