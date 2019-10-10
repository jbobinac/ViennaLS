#ifndef LS_MESH_HPP
#define LS_MESH_HPP

#include <iostream>
#include <vector>

#include <hrleVectorType.hpp>

/// This class holds an explicit mesh, which is always given in 3 dimensions
/// If it describes a 2D mesh, the third dimension is set to 0
/// Only two types of elements, Triangles and Tetras, are supported
class lsMesh {
public:
  std::vector<hrleVectorType<double, 3>> nodes;
  std::vector<hrleVectorType<unsigned, 1>> vertices;
  std::vector<hrleVectorType<unsigned, 2>> lines;
  std::vector<hrleVectorType<unsigned, 3>> triangles;
  std::vector<hrleVectorType<unsigned, 4>> tetras;
  std::vector<unsigned> materials;
  std::vector<std::vector<double>> scalarData;
  std::vector<std::string> scalarDataLabels;
  std::vector<std::vector<hrleVectorType<double, 3>>> vectorData;
  std::vector<std::string> vectorDataLabels;

  std::vector<hrleVectorType<double, 3>> &getNodes() { return nodes; }

  std::vector<double> &getScalarData(int i) { return scalarData[i]; }

  std::vector<hrleVectorType<double, 3>> &getVectorData(int i) {
    return vectorData[i];
  }

  std::vector<unsigned> &getMaterials() { return materials; }

  template <int D, typename std::enable_if<D == 1, int>::type = 0>
  std::vector<hrleVectorType<unsigned, D>> &getElements() {
    return vertices;
  }

  template <int D, typename std::enable_if<D == 2, int>::type = 0>
  std::vector<hrleVectorType<unsigned, D>> &getElements() {
    return lines;
  }

  template <int D, typename std::enable_if<D == 3, int>::type = 0>
  std::vector<hrleVectorType<unsigned, D>> &getElements() {
    return triangles;
  }

  template <int D, typename std::enable_if<D == 4, int>::type = 0>
  std::vector<hrleVectorType<unsigned, D>> &getElements() {
    return tetras;
  }

  unsigned insertNextNode(hrleVectorType<double, 3> &node) {
    nodes.push_back(node);
    return nodes.size() - 1;
  }

  unsigned insertNextVertex(hrleVectorType<unsigned, 1> &vertex) {
    vertices.push_back(vertex);
    return vertices.size() - 1;
  }

  unsigned insertNextLine(hrleVectorType<unsigned, 2> &line) {
    lines.push_back(line);
    return lines.size() - 1;
  }

  unsigned insertNextTriangle(hrleVectorType<unsigned, 3> &triangle) {
    triangles.push_back(triangle);
    return triangles.size() - 1;
  }

  unsigned insertNextTetra(hrleVectorType<unsigned, 4> &tetra) {
    tetras.push_back(tetra);
    return tetras.size() - 1;
  }

  unsigned insertNextElement(hrleVectorType<unsigned, 1> &vertex) {
    vertices.push_back(vertex);
    return vertices.size() - 1;
  }

  unsigned insertNextElement(hrleVectorType<unsigned, 2> &line) {
    lines.push_back(line);
    return lines.size() - 1;
  }

  unsigned insertNextElement(hrleVectorType<unsigned, 3> &triangle) {
    triangles.push_back(triangle);
    return triangles.size() - 1;
  }

  unsigned insertNextElement(hrleVectorType<unsigned, 4> &tetra) {
    tetras.push_back(tetra);
    return tetras.size() - 1;
  }

  void insertNextScalarData(std::vector<double> &scalars,
                            std::string label = "Scalars") {
    scalarData.push_back(scalars);
    scalarDataLabels.push_back(label);
  }

  void insertNextVectorData(std::vector<hrleVectorType<double, 3>> &vectors,
                            std::string label = "Vectors") {
    vectorData.push_back(vectors);
    vectorDataLabels.push_back(label);
  }

  void clear() {
    nodes.clear();
    vertices.clear();
    lines.clear();
    triangles.clear();
    tetras.clear();
    materials.clear();
    scalarData.clear();
    scalarDataLabels.clear();
    vectorData.clear();
    vectorDataLabels.clear();
  }

  void print() {
    std::cout << "lsMesh:" << std::endl;
    std::cout << "Number of Nodes: " << nodes.size() << std::endl;
    std::cout << "Number of Vertices: " << vertices.size() << std::endl;
    std::cout << "Number of Lines: " << lines.size() << std::endl;
    std::cout << "Number of Triangles: " << triangles.size() << std::endl;
    std::cout << "Number of Tetrahedrons: " << tetras.size() << std::endl;
  }
};

#endif // LS_MESH_HPP