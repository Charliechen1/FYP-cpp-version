#include "hypergraph.h" 
#define RANDOMNESS 30

bool Hypergraph::constructHMat(string filename, bool labelFront){
  Mat<int> dataset; 
  // data preprocessing, preprocess the categorical data to int category
  data::DatasetInfo info; 
  data::Load(filename, dataset, info, true);
  
  data::Save("log/dataset.txt", dataset);
  Mat<int> oriLabel, oriFeature;
  // split the labels and features. They will be separately one-hot encoded. 
  if (labelFront){
    oriLabel = dataset(0, span::all);
    oriFeature = dataset(span(1, dataset.n_rows-1), span::all);
  }else{
    oriLabel = dataset(dataset.n_rows-1, span::all);
    oriFeature = dataset(span(0, dataset.n_rows-2), span::all);
  }
  // doing one hot encoding separately on label matrix and feature matrix and shuffle the matrices
  hMat = oneHotEncoding(oriFeature);
  lMat = oneHotEncoding(oriLabel);
  tail = hMat; head = hMat; 
  weight = ones<Row<double>>(hMat.n_rows);
  shuffleMat(RANDOMNESS);
  return true;
}

Mat<unsigned int> Hypergraph::oneHotEncoding(Mat<int> oriData){
  int r = oriData.n_rows;
  int c = oriData.n_cols;
  int coun = 0;
  Mat<unsigned int> resData;
  
  // find out in total how many choices of features there are
  for (int i=0; i<r; i++){
    Row<int> r_i = oriData.row(i);
    coun += r_i.max()+1;
  }
  resData = zeros<Mat<unsigned int>>(coun, c); // initialize the matrix to all 0

  coun = 0;
  for (int i=0; i<r; i++){
    Row<int> r_i = oriData.row(i);
    for (int j=0; j<c; j++){
      resData(coun + oriData(i, j), j) = 1; // set the corresponding entry of resData to be 1 according to value of oriData(i, j)
    }
    coun += r_i.max()+1;  // add the number of choices for feature i to coun 
  }
  return resData;
}

void Hypergraph::shuffleMat(int time_to_shuffle){
  // shuffle the data for randomness, truer randomness will be generated with higher RANDOMNESS value
  srand (time(NULL));

  int r = rand() % time_to_shuffle;
  int hrow = hMat.n_rows; 
  int hcol = hMat.n_cols;
  int lrow = lMat.n_rows; 
  int lcol = lMat.n_cols;

  Mat<unsigned int> candidate = join_vert(join_vert(lMat, hMat), join_vert(head, tail));
  mlpack::data::Save("log/candidate.txt", candidate);

  for (int i=0; i<r; i++){
    candidate = shuffle(candidate, 1);
  }
  
  // split the candidate matrix  
  lMat = candidate(span(0, lrow-1), span::all);
  hMat = candidate(span(lrow, lrow + hrow - 1), span::all);
  head = candidate(span(lrow + hrow, lrow + 2 * hrow - 1), span::all);
  tail = candidate(span(lrow + 2 * hrow, lrow + 3 * hrow - 1), span::all);
}
