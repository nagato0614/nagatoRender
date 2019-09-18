//
// Created by 長井亨 on 2019-08-18.
//

#include "lambert.hpp"

namespace nagato {
Lambert::Lambert(const Vector3f &normal, const RGB &rho) : Bxdf(normal), rho_(rho) {}


RGB Lambert::Fr(const Vector3f &wo, const Vector3f &wi) const {
    return RGB(0);
}
Float Lambert::Pdf(const Vector3f &wo, const Vector3f &wi) const {
    return 0;
}
Float Lambert::Sample(const Vector2f &uv, const Vector3f &wo, Vector3f &wi, Float &pdf) const {
    return 0;
}
}