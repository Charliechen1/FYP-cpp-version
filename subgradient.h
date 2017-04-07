#include <mlpack/core.hpp>
#include <iostream>
#include <armadillo>
#include "hypergraph.h"

#ifndef __SUBGRADIENT_H_INCLUDED
#define __SUBGRADIENT_H_INCLUDED

using namespace arma;
using namespace std;
using namespace mlpack;

class Subgradient{
  public:
    Mat<unsigned int> fitPredict(Hypergraph *hg, int train_size, double precision);
    double accuracy;        

  private:
    mat computeDelta(mat &f, Hypergraph *hg, int train_size);
    mat sgm(mat f, Hypergraph *hg, int train_size, double precision);  
    mat recoverF(Hypergraph* hg, mat &f, int train_size);
    double evalAcc(Mat<unsigned int> target, Mat<unsigned int> prediction);
    //void worker(mat f, Hypergraph *hg, uvec allTailId, uvec allHeadId, int classnum, int edgenum, mat &f_out);
};

#endif
