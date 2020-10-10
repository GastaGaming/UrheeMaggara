#pragma once
#include <Urho3D/Urho3DAll.h>
#include <string>
using namespace Urho3D;

class ExampleCube : public LogicComponent
{
	URHO3D_OBJECT(ExampleCube, LogicComponent)
public:
	SharedPtr<Node> exampleCube_;
	float startFloat = 0;
	/// Construct.
	explicit ExampleCube(Context* context);
	/// Register object factory and attributes.
	static void RegisterObject(Context* context);
	/// Perform post-load after deserialization. Acquire the components from the scene nodes.
	void ApplyAttributes() override;
	/// Handle physics world update. Called by LogicComponent base class.
	//void FixedUpdate(float timeStep) override;
	void Update(float timeStep) override;
	/// Initialize the vehicle. Create rendering and physics components. Called by the application.
	void Init();
};
