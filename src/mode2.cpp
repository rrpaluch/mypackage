#include <Rcpp.h>
#include <vector>
using namespace Rcpp;
using namespace std;

//' @title mode2(NumericVector x) function
//' @description Function mode2() determines the most frequently occurring value in an integer
//' vector (mode). If the mode is ambiguous (e.g. for 1, 2, 2, 2, 3, 3, 1, 3),
//' function returns any mode.
//'
//' @return An integer value - the mode of the input integer vector x.
//'
//' @export
// [[Rcpp::export]]
int mode2(NumericVector x)
{
  if(!Rf_isNumeric(x)) stop("The input vector must contain only numeric values!");
  // Deep copy the input vector
  NumericVector y = Rcpp::clone(x);
  int n = y.size();   
  // Prepare the vectors for unique integers and counts
  vector<int> v;
  vector<int> c;
  // Reserve some initial space
  v.reserve(10);
  c.reserve(10);
  int flag = 0;
  // Loop over elements in vector y
  for(int i=0; i<n; i++)
  {
    flag = 0;
    // Check if the element from y is already in v,
    // if is, increment the proper element of vector c
    for(int j=0; j<v.size(); j++)
      if(y[i]==v[j])
      {
        flag = 1;
        c[j]++;
      }
    // If the element y[i] is new, add it to the vector v
    if(flag==0)
    {
      v.push_back(y[i]);
      c.push_back(1);
    }
  }
  // Find the element of vector v with maximal counts in vector c
  int c_max = 0;
  int v_max = 0;
  for(int i=0; i<c.size(); i++)
    if(c[i]>c_max)
    {
      c_max = c[i];
      v_max = i;
    }
  return v[v_max];
}