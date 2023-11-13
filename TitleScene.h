#pragma once
#include "IScene.h"

class TitleScene :
    public IScene {
public:
    void OnInitialize() override;
    void OnUpdate() override;
    void OnDraw() override;

    std::string GetName() const override { return "TitleScene"; }

private:

};