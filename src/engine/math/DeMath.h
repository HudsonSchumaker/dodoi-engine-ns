#pragma once
#include "../Common.h"

class DeMath final {
public:
    static double rootD(double n) {
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

    static float rootF(float n) {
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

    static float degree2Rad(float angle) {
        return angle * Common::PI / 180.0f;
    }

    static float rad2Degree(float angle) {
        return angle * 180.0f / Common::PI;
    }
};
