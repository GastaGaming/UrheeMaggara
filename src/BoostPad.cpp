#include "BoostPad.h"

void BoostPad::RegisterObject(Context* context)
{
	context->RegisterFactory<BoostPad>();
}

void BoostPad::ApplyAttributes()
{
}

void BoostPad::HandleNodeCollision(StringHash eventType, VariantMap& eventData)
{
	using namespace NodeCollisionStart;

	Node* other = static_cast<Node*>(eventData[P_OTHERNODE].GetPtr());
	//TODO: Call makkara boost function
}

void BoostPad::Start()
{
	SubscribeToEvent(E_NODECOLLISIONSTART, URHO3D_HANDLER(BoostPad, HandleNodeCollision));
}
