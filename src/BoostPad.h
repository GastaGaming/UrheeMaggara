#pragma once
#include <Urho3D/Urho3DAll.h>

using namespace Urho3D;

class BoostPad : public LogicComponent
{
	URHO3D_OBJECT(BoostPad, LogicComponent)
public:
	SharedPtr<Node> boostPad_;

	//Constructor
	explicit BoostPad(Context* context);

	static void RegisterObject(Context* context);

	void ApplyAttributes() override;

	void HandleNodeCollision(StringHash eventType, VariantMap& eventData);

	virtual void Start();
};