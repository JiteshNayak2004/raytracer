//color utility functions


#pragma once

#include <iostream>
#include <sstream>
#include "vec3.h"
using namespace std;

//alias defined in vec3 redefining
using color=vec3;

void write_color(ostream& out,const color& pixel_colour) {

    auto r= pixel_colour.x();
    auto g= pixel_colour.y();
    auto b= pixel_colour.z();

    int ir = int(255.999 * r);
    int ig = int(255.999 * g);
    int ib = int(255.999 * b);


    cout<<ir<<' '<<ig<<' '<<ib<<endl;

}

