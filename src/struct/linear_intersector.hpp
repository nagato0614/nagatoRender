//
// Created by nagato0614 on 2019-08-15.
//

#ifndef NAGATO_RENDER_SRC_STRUCT_LINEAR_INTERSECTOR_HPP_
#define NAGATO_RENDER_SRC_STRUCT_LINEAR_INTERSECTOR_HPP_

#include "nagato.hpp"
#include "intersector.hpp"

namespace nagato {
class LinearIntersector : public Intersector {
 public:
	LinearIntersector();
	std::optional<HitInfo> Intersect(const Ray &ray) override;
	void Build(const std::vector<std::shared_ptr<Object>> &objects) override;
 private:
	std::vector<std::shared_ptr<Object>> objects_;
};
}
#endif //NAGATO_RENDER_SRC_STRUCT_LINEAR_INTERSECTOR_HPP_
