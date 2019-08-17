//
// Created by 長井亨 on 2019-08-10.
//

#include "scene.hpp"
#include <iostream>

namespace nagato {

Scene::Scene(std::unique_ptr<Intersector> &&intersector)
		: intersector_(std::move(intersector)) {}

void Scene::AddObject(Object *object) {
	if (!object)
		return;

	if (object->GetLight())
		lights_.push_back(object->GetLight());

	objects_.emplace_back(object);
}

void Scene::AddLight(Light *light) {
	if (light)
		lights_.emplace_back(light);
}

std::optional<HitInfo> Scene::Intersect(const Ray &ray) {
	return intersector_->Intersect(ray);
}
void Scene::LoadObjectFile(const std::string &filename) {
	std::cerr << "not yet define" << std::endl;
}

void Scene::Build() {
	intersector_->Build(objects_);
}

void Scene::AddObject(std::shared_ptr<Object> &&object) {
	objects_.emplace_back(std::move(object));
}
const std::vector<std::shared_ptr<Object>> &Scene::GetObjects() const {
	return objects_;
}
}