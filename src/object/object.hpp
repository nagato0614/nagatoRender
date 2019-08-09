//
// Created by 長井亨 on 2019-08-10.
//

#ifndef NAGATO_RENDER_SRC_OBJECT_OBJECT_HPP_
#define NAGATO_RENDER_SRC_OBJECT_OBJECT_HPP_

#include <vector>
#include "nagato.hpp"
#include "hit_info.hpp"
#include "material.hpp"
#include "light.hpp"

namespace nagato {
class Object {
 public:
  virtual HitInfo Intersect() = 0;
  const std::shared_ptr<Material> &GetMaterial() const;
  const std::shared_ptr<Light> &GetLight() const;
 protected:
  std::shared_ptr<Material> material_;
  std::shared_ptr<Light> light_;
};
}
#endif //NAGATO_RENDER_SRC_OBJECT_OBJECT_HPP_
