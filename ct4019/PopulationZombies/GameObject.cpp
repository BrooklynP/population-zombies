#include "GameObject.h"
#include "UGFW.h"
#include "UG_Defines.h"


GameObject::GameObject(const char* SpritePath ,float a_fStartingX, float a_fStartingY, float a_fHeight, float a_fWidth)
{
	iSprite = UG::CreateSprite(SpritePath, a_fWidth, a_fHeight, true);
	UG::SetSpritePosition(iSprite, a_fStartingX, a_fStartingY);
	vPosition = Vector2(a_fStartingX, a_fStartingY);
	cCollider = Collider(vPosition, a_fWidth, a_fHeight);
}


GameObject::~GameObject()
{
}

int GameObject::GetSprite() {
	return iSprite;
}
void GameObject::Draw() {
	UG::DrawSprite(iSprite);
}