#include "ExampleCube.h"
ExampleCube::ExampleCube(Context* context) : LogicComponent(context)
{
	// Only the physics update event is needed: unsubscribe from the rest for optimization
	SetUpdateEventMask(USE_FIXEDUPDATE);
}
void ExampleCube::RegisterObject(Context* context)
{
	context->RegisterFactory<ExampleCube>();
}
void ExampleCube::ApplyAttributes()
{
	// This function is called on each Serializable after the whole scene has been loaded. Reacquire wheel nodes from ID's
	// as well as all required physics components
	Scene* scene = GetScene();
}
//Handle physics update
void ExampleCube::Update(float timeStep)
{
	startFloat += startFloat + 5;
	exampleCube_->SetRotation(Quaternion(0, startFloat, 0));
}
void ExampleCube::Init()
{
	// This function is called only from the main program when initially creating the vehicle, not on scene load
	auto* cache = GetSubsystem<ResourceCache>();

	auto* hullObject = node_->CreateComponent<StaticModel>();
	auto* hullShape = node_->CreateComponent<CollisionShape>();

	node_->SetScale(Vector3(3, 3, 3));
	hullObject->SetModel(cache->GetResource<Model>("Models/Box.mdl"));
	hullObject->SetMaterial(cache->GetResource<Material>("Materials/Mushroom.xml"));
	hullObject->SetCastShadows(true);
	hullShape->SetBox(Vector3::ONE);
}
