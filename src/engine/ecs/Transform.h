#include "Component.h"
#include "../physics/Vec2.h"

class Transform final : public Component {
public:
    Vec2 position;
    Vec2 scale;
    double rotation;

    Transform() { 
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->rotation = 0.0;
    }

    Transform(float v) {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->position.x = v;
        this->position.y = v;
        this->rotation = 0.0;
    }

    Transform(float x, float y) {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->position.x = x;
        this->position.y = y;
        this->rotation = 0.0;
    }

    ~Transform() {}
};
