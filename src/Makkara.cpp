#include "Makkara.h"

Makkara::Makkara(Context* context) : LogicComponent(context)
{
    SetUpdateEventMask(USE_FIXEDUPDATE);
}

void Makkara::RegisterObject(Context* context)
{
    context->RegisterFactory<Makkara>();
}

void Makkara::ApplyAttributes()
{
    Scene* scene = GetScene();
}

void Makkara::Update(float timeStep)
{

}

void Makkara::FixedUpdate(float timeStep)
{

}

void Makkara::Init()
{
    ResourceCache* cache = GetSubsystem<ResourceCache>();
    direction_ = Vector2();
}

void Makkara::SubscribeToEvents()
{
    SubscribeToEvent(E_KEYDOWN, URHO3D_HANDLER(Makkara, HandleKeyDown));
    SubscribeToEvent(E_UPDATE, URHO3D_HANDLER(Makkara, Update));
}

void Makkara::HandleKeyDown(StringHash eventType, VariantMap& eventData)
{
    using namespace KeyDown;

    int key = eventData[P_KEY].GetInt();

    direction_.x_ =  1.0 * ((key & KEY_D) == KEY_D) +
                    -1.0 * ((key & KEY_A) == KEY_A);

    direction_.y_ =  1.0 * ((key & KEY_W) == KEY_W) +
                    -1.0 * ((key & KEY_S) == KEY_S);

}
