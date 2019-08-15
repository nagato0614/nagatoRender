//
// Created by 長井亨 on 2019-08-10.
//

#include <optional>
#include "sphere.hpp"

namespace nagato {

std::optional<HitInfo> Sphere::Intersect(const Ray &ray) {
    const Float min = ray.tmin_;
    const Float max = ray.tmax_;

    const auto op = point_ - ray.origin_;
    const Float b = Dot(op, ray.direction_);
    const Float det = b * b - Dot(op, op) + radius_ * radius_;

	if (det < 0.0) {
        return  std::nullopt;
    }

	const Float t1 = b - std::sqrt(det);
    if (min <= t1 && t1 < max) {
        Vector3f point = ray.origin_ + ray.direction_ * t1;
			Vector3f normal = Normalize((point - point_) / radius_);
        return std::make_optional<HitInfo>(this, t1, point, normal);
    }

	const Float t2 = b + std::sqrt(det);
    if (min <= t2 && t2 < max) {
        Vector3f point = ray.origin_ + ray.direction_ * t2;
			Vector3f normal = Normalize((point - point_) / radius_);
        return std::make_optional<HitInfo>(this, t2, point, normal);
    }
    return std::nullopt;
}
Sphere::Sphere(const std::shared_ptr<Material> &material,
               const std::shared_ptr<Light> &light,
               const Vector3f &point,
               Float radius) : Object(material, light), point_(point), radius_(radius) {}
}