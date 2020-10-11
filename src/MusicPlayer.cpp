#include "MusicPlayer.h"

using namespace Urho3D;

void MusicPlayer::Start()
{
	ResourceCache* cache = GetSubsystem<ResourceCache>();
	Sound* music = cache->GetResource<Sound>("musaa.wav");
	SoundSource* source = GetScene()->CreateComponent<SoundSource>();
	
	if (music)
	{
		music->SetLooped(true);
		source->Play(music);
	}
}
