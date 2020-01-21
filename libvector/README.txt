This library implements simple vectors manipulation in dimension 2, 3 and 4 (homogeneous coordinates), vectors are defined as custom structures, see libvector.h.
Every function have the same name, prefixed by "vX_function_name" where X stands for the dimension you're working in.
Every function returns a new instanced vector, allocated on the stack, no vector is changed.

Functions : 


t_vecX  vX_fromcoord(double x, double y(, double z, double w))
    returns a vector with the desired coordinates

t_vecX  vX_fromcoord(t_vecX ori, t_vecX dest)
    return the vector going from ori to dest. If O is ori and D is dest, creates the vector OD


t_vecX  vX_add(t_vecX vector1, t_vecX vector 2)
    returns the sum of the two vectors

t_vecX  vX_sub(t_vecX vector1, t_vecX vector 2)
    returns vector1 - vector2

t_vecX  vX_scalar(t_vecX vector1, double k)
    returns the scalar product of vector1 by k (k * vector1)

t_vecX  vX_dotpdt(t_vecX vector1, t_vecX vector 2)
    returns the dot product of vector1 and vector2 (vector1 . vector2)

t_vecX  vX_crosspdt(t_vecX vector1, t_vecX vector 2)
    returns the cross product of vector1 and vector2 (vector1 ^ vector2). Ony defined for dimension 3 and 4

t_vecX  vX_norm(t_vecX vector1)
    returns the magnitude of vector1

t_vecX  vX_norm(t_vecX vector1)
    returns the magnitude of vector1, squared


Future implementation (soon tm)

    - Rotation from an angle
    - Translation
    - Compound object manipulation
    - Homogenous coordinates (quaternions)