/*
 * By giahuy2201
 * Date: Feb 28, 2018
 */

#include <iostream>
#include <cmath>

bool equilateral(int *coordinates);
std::string isosceles(int *coordinates);
float distance(int *coordinates, int start, int end);

int main()
{
    int *triangle = new int[9]; // to store 3 3-dimension points for the triangle
    std::cout << "Enter 3 points for the triangle (A, B, C): ";
    for(int i=0; i < 9; i++) // read the coordinates one by one
    {
        std::cin >> triangle[i];
    }

    if(equilateral(triangle)) // if the trangle is equilateral
    {
        std::cout << "This is a equilateral triangle!\n";
    }
    else
    {
        if(isosceles(triangle) != "") // if the triangle is isosceles
        {
            std::cout << "The triangle is isosceles at " << isosceles(triangle) << "\n";
        }
    }


    return 0;
}

bool equilateral(int *coordinates)
{
    float ab = distance(coordinates,0,1); // calculate distance between points
    float bc = distance(coordinates,1,2);
    float ca = distance(coordinates,2,0);
    
    if(ab == bc && bc == ca) // if three sides are the same, it is equilateral
    {
        return true;
    }
    return false;
}

std::string isosceles(int *coordinates)
{
    float ab = distance(coordinates,0,1); // calculate distance between points
    float bc = distance(coordinates,1,2);
    float ca = distance(coordinates,2,0);
    
    if(ab == bc) // if three sides are the same, it is equilateral
    {
        return "B";
    }
    else
    {
        if(bc == ca)
        {
            return "C";
        }
        else
        {
            if(ca == ab)
            {
                return "A";
            }
        }
    }
    return "";
}

float distance(int *coordinates, int start, int end)
{
    int vct1 = coordinates[start*3] - coordinates[end*3]; // calculate 3 vector for 2 points
    int vct2 = coordinates[start*3+1] - coordinates[end*3+1];
    int vct3 = coordinates[start*3+2] - coordinates[end*3+2];
    float dis = sqrt(pow(vct1,2) + pow(vct1,2) + pow(vct1,2)); // use formulas to calculate the distance
    return dis;
}