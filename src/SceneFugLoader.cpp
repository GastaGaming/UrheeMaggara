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
void SceneFugLoader::Init(Scene* scene)
{
	// This function is called only from the main program when initially creating the vehicle, not on scene load
	auto* cache = GetSubsystem<ResourceCache>();
	SharedPtr<File> file = cache->GetFile("Models/MapE/MegaMappiV.xml");
	Scene* scene_ = scene;

	/*scene_->LoadXML(*file);
	if (scene_->LoadXML(*file))
	{
		URHO3D_LOGINFO("Ladattu");
	}
	int i = 0;
	Node* node;
	while (node = scene_->GetNode(i))
	{
		URHO3D_LOGINFO(node->GetName());
		i++;
	}*/
	//auto* scene_ = GetSubsystem<Scene>();
	auto* style_ = cache->GetResource<XMLFile>("Models/MapE/MegaMappiV.xml");
	XMLElement sceneElement = style_->GetRoot();
	XMLElement nodeElement = sceneElement.GetChild("node");
	URHO3D_LOGINFO(nodeElement.GetName());
	while (!nodeElement.IsNull())
	{
		nodeElement = nodeElement.GetNext("node");
		URHO3D_LOGINFO(nodeElement.GetAttribute("id"));
		URHO3D_LOGINFO(nodeElement.GetAttribute("name"));


		XMLElement compElem = nodeElement.GetChild("component");
		while (!compElem.IsNull())
		{
			String compType = compElem.GetAttribute("type");
			int compId = compElem.GetInt("id");
			URHO3D_LOGINFO(compType);
			if (compType == "StaticModel")
			{
				//URHO3D_LOGINFO(nodeElement.GetAttribute("name"));
			}
			compElem = compElem.GetNext("component");
		}

	}
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
