//
// Created by 長井亨 on 2019-08-18.
//

#ifndef NAGATO_RENDER_SRC_BXDF_BXDF_HPP_
#define NAGATO_RENDER_SRC_BXDF_BXDF_HPP_

#include "nagato.hpp"
#include "hit_info.hpp"
#include "vector.hpp"
#include "rgb.hpp"

namespace nagato {
class HitInfo;

class Bxdf {
 public:
  explicit Bxdf(const Vector3f &normal) : normal_(normal) {
      w_ = Normalize(normal);
      Vector3f a;
      if (std::fabs(w_[0]) > 0.9)
          a = Vector3f(0, 1, 0);
      else
          a = Vector3f(1, 0, 0);
      v_ = Normalize(Cross(w_, a));
		u_ = Normalize(Cross(w_, v_));
  }

  virtual RGB Fr(const Vector3f &wo, const Vector3f &wi) const = 0;
  virtual Float Pdf(const Vector3f &wo, const Vector3f &wi) const = 0;
  virtual Float Sample(const Vector2f &uv,
                       const Vector3f &wo,
                       Vector3f &wi,
                       Float &pdf) const = 0;

  const Vector3f &normal() const {
      return normal_;
  }

  const Vector3f &u() const {
      return u_;
  }

  const Vector3f &v() const {
      return v_;
  }

  const Vector3f &w() const {
      return w_;
  }

	Vector3f WorldToLocal(const Vector3f &vector) const {
		return Vector3f(Dot(vector, u_), Dot(vector, v_), Dot(vector, w_));
  }

	Vector3f LocalToWorld(const Vector3f &vector) const {
		Vector3f a(u_[0], v_[0], w_[0]);
		Vector3f b(u_[1], v_[1], w_[1]);
		Vector3f c(u_[2], v_[2], w_[2]);
      return Vector3f(Dot(vector, a), Dot(vector, b), Dot(vector, c));
  }
 private:
  Vector3f normal_;
  Vector3f u_;
  Vector3f v_;
  Vector3f w_;
};
}

#endif //NAGATO_RENDER_SRC_BXDF_BXDF_HPP_
