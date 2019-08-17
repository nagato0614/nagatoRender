//
// Created by nagato0614 on 2019-08-15.
//

#include "linear_intersector.hpp"

namespace nagato {

std::optional<HitInfo> LinearIntersector::Intersect(const Ray &ray) {
	std::optional<HitInfo> hitinfo = std::nullopt;
	Float max = std::numeric_limits<Float>::max();
	for (auto &object : objects_) {
		auto info = object->Intersect(ray);
		if (!info)
			continue;

		if (info->GetDistance() < max) {
			hitinfo = info;
            max = info->GetDistance();
		}
	}
	return hitinfo;
}

void LinearIntersector::Build(const std::vector<std::shared_ptr<Object>>
															&objects) {
	objects_ = objects;
}

LinearIntersector::LinearIntersector() {}
}