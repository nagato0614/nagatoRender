//
// Created by 長井亨 on 2019-08-10.
//

#include "hit_info.hpp"

namespace nagato {

const Object *HitInfo::GetObject() const {
    return object_;
}
Float HitInfo::GetDistance() const {
    return distance_;
}
const Vector3f &HitInfo::GetPoint() const {
    return point_;
}
const Vector3f &HitInfo::GetNormal() const {
    return normal_;
}
}