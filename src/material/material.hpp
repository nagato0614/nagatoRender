//
// Created by 長井亨 on 2019-08-10.
//

#ifndef NAGATO_RENDER_SRC_MATERIAL_MATERIAL_HPP_
#define NAGATO_RENDER_SRC_MATERIAL_MATERIAL_HPP_

#include "nagato.hpp"
#include "vector.hpp"

namespace nagato {
class Material {
 public:
  virtual Float Fr(const Vector3f &wo, const Vector3f &wi) const = 0;
  virtual Float Pdf(const Vector3f &wo, const Vector3f &wi) const = 0;
  virtual Float Sample(const Vector3f &wo, Vector3f &wi, Float &pdf) const = 0;
};
}
#endif //NAGATO_RENDER_SRC_MATERIAL_MATERIAL_HPP_
