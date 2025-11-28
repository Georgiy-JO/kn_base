#include <gtest/gtest.h>

#include "model/model3d/model3d.h" 

/**
 * Comments referencing this function (and the function it self) are left
 * in case more testing is required
  void PrintEdges( const inbound_model::Edges& array){
    for(size_t i=0; i<(*array).size();i++)
      std::cout<<i<<") "<<(*array)[i].begin<<' '<<(*array)[i].end<<std::endl;

  }
**/

TEST(Model_Model3D, Vertices_Basic) {
  using Vec3 = vectors::Vec3;
  using Vertices = inbound_model::Vertices;
  Vertices arr_vec_a;

  EXPECT_EQ(arr_vec_a.vertices.size(), 0);
  EXPECT_EQ((*arr_vec_a).size(), 0);
  EXPECT_EQ(arr_vec_a->size(), 0);

  for (double i = 0; i < 20; i++) {
    arr_vec_a.vertices.push_back(Vec3(i * 0.5, i * 0.5 + 50, i * 0.5 + 100));
    i++;
    (*arr_vec_a).push_back(Vec3(i * 0.5, i * 0.5 + 50, i * 0.5 + 100));
    i++;
    arr_vec_a->push_back(Vec3(i * 0.5, i * 0.5 + 50, i * 0.5 + 100));
  }
  EXPECT_EQ(arr_vec_a.vertices.size(), 21);

  for (double i = 0; i < 21; i++) {
    EXPECT_DOUBLE_EQ(arr_vec_a.vertices[i].x, i * 0.5);
    EXPECT_DOUBLE_EQ((*arr_vec_a)[i].y, i * 0.5 + 50);
    EXPECT_DOUBLE_EQ((*(arr_vec_a->begin() + i)).z, i * 0.5 + 100);
  }

  Vec3 vect_0{(*arr_vec_a)[5]};
  EXPECT_DOUBLE_EQ(vect_0.x, 2.5);
  EXPECT_DOUBLE_EQ(vect_0.y, 52.5);
  EXPECT_DOUBLE_EQ(vect_0.z, 102.5);
  vect_0++;
  EXPECT_DOUBLE_EQ(vect_0.x, 3.5);
  EXPECT_DOUBLE_EQ(vect_0.y, 53.5);
  EXPECT_DOUBLE_EQ(vect_0.z, 103.5);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].x, 2.5);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].y, 52.5);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].z, 102.5);

  Vec3& vect_1 = (*arr_vec_a)[5];
  EXPECT_DOUBLE_EQ(vect_1.x, 2.5);
  EXPECT_DOUBLE_EQ(vect_1.y, 52.5);
  EXPECT_DOUBLE_EQ(vect_1.z, 102.5);
  vect_1 += vect_0;
  EXPECT_DOUBLE_EQ(vect_1.x, 6);
  EXPECT_DOUBLE_EQ(vect_1.y, 106);
  EXPECT_DOUBLE_EQ(vect_1.z, 206);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].x, 6);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].y, 106);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].z, 206);
  (*arr_vec_a)[5] = Vec3(5, 50, 500);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].x, 5);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].y, 50);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].z, 500);
  (*arr_vec_a)[5]++;
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].x, 6);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].y, 51);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].z, 501);

  const Vec3& vec_2{(*arr_vec_a)[5]};
  EXPECT_DOUBLE_EQ(vec_2.x, 6);
  EXPECT_DOUBLE_EQ(vec_2.y, 51);
  EXPECT_DOUBLE_EQ(vec_2.z, 501);

  const Vec3* vec_3 = &(*arr_vec_a)[5];
  EXPECT_DOUBLE_EQ((*vec_3).x, 6);
  EXPECT_DOUBLE_EQ((*vec_3).y, 51);
  EXPECT_DOUBLE_EQ((*vec_3).z, 501);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].x, 6);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].y, 51);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].z, 501);

  Vec3* vec_4 = &(*arr_vec_a)[5];
  (*vec_4)++;
  EXPECT_DOUBLE_EQ((*vec_4).x, 7);
  EXPECT_DOUBLE_EQ((*vec_4).y, 52);
  EXPECT_DOUBLE_EQ((*vec_4).z, 502);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].x, 7);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].y, 52);
  EXPECT_DOUBLE_EQ((*arr_vec_a)[5].z, 502);
  vec_4++;
  EXPECT_EQ((*arr_vec_a)[6], *vec_4);

  const Vertices arr_vec_b;
  EXPECT_EQ(arr_vec_b->size(), 0);
}

TEST(Model_Model3D, Edge_Basic) {
  using Edge = inbound_model::Edge;

  Edge edge_1(0, 1);
  Edge edge_2(1, 2);
  Edge edge_3(2, 3);
  Edge edge_4(3, 0);

  EXPECT_EQ(edge_1.end, edge_2.begin);
  EXPECT_EQ(edge_2.end, edge_3.begin);
  EXPECT_EQ(edge_4.begin, 0);
  EXPECT_EQ(edge_4.end, 3);
  EXPECT_EQ(edge_3.end, edge_4.end);
  EXPECT_EQ(edge_4.begin, edge_1.begin);

  Edge edge_5 = edge_4;
  EXPECT_EQ(edge_5.begin, edge_4.begin);
  EXPECT_EQ(edge_5.end, edge_4.end);
}

TEST(Model_Model3D, Edge_Comperison) {
  using Edge = inbound_model::Edge;

  Edge edge_1(0, 1);
  Edge edge_2(0, 2);
  Edge edge_3(1, 1);
  Edge edge_4(1, 1);
  Edge edge_5(1, 5);
  Edge edge_6(1, 0);

  EXPECT_EQ(edge_1, edge_6);
  EXPECT_NE(edge_1, edge_2);
  EXPECT_NE(edge_2, edge_3);
  EXPECT_EQ(edge_3, edge_4);
  EXPECT_NE(edge_4, edge_5);
  EXPECT_NE(edge_6, edge_5);

  EXPECT_EQ(edge_1 == edge_1, true);
  EXPECT_EQ(edge_1 == edge_1, 1);
  EXPECT_EQ(edge_1 == edge_6, true);
  EXPECT_EQ(edge_1 == edge_6, 1);
  EXPECT_EQ(edge_1 == edge_2, false);
  EXPECT_EQ(edge_1 == edge_2, 0);
  EXPECT_EQ(edge_1 != edge_2, true);
  EXPECT_EQ(edge_1 != edge_2, 1);
  EXPECT_EQ(edge_1 < edge_2, true);
  EXPECT_EQ(edge_1 < edge_2, 1);
  EXPECT_EQ(edge_1 <= edge_2, true);
  EXPECT_EQ(edge_1 <= edge_2, 1);
  EXPECT_EQ(edge_1 <= edge_1, true);
  EXPECT_EQ(edge_1 <= edge_1, 1);
  EXPECT_EQ(edge_1 <= edge_6, true);
  EXPECT_EQ(edge_1 <= edge_6, 1);
  EXPECT_EQ(edge_1 >= edge_6, true);
  EXPECT_EQ(edge_1 >= edge_6, 1);
  EXPECT_EQ(edge_1 > edge_2, false);
  EXPECT_EQ(edge_1 > edge_2, 0);
  EXPECT_EQ(edge_1 >= edge_2, false);
  EXPECT_EQ(edge_1 >= edge_2, 0);
  EXPECT_EQ(edge_3 == edge_4, true);
  EXPECT_EQ(edge_4 == edge_3, 1);
  EXPECT_EQ(edge_3 == edge_4, true);
  EXPECT_EQ(edge_4 == edge_3, 1);
  EXPECT_EQ(edge_2 < edge_3, true);
  EXPECT_EQ(edge_1 <= edge_4, 1);
  EXPECT_EQ(edge_4 <= edge_5, true);
  EXPECT_EQ(edge_4 < edge_5, 1);
}

TEST(Model_Model3D, Edges_Basic) {
  using Edges = inbound_model::Edges;
  using Edge = inbound_model::Edge;

  Edges arr_edges;

  EXPECT_EQ(arr_edges.edges.size(), 0);
  EXPECT_EQ((*arr_edges).size(), 0);
  EXPECT_EQ(arr_edges->size(), 0);

  for (double i = 0; i < 20; i++) {
    arr_edges.edges.push_back(Edge(i, i + 1));
    i++;
    (*arr_edges).push_back(Edge(i, i + 1));
    i++;
    arr_edges->push_back(Edge(i, i + 1));
  }
  EXPECT_EQ(arr_edges->size(), 21);

  for (double i = 0; i < 21; i++) {
    EXPECT_EQ(arr_edges.edges[i].begin, i);
    EXPECT_EQ((*arr_edges)[i].end, i + 1);
    EXPECT_EQ((*(arr_edges->begin() + i)).begin, i);
  }

  Edge edge_0{(*arr_edges)[5]};
  EXPECT_EQ(edge_0.begin, 5);
  EXPECT_EQ(edge_0.end, 6);
  edge_0.begin++;
  edge_0.end++;
  EXPECT_EQ(edge_0.begin, 6);
  EXPECT_EQ(edge_0.end, 7);
  EXPECT_EQ((*arr_edges)[5].begin, 5);
  EXPECT_EQ((*arr_edges)[5].end, 6);

  Edge& edge_1 = (*arr_edges)[5];
  EXPECT_EQ(edge_1.begin, 5);
  EXPECT_EQ(edge_1.end, 6);
  edge_1.begin += edge_0.begin;
  edge_1.end += edge_0.end;
  EXPECT_EQ(edge_1.begin, 11);
  EXPECT_EQ(edge_1.end, 13);
  EXPECT_EQ((*arr_edges)[5].begin, 11);
  EXPECT_EQ((*arr_edges)[5].end, 13);
  (*arr_edges)[5] = Edge{50, 500};
  EXPECT_EQ((*arr_edges)[5].begin, 50);
  EXPECT_EQ((*arr_edges)[5].end, 500);
  (*arr_edges)[5].begin++;
  (*arr_edges)[5].end++;
  EXPECT_EQ((*arr_edges)[5].begin, 51);
  EXPECT_EQ((*arr_edges)[5].end, 501);

  const Edge& edge_2{(*arr_edges)[5]};
  EXPECT_EQ(edge_2.begin, 51);
  EXPECT_EQ(edge_2.end, 501);

  const Edge* edge_3 = &(*arr_edges)[5];
  EXPECT_EQ((*edge_3).begin, 51);
  EXPECT_EQ((*edge_3).end, 501);
  EXPECT_EQ((*arr_edges)[5].begin, 51);
  EXPECT_EQ((*arr_edges)[5].end, 501);

  Edge* edge_4 = &(*arr_edges)[5];
  (*edge_4).begin++;
  (*edge_4).end++;
  EXPECT_EQ((*edge_4).begin, 52);
  EXPECT_EQ((*edge_4).end, 502);
  EXPECT_EQ((*arr_edges)[5].begin, 52);
  EXPECT_EQ((*arr_edges)[5].end, 502);
  edge_4++;
  EXPECT_EQ((*arr_edges)[6], *edge_4);

  const Edges arr_edges_const;
  EXPECT_EQ(arr_edges_const->size(), 0);
}

TEST(Model_Model3D, AxisBounds_Basic) {
  using AxisBounds = inbound_model::AxisBounds;
  AxisBounds bounds;

  EXPECT_DOUBLE_EQ(bounds.max, 0);
  EXPECT_DOUBLE_EQ(bounds.min, 0);

  bounds += 5;
  EXPECT_DOUBLE_EQ(bounds.max, 5);
  EXPECT_DOUBLE_EQ(bounds.min, 5);

  bounds += -5.55;
  EXPECT_DOUBLE_EQ(bounds.max, -0.55);
  EXPECT_DOUBLE_EQ(bounds.min, -0.55);

  bounds *= 10;
  EXPECT_DOUBLE_EQ(bounds.max, -5.5);
  EXPECT_DOUBLE_EQ(bounds.min, -5.5);

  bounds *= 0;
  EXPECT_DOUBLE_EQ(bounds.max, 0);
  EXPECT_DOUBLE_EQ(bounds.min, 0);

  bounds.max = 1;
  bounds.min = -1;
  EXPECT_DOUBLE_EQ(bounds.max, 1);
  EXPECT_DOUBLE_EQ(bounds.min, -1);

  bounds *= 0.25;
  EXPECT_DOUBLE_EQ(bounds.max, 0.25);
  EXPECT_DOUBLE_EQ(bounds.min, -0.25);
}

TEST(Model_Model3D, AxisBounds3D_Basic) {
  using AxisBounds3D = inbound_model::AxisBounds3D;

  AxisBounds3D bounds_3D;

  EXPECT_DOUBLE_EQ(bounds_3D.x.max, 0);
  EXPECT_DOUBLE_EQ(bounds_3D.x.min, 0);
  EXPECT_DOUBLE_EQ(bounds_3D.y.max, 0);
  EXPECT_DOUBLE_EQ(bounds_3D.y.min, 0);
  EXPECT_DOUBLE_EQ(bounds_3D.z.max, 0);
  EXPECT_DOUBLE_EQ(bounds_3D.z.min, 0);

  bounds_3D.x.max = 5.55;
  bounds_3D.x.min = -55;
  bounds_3D.y.max = 5000.5;
  bounds_3D.y.min = -55.555;
  bounds_3D.z.max = 1005;
  bounds_3D.z.min = -0.5;

  EXPECT_DOUBLE_EQ(bounds_3D.x.max, 5.55);
  EXPECT_DOUBLE_EQ(bounds_3D.x.min, -55);
  EXPECT_DOUBLE_EQ(bounds_3D.y.max, 5000.5);
  EXPECT_DOUBLE_EQ(bounds_3D.y.min, -55.555);
  EXPECT_DOUBLE_EQ(bounds_3D.z.max, 1005);
  EXPECT_DOUBLE_EQ(bounds_3D.z.min, -0.5);

  bounds_3D.clear();
  EXPECT_DOUBLE_EQ(bounds_3D.x.max, 0);
  EXPECT_DOUBLE_EQ(bounds_3D.x.min, 0);
  EXPECT_DOUBLE_EQ(bounds_3D.y.max, 0);
  EXPECT_DOUBLE_EQ(bounds_3D.y.min, 0);
  EXPECT_DOUBLE_EQ(bounds_3D.z.max, 0);
  EXPECT_DOUBLE_EQ(bounds_3D.z.min, 0);
}

TEST(Model_Model3D, Edges_Sort_1) {
  using Edges = inbound_model::Edges;
  using Edge = inbound_model::Edge;

  Edges arr_edges_1;

  (*arr_edges_1).push_back(Edge(0, 0));
  (*arr_edges_1).push_back(Edge(0, 1));
  (*arr_edges_1).push_back(Edge(2, 3));
  (*arr_edges_1).push_back(Edge(4, 3));
  (*arr_edges_1).push_back(Edge(1, 2));
  (*arr_edges_1).push_back(Edge(5, 0));
  (*arr_edges_1).push_back(Edge(5, 4));

  // PrintEdges(arr_edges_1);
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[1], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[2], Edge(2, 3));
  EXPECT_EQ((*arr_edges_1)[3], Edge(3, 4));
  EXPECT_EQ((*arr_edges_1)[4], Edge(1, 2));
  EXPECT_EQ((*arr_edges_1)[5], Edge(0, 5));
  EXPECT_EQ((*arr_edges_1)[6], Edge(4, 5));
  arr_edges_1.Sort();
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[1], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[2], Edge(0, 5));
  EXPECT_EQ((*arr_edges_1)[3], Edge(1, 2));
  EXPECT_EQ((*arr_edges_1)[4], Edge(2, 3));
  EXPECT_EQ((*arr_edges_1)[5], Edge(3, 4));
  EXPECT_EQ((*arr_edges_1)[6], Edge(4, 5));
  // PrintEdges(arr_edges_1);
}

TEST(Model_Model3D, Edges_Sort_2) {
  using Edges = inbound_model::Edges;
  using Edge = inbound_model::Edge;

  Edges arr_edges_1;

  (*arr_edges_1).push_back(Edge(0, 0));
  (*arr_edges_1).push_back(Edge(0, 1));
  (*arr_edges_1).push_back(Edge(2, 3));
  (*arr_edges_1).push_back(Edge(4, 3));
  (*arr_edges_1).push_back(Edge(1, 2));
  (*arr_edges_1).push_back(Edge(5, 0));
  (*arr_edges_1).push_back(Edge(5, 4));
  (*arr_edges_1).push_back(Edge(0, 1));

  // PrintEdges(arr_edges_1);
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[1], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[2], Edge(2, 3));
  EXPECT_EQ((*arr_edges_1)[3], Edge(3, 4));
  EXPECT_EQ((*arr_edges_1)[4], Edge(1, 2));
  EXPECT_EQ((*arr_edges_1)[5], Edge(0, 5));
  EXPECT_EQ((*arr_edges_1)[6], Edge(4, 5));
  EXPECT_EQ((*arr_edges_1)[7], Edge(0, 1));
  arr_edges_1.Sort();
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[1], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[2], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[3], Edge(0, 5));
  EXPECT_EQ((*arr_edges_1)[4], Edge(1, 2));
  EXPECT_EQ((*arr_edges_1)[5], Edge(2, 3));
  EXPECT_EQ((*arr_edges_1)[6], Edge(3, 4));
  EXPECT_EQ((*arr_edges_1)[7], Edge(4, 5));
  // PrintEdges(arr_edges_1);
}

TEST(Model_Model3D, Edges_Sort_ExtreamCase) {
  using Edges = inbound_model::Edges;
  using Edge = inbound_model::Edge;

  Edges arr_edges_1;

  EXPECT_EQ((*arr_edges_1).size(), 0);
  arr_edges_1.Sort();
  EXPECT_EQ((*arr_edges_1).size(), 0);

  (*arr_edges_1).push_back(Edge(1, 0));
  EXPECT_EQ((*arr_edges_1).size(), 1);
  arr_edges_1.Sort();
  EXPECT_EQ((*arr_edges_1).size(), 1);
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 1));

  (*arr_edges_1).push_back(Edge(0, 0));
  EXPECT_EQ((*arr_edges_1).size(), 2);
  arr_edges_1.Sort();
  EXPECT_EQ((*arr_edges_1).size(), 2);
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[1], Edge(0, 1));
}

TEST(Model_Model3D, Edges_Normalize_1) {
  using Edges = inbound_model::Edges;
  using Edge = inbound_model::Edge;

  Edges arr_edges_1;

  (*arr_edges_1).push_back(Edge(0, 0));
  (*arr_edges_1).push_back(Edge(0, 1));
  (*arr_edges_1).push_back(Edge(2, 3));
  (*arr_edges_1).push_back(Edge(4, 3));
  (*arr_edges_1).push_back(Edge(1, 2));
  (*arr_edges_1).push_back(Edge(5, 0));
  (*arr_edges_1).push_back(Edge(5, 4));
  (*arr_edges_1).push_back(Edge(0, 1));
  (*arr_edges_1).push_back(Edge(0, 1));
  (*arr_edges_1).push_back(Edge(4, 3));
  (*arr_edges_1).push_back(Edge(4, 3));

  // PrintEdges(arr_edges_1);
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[1], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[2], Edge(2, 3));
  EXPECT_EQ((*arr_edges_1)[3], Edge(3, 4));
  EXPECT_EQ((*arr_edges_1)[4], Edge(1, 2));
  EXPECT_EQ((*arr_edges_1)[5], Edge(0, 5));
  EXPECT_EQ((*arr_edges_1)[6], Edge(4, 5));
  EXPECT_EQ((*arr_edges_1)[7], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[8], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[9], Edge(4, 3));
  EXPECT_EQ((*arr_edges_1)[10], Edge(4, 3));
  arr_edges_1.Normalize();
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[1], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[2], Edge(0, 5));
  EXPECT_EQ((*arr_edges_1)[3], Edge(1, 2));
  EXPECT_EQ((*arr_edges_1)[4], Edge(2, 3));
  EXPECT_EQ((*arr_edges_1)[5], Edge(3, 4));
  EXPECT_EQ((*arr_edges_1)[6], Edge(4, 5));
  // PrintEdges(arr_edges_1);
}

TEST(Model_Model3D, Edges_Normalize_2) {
  using Edges = inbound_model::Edges;
  using Edge = inbound_model::Edge;

  Edges arr_edges_1;

  (*arr_edges_1).push_back(Edge(0, 0));
  (*arr_edges_1).push_back(Edge(0, 1));
  (*arr_edges_1).push_back(Edge(2, 3));
  (*arr_edges_1).push_back(Edge(4, 3));
  (*arr_edges_1).push_back(Edge(1, 2));
  (*arr_edges_1).push_back(Edge(5, 0));
  (*arr_edges_1).push_back(Edge(5, 4));
  (*arr_edges_1).push_back(Edge(0, 1));
  (*arr_edges_1).push_back(Edge(0, 1));
  (*arr_edges_1).push_back(Edge(4, 3));
  (*arr_edges_1).push_back(Edge(4, 3));
  (*arr_edges_1).push_back(Edge(0, 0));
  (*arr_edges_1).push_back(Edge(6, 5));
  (*arr_edges_1).push_back(Edge(0, 0));

  // PrintEdges(arr_edges_1);
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[1], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[2], Edge(2, 3));
  EXPECT_EQ((*arr_edges_1)[3], Edge(3, 4));
  EXPECT_EQ((*arr_edges_1)[4], Edge(1, 2));
  EXPECT_EQ((*arr_edges_1)[5], Edge(0, 5));
  EXPECT_EQ((*arr_edges_1)[6], Edge(4, 5));
  EXPECT_EQ((*arr_edges_1)[7], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[8], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[9], Edge(4, 3));
  EXPECT_EQ((*arr_edges_1)[10], Edge(4, 3));
  EXPECT_EQ((*arr_edges_1)[11], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[12], Edge(5, 6));
  EXPECT_EQ((*arr_edges_1)[13], Edge(0, 0));
  arr_edges_1.Normalize();
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[1], Edge(0, 1));
  EXPECT_EQ((*arr_edges_1)[2], Edge(0, 5));
  EXPECT_EQ((*arr_edges_1)[3], Edge(1, 2));
  EXPECT_EQ((*arr_edges_1)[4], Edge(2, 3));
  EXPECT_EQ((*arr_edges_1)[5], Edge(3, 4));
  EXPECT_EQ((*arr_edges_1)[6], Edge(4, 5));
  EXPECT_EQ((*arr_edges_1)[7], Edge(5, 6));
  // PrintEdges(arr_edges_1);
}

TEST(Model_Model3D, Edges_Normalize_ExtreamCase) {
  using Edges = inbound_model::Edges;
  using Edge = inbound_model::Edge;

  Edges arr_edges_1;

  EXPECT_EQ((*arr_edges_1).size(), 0);
  arr_edges_1.Normalize();
  EXPECT_EQ((*arr_edges_1).size(), 0);

  (*arr_edges_1).push_back(Edge(1, 0));
  EXPECT_EQ((*arr_edges_1).size(), 1);
  arr_edges_1.Normalize();
  EXPECT_EQ((*arr_edges_1).size(), 1);
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 1));

  (*arr_edges_1).push_back(Edge(0, 1));
  EXPECT_EQ((*arr_edges_1).size(), 2);
  arr_edges_1.Normalize();
  EXPECT_EQ((*arr_edges_1).size(), 1);
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 1));

  (*arr_edges_1).push_back(Edge(0, 0));
  EXPECT_EQ((*arr_edges_1).size(), 2);
  arr_edges_1.Normalize();
  EXPECT_EQ((*arr_edges_1).size(), 2);
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[1], Edge(0, 1));

  (*arr_edges_1).push_back(Edge(0, 0));
  (*arr_edges_1).push_back(Edge(0, 0));
  (*arr_edges_1).push_back(Edge(0, 0));
  (*arr_edges_1).push_back(Edge(0, 0));
  (*arr_edges_1).push_back(Edge(0, 0));
  (*arr_edges_1).push_back(Edge(0, 0));
  (*arr_edges_1).push_back(Edge(0, 0));
  arr_edges_1.Normalize();
  EXPECT_EQ((*arr_edges_1).size(), 2);
  EXPECT_EQ((*arr_edges_1)[0], Edge(0, 0));
  EXPECT_EQ((*arr_edges_1)[1], Edge(0, 1));
}

TEST(Model_Model3D, Model3D_Basic_1) {
  using Model3D = inbound_model::Model3D;

  Model3D model;

  for (int i = 0; i < 50; i++) {
    model.AddVert(i, -i, 2 * i);
  }

  EXPECT_EQ(model.GetVerticesAmount(), 50);
  for (int i = 0; i < 50; i++) {
    EXPECT_DOUBLE_EQ(model[i].x, i);
    EXPECT_DOUBLE_EQ(model[i].y, -i);
    EXPECT_DOUBLE_EQ(model[i].z, 2 * i);
  }

  for (int i = 0; i < 20; i++) {
    model.AddEdge(i, i * 2);
  }

  EXPECT_EQ(model.GetEdgesAmount(), 20);
  for (int i = 0; i < 20; i++) {
    EXPECT_EQ(model(i).begin, i);
    EXPECT_EQ(model(i).end, i * 2);
  }

  model.RemoveVert(5);
  EXPECT_DOUBLE_EQ(model[5].x, 6);
  EXPECT_DOUBLE_EQ(model[5].y, -6);
  EXPECT_DOUBLE_EQ(model[5].z, 12);
  model.RemoveVert(10);
  EXPECT_DOUBLE_EQ(model[10].x, 12);
  EXPECT_DOUBLE_EQ(model[10].y, -12);
  EXPECT_DOUBLE_EQ(model[10].z, 24);
  model.RemoveVert(12);
  model.RemoveVert(12);
  model.RemoveVert(12);
  EXPECT_EQ(model.GetVerticesAmount(), 45);

  model.RemoveEdge(5);
  EXPECT_EQ(model(5).begin, 6);
  EXPECT_EQ(model(5).end, 6 * 2);
  model.RemoveEdge(5);
  EXPECT_EQ(model(5).begin, 7);
  EXPECT_EQ(model(5).end, 7 * 2);
  model.RemoveEdge(5);
  model.RemoveEdge(5);
  model.RemoveEdge(5);
  EXPECT_EQ(model.GetEdgesAmount(), 15);

  EXPECT_DOUBLE_EQ(model.GetCenteringVector().x, 0);
  EXPECT_DOUBLE_EQ(model.GetCenteringVector().y, 0);
  EXPECT_DOUBLE_EQ(model.GetCenteringVector().z, 0);
  EXPECT_DOUBLE_EQ(model.GetScaleFactor(), 1);
}

TEST(Model_Model3D, Model3D_Basic_2) {
  using Model3D = inbound_model::Model3D;

  Model3D model;

  for (int i = 0; i < 50; i++) {
    model.AddVert((double)i * 0.5, (double)i * (-0.5),
                  (double)i * 5.5 - 125.25);
  }

  model.RemoveVert(50);
  model.RemoveVert(51);
  EXPECT_EQ(model.GetVerticesAmount(), 50);
  model.RemoveEdge(0);
  model.RemoveEdge(1);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  model.AddEdge(1, 1);
  EXPECT_EQ(model.GetEdgesAmount(), 1);
  model.RemoveEdge(1);
  EXPECT_EQ(model.GetEdgesAmount(), 1);
  model.RemoveEdge(0);
  EXPECT_EQ(model.GetEdgesAmount(), 0);

  model.Clear();
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_DOUBLE_EQ(model.GetCenteringVector().x, 0);
  EXPECT_DOUBLE_EQ(model.GetCenteringVector().y, 0);
  EXPECT_DOUBLE_EQ(model.GetCenteringVector().z, 0);
  EXPECT_DOUBLE_EQ(model.GetScaleFactor(), 1);
}

/*
 * SortEdges()
 * NormalizeEdges()
 * RemoveGhostEdges()
 */
TEST(Model_Model3D, Model3D_EdgeSpesialMethods) {
  using Model3D = inbound_model::Model3D;

  Model3D model;

  for (int i = 0; i < 5; i++) {
    model.AddVert(i, -i, 2 * i);
  }
  for (int i = 0; i < 5; i++) {
    model.AddEdge(i, i + 2);
  }
  for (int i = 9; i >= 2; i--) {
    model.AddEdge(i, i - 2);
  }

  EXPECT_EQ(model.GetEdgesAmount(), 13);
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(model(i).begin, i);
    EXPECT_EQ(model(i).end, i + 2);
  }
  for (int i = 5, j = 7; i <= 12; i++, j--) {
    EXPECT_EQ(model(i).begin, j);
    EXPECT_EQ(model(i).end, j + 2);
  }

  model.SortEdges();
  for (int i = 0, j = 0; i < 10; i += 2, j++) {
    EXPECT_EQ(model(i).begin, j);
    EXPECT_EQ(model(i).end, j + 2);
    EXPECT_EQ(model(i + 1).begin, j);
    EXPECT_EQ(model(i + 1).end, j + 2);
  }

  model.Clear();
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetEdgesAmount(), 0);

  for (int i = 0; i < 5; i++) {
    model.AddVert(i, -i, 2 * i);
  }
  for (int i = 0; i < 5; i++) {
    model.AddEdge(i, i + 2);
  }
  for (int i = 9; i >= 2; i--) {
    model.AddEdge(i, i - 2);
  }

  EXPECT_EQ(model.GetEdgesAmount(), 13);
  EXPECT_EQ(model.GetVerticesAmount(), 5);
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(model(i).begin, i);
    EXPECT_EQ(model(i).end, i + 2);
  }
  for (int i = 5, j = 7; i <= 12; i++, j--) {
    EXPECT_EQ(model(i).begin, j);
    EXPECT_EQ(model(i).end, j + 2);
  }

  model.NormalizeEdges();
  EXPECT_EQ(model.GetEdgesAmount(), 8);
  EXPECT_EQ(model.GetVerticesAmount(), 5);
  for (int i = 0; i < 8; i++) {
    EXPECT_EQ(model(i).begin, i);
    EXPECT_EQ(model(i).end, i + 2);
  }

  model.RemoveGhostEdges();
  EXPECT_EQ(model.GetEdgesAmount(), 3);
  EXPECT_EQ(model.GetVerticesAmount(), 5);
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(model(i).begin, i);
    EXPECT_EQ(model(i).end, i + 2);
  }

  model.Clear();
  model.RemoveGhostEdges();
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_EQ(model.GetVerticesAmount(), 0);

  model.AddVert(1, 1, 1);
  model.AddEdge(0, 0);
  model.AddEdge(0, 1);
  EXPECT_EQ(model.GetEdgesAmount(), 2);
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  model.RemoveGhostEdges();
  EXPECT_EQ(model.GetEdgesAmount(), 1);
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model(0).begin, 0);
  EXPECT_EQ(model(0).end, 0);

  model.Clear();
  model.AddEdge(0, 0);
  EXPECT_EQ(model.GetEdgesAmount(), 1);
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  model.SortEdges();
  model.NormalizeEdges();
  model.RemoveGhostEdges();
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_EQ(model.GetVerticesAmount(), 0);
}

TEST(Model_Model3D, Model3D_Basic_GeneralUsage) {
  using Model3D = inbound_model::Model3D;

  Model3D model;

  for (int i = 0; i < 20; i++) {
    model.AddVert(i, -i, 2 * i);
  }

  for (int i = 0; i < 19; i++) {
    model.AddEdge(i, i + 1);
  }
  model.AddEdge(19, 0);

  EXPECT_EQ(model.GetVerticesAmount(), 20);
  EXPECT_EQ(model.GetEdgesAmount(), 20);

  for (int i = 0; i < 19; i++) {
    EXPECT_EQ(model(i).begin, i);
    EXPECT_EQ(model(i).end, i + 1);
    EXPECT_DOUBLE_EQ(model[model(i).begin].x, i);
    EXPECT_DOUBLE_EQ(model[model(i).begin].y, -i);
    EXPECT_DOUBLE_EQ(model[model(i).begin].z, 2 * i);
    EXPECT_DOUBLE_EQ(model[model(i).end].x, i + 1);
    EXPECT_DOUBLE_EQ(model[model(i).end].y, -i - 1);
    EXPECT_DOUBLE_EQ(model[model(i).end].z, 2 * i + 2);
  }
  EXPECT_DOUBLE_EQ(model[model(19).begin].x, 0);
  EXPECT_DOUBLE_EQ(model[model(19).begin].y, 0);
  EXPECT_DOUBLE_EQ(model[model(19).begin].z, 0);
  EXPECT_DOUBLE_EQ(model[model(19).end].x, 19);
  EXPECT_DOUBLE_EQ(model[model(19).end].y, -19);
  EXPECT_DOUBLE_EQ(model[model(19).end].z, 2 * 19);
}

TEST(Model_Model3D, Model3D_Basic_Errors) {
  using Model3D = inbound_model::Model3D;

  Model3D model;

  for (int i = 0; i < 20; i++) {
    model.AddVert(i, -i, 2 * i);
  }

  for (int i = 0; i < 19; i++) {
    model.AddEdge(i, i + 1);
  }
  model.AddEdge(19, 0);

  EXPECT_EQ(model.GetVerticesAmount(), 20);
  EXPECT_EQ(model.GetEdgesAmount(), 20);

  for (int i = 0; i < 20; i++) {
    EXPECT_NO_THROW(model[i]);
    EXPECT_NO_THROW(model(i));
  }
  EXPECT_THROW(model[20], std::out_of_range);
  EXPECT_THROW(model(20), std::out_of_range);
  EXPECT_THROW(model[21], std::out_of_range);
  EXPECT_THROW(model(21), std::out_of_range);
  EXPECT_THROW(model[-1], std::out_of_range);
  EXPECT_THROW(model(-1), std::out_of_range);
}

TEST(Model_Model3D, Model3D_Scaling_1) {
  using Model3D = inbound_model::Model3D;
  using Vec3 = vectors::Vec3;

  Model3D model;

  for (int i = 0; i < 5; i++) {
    model.AddVert(5.5 * i, 5.5 * (5 - i), 5.5 * i - (i + 5.5));
  }
  for (int i = 0; i < 5; i++) {
    model.AddVert(5.5 * (5 - i), 5.5 * (-i), (i + 5.5) - 5.5 * i);
  }
  for (int i = 0; i < 5; i++) {
    model.AddVert(5.5 * (-i), 5.5 * (i - 5), 5 * i - (i + 5.5));
  }
  for (int i = 0; i < 5; i++) {
    model.AddVert(5.5 * (i - 5), 5.5 * (i), (i + 5.5) - 5.5 * i);
  }
  EXPECT_EQ(model.GetVerticesAmount(), 20);

  for (int i = 0; i < 19; i++) {
    model.AddEdge(i, i + 1);
  }
  model.AddEdge(19, 0);
  EXPECT_EQ(model.GetEdgesAmount(), 20);

  EXPECT_EQ(model[4], Vec3(22, 5.5, 12.5));
  EXPECT_EQ(model[0], Vec3(0, 27.5, -5.5));
  EXPECT_EQ(model[5], Vec3(27.5, 0, 5.5));
  EXPECT_EQ(model.IsScaled(), false);
  EXPECT_DOUBLE_EQ(model.GetScaleFactor(), 1);
  model.Scale();
  EXPECT_EQ(model.IsScaled(), true);
  EXPECT_NEAR(model.GetScaleFactor(), 0.0363636, 0.00000009);
  for (int i = 0; i < 20; i++) {
    EXPECT_LE(abs(model[i].x), 1);
    EXPECT_LE(abs(model[i].y), 1);
    EXPECT_LE(abs(model[i].z), 1);
    if (abs(model[i].x) == 1) {
      EXPECT_EQ(i % 5, 0);
    }
  }

  model.Scale();
  for (int i = 0; i < 20; i++) {
    if (abs(model[i].x) == 1) {
      EXPECT_EQ(i % 5, 0);
    }
  }
  EXPECT_EQ(model.IsScaled(), true);

  model.Unscale();
  EXPECT_EQ(model.IsScaled(), false);
  EXPECT_DOUBLE_EQ(model.GetScaleFactor(), 1);
  EXPECT_NEAR(model[4].x, 22, 0.001);
  EXPECT_NEAR(model[4].y, 5.5, 0.001);
  EXPECT_NEAR(model[4].z, 12.5, 0.001);
  EXPECT_NEAR(model[0].x, 0, 0.001);
  EXPECT_NEAR(model[0].y, 27.5, 0.001);
  EXPECT_NEAR(model[0].z, -5.5, 0.001);
  EXPECT_NEAR(model[5].x, 27.5, 0.001);
  EXPECT_NEAR(model[5].y, 0, 0.001);
  EXPECT_NEAR(model[5].z, 5.5, 0.001);

  model.Scale();
  EXPECT_EQ(model.IsScaled(), true);
  EXPECT_NEAR(model.GetScaleFactor(), 0.0363636, 0.00000009);
  for (int i = 0; i < 20; i++) {
    EXPECT_LE(abs(model[i].x), 1);
    EXPECT_LE(abs(model[i].y), 1);
    EXPECT_LE(abs(model[i].z), 1);
    if (abs(model[i].x) == 1) {
      EXPECT_EQ(i % 5, 0);
    }
  }
}

TEST(Model_Model3D, Model3D_Scaling_2) {
  using Model3D = inbound_model::Model3D;
  using Vec3 = vectors::Vec3;

  Model3D model;

  for (int i = 0; i < 21; i++) {
    model.AddVert(i, -i, 0);
  }
  EXPECT_EQ(model.GetVerticesAmount(), 21);

  for (int i = 0; i < 20; i++) {
    model.AddEdge(i, i + 1);
  }
  model.AddEdge(20, 0);
  EXPECT_EQ(model.GetEdgesAmount(), 21);

  EXPECT_EQ(model[4], Vec3(4, -4, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[5], Vec3(5, -5, 0));
  EXPECT_EQ(model.IsScaled(), false);
  EXPECT_DOUBLE_EQ(model.GetScaleFactor(), 1);

  model.Scale();
  EXPECT_EQ(model.IsScaled(), true);
  EXPECT_NEAR(model.GetScaleFactor(), 0.05, 0.001);
  for (int i = 0; i < 21; i++) {
    EXPECT_LE(abs(model[i].x), 1);
    EXPECT_LE(abs(model[i].y), 1);
    EXPECT_LE(abs(model[i].z), 1);
  }
  EXPECT_EQ(model[4], Vec3(0.2, -0.2, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[5], Vec3(0.25, -0.25, 0));
  EXPECT_EQ(model[20], Vec3(1, -1, 0));

  model.AddVert(50, 0, 0);
  EXPECT_EQ(model[4], Vec3(4, -4, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[5], Vec3(5, -5, 0));
  EXPECT_EQ(model[20], Vec3(20, -20, 0));
  EXPECT_EQ(model[21], Vec3(50, 0, 0));
  EXPECT_EQ(model.IsScaled(), false);
  EXPECT_DOUBLE_EQ(model.GetScaleFactor(), 1);

  model.Scale();
  EXPECT_EQ(model.IsScaled(), true);
  EXPECT_NEAR(model.GetScaleFactor(), 0.02, 0.001);
  for (int i = 0; i < 21; i++) {
    EXPECT_LE(abs(model[i].x), 1);
    EXPECT_LE(abs(model[i].y), 1);
    EXPECT_LE(abs(model[i].z), 1);
  }
  EXPECT_EQ(model[4], Vec3(0.08, -0.08, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[5], Vec3(0.1, -0.1, 0));
  EXPECT_EQ(model[20], Vec3(0.4, -0.4, 0));
  EXPECT_EQ(model[21], Vec3(1, 0, 0));

  model.RemoveVert(19);
  EXPECT_EQ(model.IsScaled(), true);
  EXPECT_NEAR(model.GetScaleFactor(), 0.02, 0.001);
  for (int i = 0; i < 21; i++) {
    EXPECT_LE(abs(model[i].x), 1);
    EXPECT_LE(abs(model[i].y), 1);
    EXPECT_LE(abs(model[i].z), 1);
  }
  EXPECT_EQ(model[4], Vec3(0.08, -0.08, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[5], Vec3(0.1, -0.1, 0));
  EXPECT_EQ(model[19], Vec3(0.4, -0.4, 0));
  EXPECT_EQ(model[20], Vec3(1, 0, 0));
  model.Scale();
  EXPECT_EQ(model.IsScaled(), true);
  EXPECT_NEAR(model.GetScaleFactor(), 0.02, 0.001);
  for (int i = 0; i < 21; i++) {
    EXPECT_LE(abs(model[i].x), 1);
    EXPECT_LE(abs(model[i].y), 1);
    EXPECT_LE(abs(model[i].z), 1);
  }
  EXPECT_EQ(model[4], Vec3(0.08, -0.08, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[5], Vec3(0.1, -0.1, 0));
  EXPECT_EQ(model[19], Vec3(0.4, -0.4, 0));
  EXPECT_EQ(model[20], Vec3(1, 0, 0));

  model.RemoveVert(20);
  EXPECT_EQ(model.IsScaled(), true);
  EXPECT_NEAR(model.GetScaleFactor(), 0.02, 0.001);
  for (int i = 0; i < 20; i++) {
    EXPECT_LE(abs(model[i].x), 1);
    EXPECT_LE(abs(model[i].y), 1);
    EXPECT_LE(abs(model[i].z), 1);
  }
  EXPECT_EQ(model[4], Vec3(0.08, -0.08, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[5], Vec3(0.1, -0.1, 0));
  EXPECT_EQ(model[19], Vec3(0.4, -0.4, 0));
  model.Scale();
  EXPECT_EQ(model.IsScaled(), true);
  EXPECT_NEAR(model.GetScaleFactor(), 0.02, 0.001);
  for (int i = 0; i < 20; i++) {
    EXPECT_LE(abs(model[i].x), 1);
    EXPECT_LE(abs(model[i].y), 1);
    EXPECT_LE(abs(model[i].z), 1);
  }
  EXPECT_EQ(model[4], Vec3(0.08, -0.08, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[5], Vec3(0.1, -0.1, 0));
  EXPECT_EQ(model[19], Vec3(0.4, -0.4, 0));
  model.Unscale();
  model.Scale();
  EXPECT_EQ(model.IsScaled(), true);
  EXPECT_NEAR(model.GetScaleFactor(), 0.05, 0.001);
  for (int i = 0; i < 20; i++) {
    EXPECT_LE(abs(model[i].x), 1);
    EXPECT_LE(abs(model[i].y), 1);
    EXPECT_LE(abs(model[i].z), 1);
  }
  EXPECT_EQ(model[4], Vec3(0.2, -0.2, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[5], Vec3(0.25, -0.25, 0));
  EXPECT_EQ(model[19], Vec3(1, -1, 0));

  model.Clear();
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_EQ(model.GetScaleFactor(), 1);
  EXPECT_EQ(model.IsScaled(), false);

  model.Scale();
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_EQ(model.GetScaleFactor(), 1);
  EXPECT_EQ(model.IsScaled(), false);
  model.Unscale();
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_EQ(model.GetScaleFactor(), 1);
  EXPECT_EQ(model.IsScaled(), false);
}

TEST(Model_Model3D, Model3D_Scaling_3) {
  using Model3D = inbound_model::Model3D;
  using Vec3 = vectors::Vec3;

  Model3D model;

  for (int i = 0; i < 21; i++) {
    model.AddVert(i, -i, 0);
  }
  EXPECT_EQ(model.GetVerticesAmount(), 21);

  for (int i = 0; i < 20; i++) {
    model.AddEdge(i, i + 1);
  }
  model.AddEdge(20, 0);
  EXPECT_EQ(model.GetEdgesAmount(), 21);

  model.Clear();

  model.AddVert(50, 50, 50);
  EXPECT_EQ(model[0], Vec3(50, 50, 50));
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_EQ(model.IsScaled(), false);
  EXPECT_EQ(model.GetScaleFactor(), 1);
  model.Scale();
  EXPECT_EQ(model[0], Vec3(1, 1, 1));
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_EQ(model.IsScaled(), true);
  EXPECT_DOUBLE_EQ(model.GetScaleFactor(), 1.0 / 50.0);
}

TEST(Model_Model3D, Model3D_Scaling_4) {
  using Model3D = inbound_model::Model3D;

  Model3D model;

  for (int i = 0; i < 2; i++) {
    model.AddVert(-i / 10, i * 10, 0);
  }
  EXPECT_EQ(model.GetVerticesAmount(), 2);

  EXPECT_EQ(model.IsScaled(), false);
  model.Scale();
  EXPECT_EQ(model.IsScaled(), true);
  model.RemoveEdge(1);
  EXPECT_EQ(model.IsScaled(), true);
  model.Scale();
  EXPECT_EQ(model.IsScaled(), true);
  model.RemoveEdge(0);
  EXPECT_EQ(model.IsScaled(), true);
  model.Scale();
  EXPECT_EQ(model.IsScaled(), true);
  model.Unscale();
  EXPECT_EQ(model.IsScaled(), false);
}

TEST(Model_Model3D, Model3D_Centering_1) {
  using Model3D = inbound_model::Model3D;
  using Vec3 = vectors::Vec3;

  Model3D model;

  for (int i = 0; i < 5; i++) {
    model.AddVert(5.5 * i, 5.5 * (5 - i), 5.5 * i - (i + 5.5));
  }
  for (int i = 0; i < 5; i++) {
    model.AddVert(5.5 * (5 - i), 5.5 * (-i), (i + 5.5) - 5.5 * i);
  }
  for (int i = 0; i < 5; i++) {
    model.AddVert(5.5 * (-i), 5.5 * (i - 5), 5 * i - (i + 5.5));
  }
  for (int i = 0; i < 5; i++) {
    model.AddVert(5.5 * (i - 5), 5.5 * (i), (i + 5.5) - 5.5 * i);
  }
  EXPECT_EQ(model.GetVerticesAmount(), 20);

  for (int i = 0; i < 19; i++) {
    model.AddEdge(i, i + 1);
  }
  model.AddEdge(19, 0);
  EXPECT_EQ(model.GetEdgesAmount(), 20);

  EXPECT_EQ(model[0], Vec3(0, 27.5, -5.5));
  EXPECT_EQ(model[4], Vec3(22, 5.5, 12.5));
  EXPECT_EQ(model[5], Vec3(27.5, 0, 5.5));
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));

  model.Center();
  EXPECT_EQ(model[0], Vec3(0, 27.5, -5.5));
  EXPECT_EQ(model[4], Vec3(22, 5.5, 12.5));
  EXPECT_EQ(model[5], Vec3(27.5, 0, 5.5));
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));
}

TEST(Model_Model3D, Model3D_Centering_2) {
  using Model3D = inbound_model::Model3D;
  using Vec3 = vectors::Vec3;

  Model3D model;

  for (int i = 0; i < 5; i++) {
    model.AddVert(50.5 + 5.5 * i, 5.5 * (5 - i) - 100.5,
                  5.5 * i - (i + 5.5) + 25.5);
  }
  for (int i = 0; i < 5; i++) {
    model.AddVert(50.5 + 5.5 * (5 - i), 5.5 * (-i) - 100.5,
                  (i + 5.5) - 5.5 * i - 25.5);
  }
  for (int i = 0; i < 5; i++) {
    model.AddVert(50.5 + 5.5 * (-i), 5.5 * (i - 5) - 100.5,
                  5 * i - (i + 5.5) - 25.5);
  }
  for (int i = 0; i < 5; i++) {
    model.AddVert(50.5 + 5.5 * (i - 5), 5.5 * (i)-100.5,
                  (i + 5.5) - 5.5 * i + 25.5);
  }
  EXPECT_EQ(model.GetVerticesAmount(), 20);

  for (int i = 0; i < 19; i++) {
    model.AddEdge(i, i + 1);
  }
  model.AddEdge(19, 0);
  EXPECT_EQ(model.GetEdgesAmount(), 20);

  EXPECT_EQ(model[0], Vec3(50.5, -73, 20));
  EXPECT_EQ(model[4], Vec3(72.5, -95, 38));
  EXPECT_EQ(model[5], Vec3(78, -100.5, -20));
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));

  model.Center();
  EXPECT_EQ(model[0], Vec3(0, 27.5, 20));
  EXPECT_EQ(model[4], Vec3(22, 5.5, 38));
  EXPECT_EQ(model[5], Vec3(27.5, 0, -20));
  EXPECT_EQ(model.IsCentered(), true);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(-50.5, 100.5, 0));

  model.Center();
  EXPECT_EQ(model[0], Vec3(0, 27.5, 20));
  EXPECT_EQ(model[4], Vec3(22, 5.5, 38));
  EXPECT_EQ(model[5], Vec3(27.5, 0, -20));
  EXPECT_EQ(model.IsCentered(), true);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(-50.5, 100.5, 0));

  model.Uncenter();
  EXPECT_EQ(model[0], Vec3(50.5, -73, 20));
  EXPECT_EQ(model[4], Vec3(72.5, -95, 38));
  EXPECT_EQ(model[5], Vec3(78, -100.5, -20));
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));

  model.Center();
  EXPECT_EQ(model[0], Vec3(0, 27.5, 20));
  EXPECT_EQ(model[4], Vec3(22, 5.5, 38));
  EXPECT_EQ(model[5], Vec3(27.5, 0, -20));
  EXPECT_EQ(model.IsCentered(), true);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(-50.5, 100.5, 0));
}

TEST(Model_Model3D, Model3D_Centering_3) {
  using Model3D = inbound_model::Model3D;
  using Vec3 = vectors::Vec3;

  Model3D model;

  for (int i = 0; i < 21; i++) {
    model.AddVert(i, -i, 0);
  }
  EXPECT_EQ(model.GetVerticesAmount(), 21);

  for (int i = 0; i < 20; i++) {
    model.AddEdge(i, i + 1);
  }
  model.AddEdge(20, 0);
  EXPECT_EQ(model.GetEdgesAmount(), 21);

  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[4], Vec3(4, -4, 0));
  EXPECT_EQ(model[5], Vec3(5, -5, 0));
  EXPECT_EQ(model[20], Vec3(20, -20, 0));

  model.Center();
  EXPECT_EQ(model.IsCentered(), true);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(-10, 10, 0));
  EXPECT_EQ(model[0], Vec3(-10, 10, 0));
  EXPECT_EQ(model[4], Vec3(-6, 6, 0));
  EXPECT_EQ(model[5], Vec3(-5, 5, 0));
  EXPECT_EQ(model[20], Vec3(10, -10, 0));

  model.AddVert(50, 0, 0);
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[4], Vec3(4, -4, 0));
  EXPECT_EQ(model[5], Vec3(5, -5, 0));
  EXPECT_EQ(model[20], Vec3(20, -20, 0));
  EXPECT_EQ(model[21], Vec3(50, 0, 0));

  model.Center();
  EXPECT_EQ(model.IsCentered(), true);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(-25, 10, 0));
  EXPECT_EQ(model[0], Vec3(-25, 10, 0));
  EXPECT_EQ(model[4], Vec3(-21, 6, 0));
  EXPECT_EQ(model[5], Vec3(-20, 5, 0));
  EXPECT_EQ(model[20], Vec3(-5, -10, 0));
  EXPECT_EQ(model[21], Vec3(25, 10, 0));

  model.RemoveVert(19);
  EXPECT_EQ(model.IsCentered(), true);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(-25, 10, 0));
  EXPECT_EQ(model[0], Vec3(-25, 10, 0));
  EXPECT_EQ(model[4], Vec3(-21, 6, 0));
  EXPECT_EQ(model[5], Vec3(-20, 5, 0));
  EXPECT_EQ(model[19], Vec3(-5, -10, 0));
  EXPECT_EQ(model[20], Vec3(25, 10, 0));
  model.RemoveVert(20);
  EXPECT_EQ(model.IsCentered(), true);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(-25, 10, 0));
  EXPECT_EQ(model[0], Vec3(-25, 10, 0));
  EXPECT_EQ(model[4], Vec3(-21, 6, 0));
  EXPECT_EQ(model[5], Vec3(-20, 5, 0));
  EXPECT_EQ(model[19], Vec3(-5, -10, 0));
  model.Center();
  EXPECT_EQ(model.IsCentered(), true);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(-25, 10, 0));
  EXPECT_EQ(model[0], Vec3(-25, 10, 0));
  EXPECT_EQ(model[4], Vec3(-21, 6, 0));
  EXPECT_EQ(model[5], Vec3(-20, 5, 0));
  EXPECT_EQ(model[19], Vec3(-5, -10, 0));
  model.Uncenter();
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[4], Vec3(4, -4, 0));
  EXPECT_EQ(model[5], Vec3(5, -5, 0));
  EXPECT_EQ(model[19], Vec3(20, -20, 0));
  model.Center();
  EXPECT_EQ(model.IsCentered(), true);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(-10, 10, 0));
  EXPECT_EQ(model[0], Vec3(-10, 10, 0));
  EXPECT_EQ(model[4], Vec3(-6, 6, 0));
  EXPECT_EQ(model[5], Vec3(-5, 5, 0));
  EXPECT_EQ(model[19], Vec3(10, -10, 0));

  model.Clear();
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));
  model.Center();
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));
  model.Uncenter();
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));
  model.Center();
  model.Center();
  model.Center();
  model.Center();
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));
  model.Uncenter();
  model.Uncenter();
  model.Uncenter();
  model.Uncenter();
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));
}

TEST(Model_Model3D, Model3D_Centering_4) {
  using Model3D = inbound_model::Model3D;
  using Vec3 = vectors::Vec3;

  Model3D model;

  for (int i = 0; i < 21; i++) {
    model.AddVert(i, -i, 0);
  }
  EXPECT_EQ(model.GetVerticesAmount(), 21);

  for (int i = 0; i < 20; i++) {
    model.AddEdge(i, i + 1);
  }
  model.AddEdge(20, 0);
  EXPECT_EQ(model.GetEdgesAmount(), 21);

  model.Clear();

  model.AddVert(50, 50, 50);
  EXPECT_EQ(model[0], Vec3(50, 50, 50));
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_EQ(model.IsCentered(), false);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(0, 0, 0));
  model.Center();
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_EQ(model.IsCentered(), true);
  EXPECT_EQ(model.GetCenteringVector(), Vec3(-50, -50, -50));
}

TEST(Model_Model3D, Model3D_Single_Vertice_Edges) {
  using Model3D = inbound_model::Model3D;
  using Vec3 = vectors::Vec3;
  using Edge = inbound_model::Edge;

  Model3D model;

  for (int i = 0; i <= 20; i++) {
    model.AddVert(i, -i, 0);
  }
  for (int i = 0; i < 10; i++) {
    model.AddEdge(i, i + 1);
  }
  model.AddEdge(10, 0);
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 11);
  EXPECT_EQ(model[0], Vec3(0, 0, 0));
  EXPECT_EQ(model[4], Vec3(4, -4, 0));
  EXPECT_EQ(model[5], Vec3(5, -5, 0));
  EXPECT_EQ(model[20], Vec3(20, -20, 0));
  EXPECT_EQ(model(0), Edge(0, 1));
  EXPECT_EQ(model(1), Edge(1, 2));
  EXPECT_EQ(model(9), Edge(9, 10));
  EXPECT_EQ(model(10), Edge(0, 10));

  model.AddSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 21);
  EXPECT_EQ(model(0), Edge(0, 1));
  EXPECT_EQ(model(1), Edge(1, 2));
  EXPECT_EQ(model(9), Edge(9, 10));
  EXPECT_EQ(model(10), Edge(0, 10));
  for (int i = 11; i < 21; i++) {
    EXPECT_EQ(model(i), Edge(i, i));
  }
  EXPECT_EQ(model(15), Edge(15, 15));

  model.SortEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 21);
  EXPECT_EQ(model(0), Edge(0, 1));
  EXPECT_EQ(model(1), Edge(0, 10));
  EXPECT_EQ(model(2), Edge(1, 2));
  EXPECT_EQ(model(10), Edge(9, 10));
  EXPECT_EQ(model(15), Edge(15, 15));

  for (int i = 0; i < 5; i++) {
    model.RemoveEdge(0);
  }
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 16);
  EXPECT_EQ(model(0), Edge(4, 5));
  EXPECT_EQ(model(1), Edge(5, 6));
  EXPECT_EQ(model(2), Edge(6, 7));
  EXPECT_EQ(model(10), Edge(15, 15));
  EXPECT_EQ(model(15), Edge(20, 20));

  model.AddSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 20);
  EXPECT_EQ(model(0), Edge(4, 5));
  EXPECT_EQ(model(1), Edge(5, 6));
  EXPECT_EQ(model(2), Edge(6, 7));
  EXPECT_EQ(model(10), Edge(15, 15));
  EXPECT_EQ(model(15), Edge(20, 20));
  EXPECT_EQ(model(16), Edge(0, 0));
  EXPECT_EQ(model(17), Edge(1, 1));
  EXPECT_EQ(model(18), Edge(2, 2));
  EXPECT_EQ(model(19), Edge(3, 3));

  model.SortEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 20);
  EXPECT_EQ(model(0), Edge(0, 0));
  EXPECT_EQ(model(1), Edge(1, 1));
  EXPECT_EQ(model(2), Edge(2, 2));
  EXPECT_EQ(model(3), Edge(3, 3));
  EXPECT_EQ(model(4), Edge(4, 5));
  EXPECT_EQ(model(5), Edge(5, 6));
  EXPECT_EQ(model(6), Edge(6, 7));
  EXPECT_EQ(model(14), Edge(15, 15));
  EXPECT_EQ(model(19), Edge(20, 20));

  model.AddSingleVertEdges();
  model.AddSingleVertEdges();
  model.AddSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 20);
  EXPECT_EQ(model(0), Edge(0, 0));
  EXPECT_EQ(model(1), Edge(1, 1));
  EXPECT_EQ(model(2), Edge(2, 2));
  EXPECT_EQ(model(3), Edge(3, 3));
  EXPECT_EQ(model(4), Edge(4, 5));
  EXPECT_EQ(model(5), Edge(5, 6));
  EXPECT_EQ(model(6), Edge(6, 7));
  EXPECT_EQ(model(14), Edge(15, 15));
  EXPECT_EQ(model(19), Edge(20, 20));

  model.RemoveSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 6);
  EXPECT_EQ(model(0), Edge(4, 5));
  EXPECT_EQ(model(1), Edge(5, 6));
  EXPECT_EQ(model(2), Edge(6, 7));
  EXPECT_EQ(model(5), Edge(9, 10));

  model.RemoveSingleVertEdges();
  model.RemoveSingleVertEdges();
  model.RemoveSingleVertEdges();
  model.RemoveSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 6);
  EXPECT_EQ(model(0), Edge(4, 5));
  EXPECT_EQ(model(1), Edge(5, 6));
  EXPECT_EQ(model(2), Edge(6, 7));
  EXPECT_EQ(model(5), Edge(9, 10));

  model.Clear();
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  model.AddSingleVertEdges();
  model.AddSingleVertEdges();
  model.AddSingleVertEdges();
  model.AddSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  model.RemoveSingleVertEdges();
  model.RemoveSingleVertEdges();
  model.RemoveSingleVertEdges();
  model.RemoveSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetEdgesAmount(), 0);

  model.AddVert(1, 2, 3);
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  model.RemoveSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  model.AddSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model.GetEdgesAmount(), 1);

  model.AddVert(3, 2, 3);
  EXPECT_EQ(model.GetVerticesAmount(), 2);
  EXPECT_EQ(model.GetEdgesAmount(), 1);
  model.RemoveSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 2);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  model.AddSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 2);
  EXPECT_EQ(model.GetEdgesAmount(), 2);

  model.AddEdge(0, 1);
  EXPECT_EQ(model.GetVerticesAmount(), 2);
  EXPECT_EQ(model.GetEdgesAmount(), 3);
  model.AddSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 2);
  EXPECT_EQ(model.GetEdgesAmount(), 3);
  model.RemoveSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 2);
  EXPECT_EQ(model.GetEdgesAmount(), 1);
}

TEST(Model_Model3D, Model3D_Model_Name) {
  using Model3D = inbound_model::Model3D;

  Model3D model;
  std::string str_in{"Margo"}, str_out;

  model.SetName(str_in);
  EXPECT_EQ(model.GetName(), str_in);

  model.Clear();
  EXPECT_EQ(model.GetName(), "");
}

TEST(Model_Model3D, Model3D_ManageEdges_1) {
  using Model3D = inbound_model::Model3D;
  using Edge = inbound_model::Edge;

  Model3D model;

  for (int i = 0; i <= 20; i++) {
    model.AddVert(i, -i, 0);
  }
  for (int i = 10; i < 20; i++) {
    model.AddEdge(i, i + 1);
    model.AddEdge(i, i + 1);
    model.AddEdge(i, i + 1);
  }
  for (int i = 0; i < 10; i++) {
    model.AddEdge(i, i + 1);
  }
  model.AddEdge(10, 0);
  for (int i = 20; i < 30; i++) {
    model.AddEdge(i, i + 1);
    model.AddEdge(i, i + 1);
    model.AddEdge(i, i + 1);
  }

  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 71);
  EXPECT_EQ(model(0), Edge(10, 11));
  EXPECT_EQ(model(1), Edge(10, 11));
  EXPECT_EQ(model(2), Edge(10, 11));
  EXPECT_EQ(model(3), Edge(11, 12));
  EXPECT_EQ(model(10), Edge(13, 14));
  EXPECT_EQ(model(11), Edge(13, 14));
  EXPECT_EQ(model(12), Edge(14, 15));
  EXPECT_EQ(model(15), Edge(15, 16));
  EXPECT_EQ(model(20), Edge(16, 17));
  EXPECT_EQ(model(21), Edge(17, 18));
  EXPECT_EQ(model(22), Edge(17, 18));
  EXPECT_EQ(model(23), Edge(17, 18));
  EXPECT_EQ(model(30), Edge(0, 1));
  EXPECT_EQ(model(31), Edge(1, 2));
  EXPECT_EQ(model(32), Edge(2, 3));
  EXPECT_EQ(model(33), Edge(3, 4));
  EXPECT_EQ(model(40), Edge(0, 10));
  EXPECT_EQ(model(41), Edge(20, 21));
  EXPECT_EQ(model(42), Edge(20, 21));
  EXPECT_EQ(model(43), Edge(20, 21));
  EXPECT_EQ(model(44), Edge(21, 22));
  EXPECT_EQ(model(50), Edge(23, 24));
  EXPECT_EQ(model(51), Edge(23, 24));
  EXPECT_EQ(model(52), Edge(23, 24));
  EXPECT_EQ(model(53), Edge(24, 25));
  EXPECT_EQ(model(60), Edge(26, 27));
  EXPECT_EQ(model(61), Edge(26, 27));
  EXPECT_EQ(model(62), Edge(27, 28));
  EXPECT_EQ(model(63), Edge(27, 28));
  EXPECT_EQ(model(70), Edge(29, 30));
  EXPECT_THROW(model(71), std::out_of_range);

  model.ManageEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 21);
  EXPECT_EQ(model(0), Edge(0, 1));
  EXPECT_EQ(model(1), Edge(0, 10));
  EXPECT_EQ(model(2), Edge(1, 2));
  EXPECT_EQ(model(3), Edge(2, 3));
  EXPECT_EQ(model(10), Edge(9, 10));
  EXPECT_EQ(model(11), Edge(10, 11));
  EXPECT_EQ(model(12), Edge(11, 12));
  EXPECT_EQ(model(15), Edge(14, 15));
  EXPECT_EQ(model(20), Edge(19, 20));
  EXPECT_THROW(model(21), std::out_of_range);
  EXPECT_THROW(model(22), std::out_of_range);
  EXPECT_THROW(model(23), std::out_of_range);
  EXPECT_THROW(model(30), std::out_of_range);
  EXPECT_THROW(model(31), std::out_of_range);
  EXPECT_THROW(model(32), std::out_of_range);
  EXPECT_THROW(model(33), std::out_of_range);
  EXPECT_THROW(model(40), std::out_of_range);
  EXPECT_THROW(model(41), std::out_of_range);
  EXPECT_THROW(model(42), std::out_of_range);
  EXPECT_THROW(model(43), std::out_of_range);
  EXPECT_THROW(model(44), std::out_of_range);
  EXPECT_THROW(model(50), std::out_of_range);
  EXPECT_THROW(model(51), std::out_of_range);
  EXPECT_THROW(model(52), std::out_of_range);
  EXPECT_THROW(model(53), std::out_of_range);
  EXPECT_THROW(model(60), std::out_of_range);
  EXPECT_THROW(model(61), std::out_of_range);
  EXPECT_THROW(model(62), std::out_of_range);
  EXPECT_THROW(model(63), std::out_of_range);
  EXPECT_THROW(model(70), std::out_of_range);
  EXPECT_THROW(model(71), std::out_of_range);
}

TEST(Model_Model3D, Model3D_ManageEdges_2) {
  using Model3D = inbound_model::Model3D;
  using Edge = inbound_model::Edge;

  Model3D model;

  for (int i = 0; i <= 20; i++) {
    model.AddVert(i, -i, 0);
  }
  for (int i = 10; i < 20; i++) {
    model.AddEdge(i, i + 1);
    model.AddEdge(i, i + 1);
    model.AddEdge(i, i + 1);
  }
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 30);
  EXPECT_EQ(model(0), Edge(10, 11));
  EXPECT_EQ(model(1), Edge(10, 11));
  EXPECT_EQ(model(2), Edge(10, 11));
  EXPECT_EQ(model(3), Edge(11, 12));
  EXPECT_EQ(model(10), Edge(13, 14));
  EXPECT_EQ(model(11), Edge(13, 14));
  EXPECT_EQ(model(12), Edge(14, 15));
  EXPECT_EQ(model(15), Edge(15, 16));
  EXPECT_EQ(model(20), Edge(16, 17));
  EXPECT_EQ(model(21), Edge(17, 18));
  EXPECT_EQ(model(22), Edge(17, 18));
  EXPECT_EQ(model(23), Edge(17, 18));
  EXPECT_THROW(model(30), std::out_of_range);

  model.AddSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 40);
  EXPECT_EQ(model(0), Edge(10, 11));
  EXPECT_EQ(model(1), Edge(10, 11));
  EXPECT_EQ(model(2), Edge(10, 11));
  EXPECT_EQ(model(3), Edge(11, 12));
  EXPECT_EQ(model(10), Edge(13, 14));
  EXPECT_EQ(model(11), Edge(13, 14));
  EXPECT_EQ(model(12), Edge(14, 15));
  EXPECT_EQ(model(15), Edge(15, 16));
  EXPECT_EQ(model(20), Edge(16, 17));
  EXPECT_EQ(model(21), Edge(17, 18));
  EXPECT_EQ(model(22), Edge(17, 18));
  EXPECT_EQ(model(23), Edge(17, 18));
  EXPECT_EQ(model(30), Edge(0, 0));
  EXPECT_EQ(model(31), Edge(1, 1));
  EXPECT_EQ(model(32), Edge(2, 2));
  EXPECT_EQ(model(33), Edge(3, 3));
  EXPECT_EQ(model(39), Edge(9, 9));
  EXPECT_THROW(model(40), std::out_of_range);

  model.ManageEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 21);
  EXPECT_EQ(model.GetEdgesAmount(), 20);
  EXPECT_EQ(model(0), Edge(0, 0));
  EXPECT_EQ(model(1), Edge(1, 1));
  EXPECT_EQ(model(2), Edge(2, 2));
  EXPECT_EQ(model(3), Edge(3, 3));
  EXPECT_EQ(model(10), Edge(10, 11));
  EXPECT_EQ(model(11), Edge(11, 12));
  EXPECT_EQ(model(12), Edge(12, 13));
  EXPECT_EQ(model(15), Edge(15, 16));
  EXPECT_THROW(model(20), std::out_of_range);
  EXPECT_THROW(model(21), std::out_of_range);
  EXPECT_THROW(model(22), std::out_of_range);
  EXPECT_THROW(model(23), std::out_of_range);
  EXPECT_THROW(model(30), std::out_of_range);
  EXPECT_THROW(model(31), std::out_of_range);
  EXPECT_THROW(model(32), std::out_of_range);
  EXPECT_THROW(model(33), std::out_of_range);
  EXPECT_THROW(model(40), std::out_of_range);
}

TEST(Model_Model3D, Model3D_ManageEdges_3) {
  using Model3D = inbound_model::Model3D;

  Model3D model;

  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_THROW(model(0), std::out_of_range);
  EXPECT_THROW(model(1), std::out_of_range);
  EXPECT_THROW(model[0], std::out_of_range);
  EXPECT_THROW(model[1], std::out_of_range);

  model.ManageEdges();
  model.ManageEdges();
  model.ManageEdges();
  model.ManageEdges();
  model.ManageEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 0);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_THROW(model(0), std::out_of_range);
  EXPECT_THROW(model(1), std::out_of_range);
  EXPECT_THROW(model[0], std::out_of_range);
  EXPECT_THROW(model[1], std::out_of_range);

  model.AddVert(1, 2, 3);
  model.ManageEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model.GetEdgesAmount(), 0);
  EXPECT_THROW(model(0), std::out_of_range);
  EXPECT_THROW(model(1), std::out_of_range);
  EXPECT_DOUBLE_EQ(model[0].x, 1);
  EXPECT_DOUBLE_EQ(model[0].y, 2);
  EXPECT_DOUBLE_EQ(model[0].z, 3);
  EXPECT_THROW(model[1], std::out_of_range);

  model.AddSingleVertEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model.GetEdgesAmount(), 1);
  EXPECT_EQ(model(0).begin, 0);
  EXPECT_EQ(model(0).end, 0);
  EXPECT_THROW(model(1), std::out_of_range);
  EXPECT_DOUBLE_EQ(model[0].x, 1);
  EXPECT_DOUBLE_EQ(model[0].y, 2);
  EXPECT_DOUBLE_EQ(model[0].z, 3);
  EXPECT_THROW(model[1], std::out_of_range);
  model.ManageEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 1);

  EXPECT_EQ(model.GetEdgesAmount(), 1);
  EXPECT_EQ(model(0).begin, 0);
  EXPECT_EQ(model(0).end, 0);
  EXPECT_THROW(model(1), std::out_of_range);
  EXPECT_DOUBLE_EQ(model[0].x, 1);
  EXPECT_DOUBLE_EQ(model[0].y, 2);
  EXPECT_DOUBLE_EQ(model[0].z, 3);
  EXPECT_THROW(model[1], std::out_of_range);

  model.AddEdge(0, 0);
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model.GetEdgesAmount(), 2);
  EXPECT_EQ(model(0).begin, 0);
  EXPECT_EQ(model(0).end, 0);
  EXPECT_EQ(model(1).begin, 0);
  EXPECT_EQ(model(1).end, 0);
  EXPECT_DOUBLE_EQ(model[0].x, 1);
  EXPECT_DOUBLE_EQ(model[0].y, 2);
  EXPECT_DOUBLE_EQ(model[0].z, 3);
  EXPECT_THROW(model[1], std::out_of_range);

  model.ManageEdges();
  EXPECT_EQ(model.GetVerticesAmount(), 1);
  EXPECT_EQ(model.GetEdgesAmount(), 1);
  EXPECT_EQ(model(0).begin, 0);
  EXPECT_EQ(model(0).end, 0);
  EXPECT_THROW(model(1), std::out_of_range);
  EXPECT_DOUBLE_EQ(model[0].x, 1);
  EXPECT_DOUBLE_EQ(model[0].y, 2);
  EXPECT_DOUBLE_EQ(model[0].z, 3);
  EXPECT_THROW(model[1], std::out_of_range);
}

TEST(Model_Model3D, Model3D_CenterScale_UnscaleUncenter) {
  using vectors::Vec3;

  inbound_model::Model3D model;
  for (int i = 0; i < 21; i++) {
    model.AddVert(i + 10, i - 20, i - 10);
  }
  EXPECT_EQ(model.GetVerticesAmount(), 21);

  model.CenterScale();
  EXPECT_EQ(model.GetCenteringVector(), Vec3(-20, 10, 0));
  EXPECT_DOUBLE_EQ(model.GetScaleFactor(), 0.1);

  for (int i = 0; i < 21; i++) {
    EXPECT_LE(model[i].x, 1);
    EXPECT_LE(model[i].y, 1);
    EXPECT_LE(model[i].z, 1);
  }
  model.UnscaleUncenter();
  for (int i = 0; i < 21; i++) {
    EXPECT_DOUBLE_EQ(model[i].x, i + 10);
    EXPECT_DOUBLE_EQ(model[i].y, i - 20);
    EXPECT_DOUBLE_EQ(model[i].z, i - 10);
    // EXPECT_EQ(model[i], Vec3(i+10,i-20,i-10)); //does not work due to double
  }
}