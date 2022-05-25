#include "raylib.h"
#include "GameObject.h"
#include <cassert>

void GameObject::AddChild(GameObject* child){
	assert(child->parent == nullptr);
	child->parent = this;
	childrenAddPending.push_back(child);
}
void GameObject::RemoveChild(GameObject* child){
	if (child->parent == this)
	{
		childrenRemovePending.push_back(child);
		child->parent = nullptr;
	}
}
void GameObject::RemoveFromParent(){
	if (parent != nullptr) {
		parent->RemoveChild(this);
	}
}
void GameObject::CopyTransformToLocal(Matrix3 t){
	localTransform->Set(t);
	UpdateTransform();
}
MyVector GameObject::GlobalTransformAsVector() {
	return MyVector(globalTransform->m20, globalTransform->m21, globalTransform->m22);
}
void GameObject::UpdateTransform(){
	if (parent != nullptr){
		*globalTransform = *parent->globalTransform * *localTransform;
	}
	else
		*globalTransform = *localTransform;
	for(GameObject* child : children){
		child->UpdateTransform();
	}
}
void GameObject::SetPosition(float x, float y){
	localTransform->SetTranslation(x, y);
	UpdateTransform();
}
void GameObject::SetRotate(float radians){
	localTransform->SetRotateZ(radians);
	UpdateTransform();
}
void GameObject::Rotate(float radians){
	 Matrix3 temp = *localTransform;
	 temp.SetRotateZ(radians);
	*localTransform = *localTransform * temp;
	UpdateTransform();
}
void GameObject::Translate(MyVector v){
	localTransform->m20 += v.x; localTransform->m21 += v.y;
	UpdateTransform();
}
void GameObject::TranslateLocal(MyVector v){
	localTransform->Translate(v);
	UpdateTransform();
}
MyVector GameObject::DistanceTo(GameObject obj){
	return obj.GlobalTransformAsVector() - this->GlobalTransformAsVector();
}
void GameObject::OnUpdate(float deltatime){
}
void GameObject::OnDraw(){
}
void GameObject::Update(float deltatime){
	for (GameObject* child : children) {
		child->Update(deltatime);
	}
	for (GameObject* child : childrenAddPending) {
		children.push_back(child);
		child->UpdateTransform();
	}
	childrenAddPending.clear();
	for (GameObject* chitorem : childrenRemovePending) {
		for (GameObject* child : children) {
			if (child == chitorem){
				auto it = std::find(children.begin(), children.end(), child);
				children.erase(it);
			}
		}
	}
	childrenRemovePending.clear();
	OnUpdate(deltatime);
}
void GameObject::Draw(){
	OnDraw();
	for (GameObject* child : children) {
		child->Draw();
	}
}