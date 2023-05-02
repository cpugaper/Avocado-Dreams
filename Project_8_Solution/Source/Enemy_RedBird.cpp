#include "Enemy_RedBird.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_RedBird::Enemy_RedBird(int x, int y) : Enemy(x, y)
{
	flyAnim.PushBack({5,6,24,24});
	flyAnim.PushBack({38, 6, 24, 24});
	flyAnim.PushBack({71, 6, 24, 24});
	flyAnim.PushBack({104, 6, 24, 24});
	flyAnim.PushBack({137, 6, 24, 24});
	flyAnim.PushBack({170, 6, 24, 24});
	flyAnim.PushBack({203, 6, 24, 24});
	flyAnim.PushBack({236, 6, 24, 24});
	flyAnim.speed = 0.2f;

	currentAnim = &flyAnim;

	path.PushBack({ -1.0f, 0.0f }, 100);
	path.PushBack({ 1.0f, 0.0f }, 80);

	collider = App->collisions->AddCollider({0, 0, 24, 24}, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedBird::Update()
{
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
