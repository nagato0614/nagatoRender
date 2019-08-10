//
// Created by 長井亨 on 2019-08-10.
//

#include "object.hpp"

namespace nagato {

const std::shared_ptr<Material> &Object::GetMaterial() const {
    return material_;
}
const std::shared_ptr<Light> &Object::GetLight() const {
    return light_;
}
Object::Object(const std::shared_ptr<Material> &material,
               const std::shared_ptr<Light> &light)
    : material_(material), light_(light) {}
}