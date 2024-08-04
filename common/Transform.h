#pragma once

struct Transform
{
    Vec Position;
    Rotation Rotation;

    Transform(const Vec& position, const ::Rotation& rotation)
        : Position(position),
          Rotation(rotation)
    {
    }

    Transform()
        : Position(Vec()),
          Rotation(::Rotation())
    {
    }
};
