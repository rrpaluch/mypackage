#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

//' @title simplify2array2(List x) function
//' @description Function simplify2array2() converts a list containing numeric vectors into a matrix.
//'
//' @return A matrix which columns are equivalent with elements of a imput list.
//'
//' @export
// [[Rcpp::export]]
NumericMatrix simplify2array2(List x) {
  int n = x.size();
  // Find the length of vectors
  NumericVector first(x[0]);
  int m = first.size();
  // Create a matrix with zeros
  NumericMatrix A(m,n);
  // Iterate over all elements of the list x
  for(int i=0; i<n; ++i) {
    // Check if the type of vector is correct
    if(!Rf_isNumeric(x[i])) stop("The list contains non-numeric vector!");
    NumericVector elem(x[i]);
    // Check if all vectors have the same length
    if(elem.size()!=m) stop("The list contains vectors of different length!");
    // Add the elements of vectors to the columns of the matrix A
    for(int j=0; j<m; ++j) 
      A(j,i) = elem[j];
  }
  // Prepare the list for names of rows and cols
  List dimlst(2);
  // Leave rows without names
  dimlst[0] = R_NilValue;
  // Take the names of columns from list x
  dimlst[1] = x.names();
  // Assign the dimnames to the matrix A
  A.attr( "dimnames" ) = dimlst;
  return A;
}