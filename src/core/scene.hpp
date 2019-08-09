//
// Created by 長井亨 on 2019-08-10.
//

#ifndef NAGATO_RENDER_SRC_CORE_SCENE_HPP_
#define NAGATO_RENDER_SRC_CORE_SCENE_HPP_

#include "nagato.hpp"
#include "camera.hpp"
#include "object.hpp"
#include "ray.hpp"
#include "intersector.hpp"


namespace nagato {
class Scene {
 public:
  void AddObject(Object *object);
  void AddLight(Light *light);
  HitInfo Intersect(Ray ray);
  void LoadObjectFile(const std::string &filename);

 private:
  std::vector<std::shared_ptr<Light>> lights_;
  std::vector<std::shared_ptr<Object>> objects_;
  std::unique_ptr<Intersector> intersector_;
};
}
#endif //NAGATO_RENDER_SRC_CORE_SCENE_HPP_
