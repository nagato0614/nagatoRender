//
// Created by 長井亨 on 2019-08-10.
//

#include "render_base.hpp"

namespace nagato {
RenderBase::RenderBase(std::unique_ptr<Camera> &&camera,
                       std::unique_ptr<Scene> &&scene,
                       std::unique_ptr<Film> &&film,
                       std::unique_ptr<Integrator> &&integrator)
    : camera_(std::move(camera)),
      scene_(std::move(scene)),
      film_(std::move(film)),
      integrator_(std::move(integrator)) {

}
const std::unique_ptr<Camera> &RenderBase::GetCamera() const {
    return camera_;
}
const std::unique_ptr<Scene> &RenderBase::GetScene() const {
    return scene_;
}
const std::unique_ptr<Film> &RenderBase::GetFilm() const {
    return film_;
}
const std::unique_ptr<Integrator> &RenderBase::GetIntegrator() const {
    return integrator_;
}

}