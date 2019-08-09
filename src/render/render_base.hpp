//
// Created by 長井亨 on 2019-08-10.
//

#ifndef NAGATO_RENDER_SRC_RENDER_RENDER_BASE_HPP_
#define NAGATO_RENDER_SRC_RENDER_RENDER_BASE_HPP_

#include "nagato.hpp"

namespace nagato {
class RenderBase {
 public:
  RenderBase(std::unique_ptr<Camera> &&camera,
             std::unique_ptr<Scene> &&scene,
             std::unique_ptr<Film> &&film,
             std::unique_ptr<Integrator> &&integrator);

  virtual void Render() = 0;
  const std::unique_ptr<Camera> &GetCamera() const;
  const std::unique_ptr<Scene> &GetScene() const;
  const std::unique_ptr<Film> &GetFilm() const;
  const std::unique_ptr<Integrator> &GetIntegrator() const;
 protected:
  std::unique_ptr<Camera> camera_;
  std::unique_ptr<Scene> scene_;
  std::unique_ptr<Film> film_;
  std::unique_ptr<Integrator> integrator_;
};
}
#endif //NAGATO_RENDER_SRC_RENDER_RENDER_BASE_HPP_
