#' @title mypackage
#' 
#' @description
#' The package contains two Rcpp functions - mode2 and simplify2array2.
#' Function mode2() calculates a mode for a given integer vector.
#' Function simplify2array2() converts a list containing numeric vectors
#' into a matrix.
#' 
#' @useDynLib mypackage
#' @name mypackage-package
#' @docType package
#' @importFrom Rcpp sourceCpp
invisible(NULL)