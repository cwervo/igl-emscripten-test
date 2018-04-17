#include <igl/cotmatrix.h>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <iostream>

#include <emscripten/bind.h>
#include <emscripten/val.h>

// From: https://kripken.github.io/emscripten-site/docs/porting/connecting_cpp_and_javascript/embind.html#a-quick-example

using namespace emscripten;

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

Eigen::MatrixXd get_a_matrix() {
    Eigen::MatrixXd V(4,2);
    V<<0,0,
        1,0,
        1,1,
        0,1;
    return V;
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("lerp", &lerp);
    function("get_a_matrix", &get_a_matrix);
}

int main()
{
    // val x = val::global("console.log");
    // x("beep");
  Eigen::MatrixXd V(4,2);
  V<<0,0,
     1,0,
     1,1,
     0,1;

  Eigen::MatrixXi F(2,3);
  F<<0,1,2,
     0,2,3;
  Eigen::SparseMatrix<double> L;
  igl::cotmatrix(V,F,L);
  std::cout<<"Hello, mesh: "<< std::endl << L*V << std::endl;
  return 0;
}

