//
// Created by nagato0614 on 2019-07-19.
//

#ifndef NAGATO_RENDER_SRC_CORE_NAGATO_HPP_
#define NAGATO_RENDER_SRC_CORE_NAGATO_HPP_

#include <cstdlib>
#include <nagatolib.hpp>
#include <matrix.hpp>

namespace nagato {

// -----------------------------------------------------------------------------
// Type Declaration
using Float = float;
using Size = std::size_t;

using Vector2f = Vector<Float, 2>;
using Vector3f = Vector<Float, 3>;
using Vector4f = Vector<Float, 4>;
using Vector2i = Vector<int, 2>;
using Vector3i = Vector<int, 3>;
using Vector4i = Vector<int, 4>;

using Matrix3f = Matrix<Float, 3, 3>;
using Matrix4f = Matrix<Float, 4, 4>;

// -----------------------------------------------------------------------------
// Functions


}

#endif //NAGATO_RENDER_SRC_CORE_NAGATO_HPP_
