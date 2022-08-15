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

	bool isInBox(float3 position, Transform parentTransform) {

	}

};

struct Entity {
	Transform T;

	AnimationController aniamtionController;
	PhysicsController physicsController;
	AiController aiController;

	EventTrigger *eventTriggers; //NOTE: Could have more than one event trigger 

	DialogController dialogController; 




};