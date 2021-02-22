#include <iostream>

#include <projectsg/physics/vectors.ipp>

int main()
{
    std::cout << "Vectors module unit test." << std::endl;

    std::cout << "Vector 1 : (12, 5)" << std::endl;
    std::cout << "Vector 2 : (30, 6)" << std::endl;

    Vector2 vector1(12.0f, 5.0f);

    Vector2 vector2(30.0f, 6.0f);

    std::cout << "Vector 1 Magnitude : " << vector1.magnitude() << std::endl;
    std::cout << "Vector 2 Magnitude : " << vector2.magnitude() << std::endl;

    std::cout << "Vector 1_EQU : (12, 5)" << std::endl;

    Vector2 vector1_equ(12.0f, 5.0f);

    std::cout << "Is Vector 1 equal to Vector 1_EQU ? : " << (vector1 == vector1_equ ? "True" : "False" ) << std::endl;

    return 0;
}
