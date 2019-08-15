//
// Created by nagato0614 on 2019-08-15.
//

#include "linear_intersector.hpp"

namespace nagato {

std::optional<HitInfo> LinearIntersector::Intersect(const Ray &ray) {
	std::optional<HitInfo> hitinfo = std::nullopt;
	for (auto &object : objects_) {
		auto info = object->Intersect(ray);
		if (!info)
			continue;

		if (!hitinfo)
			hitinfo = info;

		if (info->GetDistance() < hitinfo->GetDistance())
			hitinfo = info;
	}
	return hitinfo;
}

void LinearIntersector::Build(const std::vector<std::shared_ptr<Object>>
															&objects) {
	objects_ = objects;
}

LinearIntersector::LinearIntersector() {}
}