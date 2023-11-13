#pragma once
#include <string>

class IScene {
public:
    virtual ~IScene() = default;

    virtual void OnInitialize() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnDraw() = 0;

    virtual std::string GetName() const = 0;
};