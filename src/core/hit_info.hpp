//
// Created by 長井亨 on 2019-08-10.
//

#ifndef NAGATO_RENDER_SRC_CORE_HIT_INFO_HPP_
#define NAGATO_RENDER_SRC_CORE_HIT_INFO_HPP_

#include "nagato.hpp"
#include "object.hpp"

namespace nagato {
class Object;
class HitInfo {
 public:
  HitInfo() {};
  HitInfo(Object *object, Float distance, const Vector3f &point, const Vector3f &normal)
      : object_(object), distance_(distance), point_(point), normal_(normal) {}
 public:
  const Object *GetObject() const;
  Float GetDistance() const;
  const Vector3f &GetPoint() const;
  const Vector3f &GetNormal() const;
 private:
  Object *object_;
  Float distance_;
  Vector3f point_;
  Vector3f normal_;
};
}

#endif //NAGATO_RENDER_SRC_CORE_HIT_INFO_HPP_
