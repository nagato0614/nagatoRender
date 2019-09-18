//
// Created by 長井亨 on 2019-08-18.
//

#ifndef NAGATO_RENDER_SRC_BXDF_LAMBERT_HPP_
#define NAGATO_RENDER_SRC_BXDF_LAMBERT_HPP_

#include "nagato.hpp"
#include "bxdf.hpp"

namespace nagato {
class Lambert : public Bxdf {
 public:
  Lambert(const Vector3f &normal, const RGB &rho);
  RGB Fr(const Vector3f &wo, const Vector3f &wi) const override;
  Float Pdf(const Vector3f &wo, const Vector3f &wi) const override;
  Float Sample(const Vector2f &uv, const Vector3f &wo, Vector3f &wi, Float &pdf) const override;
 private:
  RGB rho_;
};
}

#endif //NAGATO_RENDER_SRC_BXDF_LAMBERT_HPP_
