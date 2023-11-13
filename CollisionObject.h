#pragma once

class CollisionObject {
public:
    virtual int GetPosX() const = 0;
    virtual int GetPosY() const = 0;
    virtual int GetRadius() const = 0;
    virtual void OnCollision() {}
};