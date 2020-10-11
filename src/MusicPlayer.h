#pragma once
#include <Urho3D/Urho3DAll.h>

using namespace Urho3D;

class MusicPlayer : public LogicComponent
{
	URHO3D_OBJECT(MusicPlayer, LogicComponent)
public:
	static void RegisterObject(Context* context);

	virtual void Start();
};