#include "Physics.h"
#include "Components.h"

Vec2 Physics::GetOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b)
{
	if (!a->hasComponent<CBoundingBox>() || !b->hasComponent<CBoundingBox>())
	{
		return Vec2();
	}

	Vec2 dist = (a->getComponent<CTransform>().pos - b->getComponent<CTransform>().pos).abs();

	Vec2 boxSize = a->getComponent<CBoundingBox>().halfSize + b->getComponent<CBoundingBox>().halfSize;

	return Vec2(boxSize.x - dist.x, boxSize.y - dist.y);
}

Vec2 Physics::GetPreviousOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b)
{
	if (!a->hasComponent<CBoundingBox>() || !b->hasComponent<CBoundingBox>())
	{
		return Vec2();
	}

	Vec2 dist = (a->getComponent<CTransform>().prevPos - b->getComponent<CTransform>().prevPos).abs();

	Vec2 boxSize = a->getComponent<CBoundingBox>().halfSize + b->getComponent<CBoundingBox>().halfSize;

	return Vec2(boxSize.x - dist.x, boxSize.y - dist.y);
}