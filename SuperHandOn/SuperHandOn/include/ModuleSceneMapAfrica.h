#ifndef __ModuleSceneMapAfrica_H__
#define __ModuleSceneMapAfrica_H__

#include "Animation.h"
#include "ModuleSceneTrack.h"
using namespace std;


class ModuleSceneMapAfrica : public ModuleSceneTrack
{

public:
	ModuleSceneMapAfrica(bool active = true);
	bool Start();
	~ModuleSceneMapAfrica();

};

#endif // __ModuleSceneMapAfrica_H__