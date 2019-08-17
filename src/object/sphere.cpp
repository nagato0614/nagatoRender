//
// Created by 長井亨 on 2019-08-10.
//

#include <optional>
#include "sphere.hpp"

namespace nagato {

std::optional<HitInfo> Sphere::Intersect(const Ray &ray) {
    const Float min = ray.tmin_;
    const Float max = ray.tmax_;

    const auto oc = ray.origin_ - point_;
    const Float b = 2.f * Dot(oc, ray.direction_);
    const Float c = Dot(oc, oc) - radius_ * radius_;
    const Float D = b * b - 4 * c;
    if (D <= 0)
        return std::nullopt;

    const Float t1 = (-b - std::sqrt(D)) / 2.f;
    if (min < t1 && t1 < max) {
        const auto hit_point = ray.origin_ + ray.direction_ * t1;
        const auto normal = Normalize(hit_point - point_) / radius_;
        return HitInfo(this, t1, hit_point, normal);
    }

    const Float t2 = (-b + std::sqrt(D)) / 2.f;
    if (min < t2 && t2 < max) {
        const auto hit_point = ray.origin_ + ray.direction_ * t2;
        const auto normal = Normalize(hit_point - point_) / radius_;
        return HitInfo(this, t2, hit_point, normal);
    }

    return std::nullopt;
}
Sphere::Sphere(const std::shared_ptr<Material> &material,
               const std::shared_ptr<Light> &light,
               const Vector3f &point,
               Float radius) : Object(material, light), point_(point), radius_(radius) {}
}