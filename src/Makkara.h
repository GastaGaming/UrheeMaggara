#pragma once
#include <Urho3D/Urho3DAll.h>
#include <string>
using namespace Urho3D;

class Makkara : public LogicComponent
{
	URHO3D_OBJECT(Makkara, LogicComponent)

public:
	/// Construct.
	explicit Makkara(Context* context);

	/// Perform post-load after deserialization. Acquire the components from the scene nodes.
	void ApplyAttributes() override;

	/// Handle physics world update. Called by LogicComponent base class.
	void FixedUpdate(float timeStep) override;

	void Update(float timeStep) override;

	/// Initialize the vehicle. Create rendering and physics components. Called by the application.
	void Init();

    /// Register object factory and attributes.
	static void RegisterObject(Context* context);

	SharedPtr<Node> makkara_;

private:

    void SubscribeToEvents();
    void HandleKeyDown(StringHash eventType, VariantMap& eventData);

    Input* input_;
    Vector2 direction_;
};
