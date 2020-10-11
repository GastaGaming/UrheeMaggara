#include "SceneFugLoader.h"
#include <Urho3D/ThirdParty/PugiXml/pugixml.hpp>
#include <iostream>
SceneFugLoader::SceneFugLoader(Context* context) : LogicComponent(context)
{
	// Only the physics update event is needed: unsubscribe from the rest for optimization
	SetUpdateEventMask(USE_FIXEDUPDATE);
}
void SceneFugLoader::RegisterObject(Context* context)
{
	context->RegisterFactory<SceneFugLoader>();
}
void SceneFugLoader::ApplyAttributes()
{
	// This function is called on each Serializable after the whole scene has been loaded. Reacquire wheel nodes from ID's
	// as well as all required physics components
	Scene* scene = GetScene();
}
//Handle physics update
void SceneFugLoader::Update(float timeStep)
{
	std::string str = "ExampleCube ";
	str.append(std::to_string(timeStep));
	String s(str.c_str(), str.size());
	URHO3D_LOGINFO(s);
	//exampleCube_
}
void SceneFugLoader::Init(Scene* scene, std::string fileName, Context* context)
{
	// This function is called only from the main program when initially creating the vehicle, not on scene load
	auto* cache = GetSubsystem<ResourceCache>();
	Scene* scene_ = scene;
    ImportScene(fileName, context);
}

void SceneFugLoader::ImportScene(std::string fileName, Context* context)
{
	if (fileName.empty())
	{
		URHO3D_LOGINFO("SceneFugLoader :: filename empty you dummy");
		return;
	}
	/*XMLFile source = XMLFile(context);
	*source->LoadFile(fileName.c_str());
	XMLElement sceneElem = source->GetRoot();
	XMLElement entityElem = sceneElem.GetChild("node");
	while (!entityElem.IsNull())
	{
		Urho3D::String s = entityElem.GetName();
		URHO3D_LOGINFO(s);
		entityElem = entityElem.GetNext("node");
	}*/
}
