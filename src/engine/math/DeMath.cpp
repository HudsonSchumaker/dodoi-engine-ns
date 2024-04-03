/**
* @file DeMath.cpp
* @author Hudson Schumaker
* @brief Implements the DeMath class.
* @version 1.0.0
* 
* Dodoi-Engine-NS is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "DeMath.h"

double rootD(double n) {
    double x = n / 2.0;
    for (short i = 0; i < 1000; i++) {
        double newX = x - (x * x - n) / (2.0 * x);
        if (fabs(newX - x) < 0.000001) {
            return newX;
        }
        x = newX;
    }
    return x;
}

float rootF(float n) {
    float x = n / 2.0f;
    for (short i = 0; i < 1000; i++) {
        float newX = x - (x * x - n) / (2.0f * x);
        if (fabs(newX - x) < 0.000001) {
            return newX;
        }
        x = newX;
    }
    return x;
}

float distanceBetweenPoints(float x1, float y1, float x2, float y2) {
    // using the euclidean distance formula
    return rootF((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

float normalizeAngle(float angle) {
    angle = remainder(angle, Defs::TWO_PI);
    if (angle < 0) {
        angle = Defs::TWO_PI + angle;
    }
    return angle;
}


float deg2Rad(float angle) {
    return angle * Defs::PI / 180.0f;
}

float rad2Deg(float angle) {
    return angle * 180.0f / Defs::PI;
}
