struct Transform {
	float3 position;
	float3 scale;
	Quaternion rotation;
};

enum EventCommand {
	EVENT_HURT_1,
	EVENT_HURT_2,
	EVENT_HURT_3,
};

struct HealthController {
	float health;

	bool isDead() {
		return (health <= 0);
	}
}

struct EventTrigger {
	Rect3 eventBox;
	EventCommand command;

	bool trigger;

	bool update(float3 position, Transform parentTransform) {

	}

};

struct Entity {
	string uuid;
	Transform T;

	AnimationController *aniamtionController;
	PhysicsController *physicsController;
	AiController *aiController;

	EventTrigger *eventTriggers; //NOTE: Could have more than one event trigger 

	DialogController *dialogController; 
};

//NOTE: There might be different regions of entities that don't neeed updateing so would want to make this a different sub system
struct EntityStore {
	//ZII - zero is initialised
	int entityCount;
	int maxEntityCount;
	Entity *entities;

	Entity *GetEntity(EntityStore store) {
		int id = newUuid();

		//NOTE: Lazily initialize the array 
		if(store->entityCount >= store->maxEntityCount) {
			assert(store->entityCount == store->maxEntityCount);
			store->maxEntityCount += 64;
			store->entities = platform_memory_resize(store->entities, store->maxEntityCount*sizeof(Entity));
		}

		Entity *result = store->entities[store->entityCount++];
		result->id = id;

		platform_memory_zero(result);

		return result; 
	}  

};

void updateEntities {
	for(int i = 0; 
}