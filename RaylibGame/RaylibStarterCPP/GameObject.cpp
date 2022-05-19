#include "raylib.h"
#include "GameObject.h"
#include <cassert>


void GameObject::AddChild(GameObject child){
	assert(child.parent == nullptr);
	child.parent = this;
	childrenAddPending.push_back(child);
}
void GameObject::RemoveChild(GameObject child){
	if (child.parent == this)
	{
		childrenRemovePending.push_back(child);
		child.parent = nullptr;
	}
}
void GameObject::RemoveFromParent(){
	if (parent != nullptr) {
		parent->RemoveChild(*this);
	}
}
void GameObject::CopyTransformToLocal(Matrix3 t){
	localTransform.Set(t);
	UpdateTransform();
}
void GameObject::UpdateTransform(){
	if (parent != nullptr)
	{
		globalTransform = parent->globalTransform * localTransform;
	}
	else
		globalTransform = localTransform;
	for(GameObject child : children){
		child.UpdateTransform();
	}
}
void GameObject::SetPosition(float x, float y){
	localTransform.SetTranslation(x, y);
	UpdateTransform();
}
void GameObject::SetRotate(float radians){
	localTransform.SetRotateZ(radians);
	UpdateTransform();
}
void GameObject::Rotate(float radians){
	Matrix3 temp = localTransform.SetRotateZ(radians);
	localTransform = localTransform * temp;
}
void GameObject::Translate(Vector3 v){

}
void GameObject::TranslateLocal(Vector3 v){

}
void GameObject::DistanceTo(GameObject obj){

}
void GameObject::OnUpdate(float deltatime){

}
void GameObject::OnDraw(){

}
void GameObject::Update(float deltatime){

}
void GameObject::Draw(){

}