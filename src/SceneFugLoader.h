#pragma once
#include <Urho3D/Urho3DAll.h>
#include <string>
using namespace Urho3D;

class SceneFugLoader : public LogicComponent
{
	URHO3D_OBJECT(SceneFugLoader, LogicComponent)
public:
	int objLoaded_ = 0;
	/// Construct.
	explicit SceneFugLoader(Context* context);
	/// Register object factory and attributes.
	static void RegisterObject(Context* context);
	/// Perform post-load after deserialization. Acquire the components from the scene nodes.
	void ApplyAttributes() override;
	/// Handle physics world update. Called by LogicComponent base class.
	//void FixedUpdate(float timeStep) override;
	void Update(float timeStep) override;
	/// Initialize the vehicle. Create rendering and physics components. Called by the application.
	virtual void Init(Scene* scene);

	void ImportScene(std::string path, Context* context);
};
