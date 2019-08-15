//
// Created by 長井亨 on 2019-08-10.
//

#ifndef NAGATO_RENDER_SRC_STRUCT_INTERSECTOR_HPP_
#define NAGATO_RENDER_SRC_STRUCT_INTERSECTOR_HPP_

#include "nagato.hpp"
#include "hit_info.hpp"
#include "ray.hpp"

namespace nagato {
class Intersector {
 public:
	virtual std::optional<HitInfo> Intersect(const Ray &ray) = 0;
	virtual void Build(const std::vector<std::shared_ptr<Object>> &objects) = 0;
 private:
};
}

#endif //NAGATO_RENDER_SRC_STRUCT_INTERSECTOR_HPP_
