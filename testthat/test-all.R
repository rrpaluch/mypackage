library(testthat)
library(mypackage)

# Tests of mode2() function
expect_is( mode2(1), "integer")
expect_is( mode2(c(1,3,2,1,5,5,1,6)), "integer")
expect_is( mode2(c(1L,3L,2L,1L,5L,5L,1L,6L)), "integer")
expect_equal( mode2(c(1,3,2,1,5,5,1,6)), 1)
expect_equal( mode2(c(-1,0,1,0,-2)), 0)
expect_equal( mode2(77L), 77)
expect_error( mode2() )
expect_error( mode2(c("-1","0","1","0","-2")) )
expect_error( mode2(1,3,2,1,1,6) )

# Tests of simplify2array2() function
expect_is( simplify2array2(list(a=c(1,2), b=c(3,4), c=c(5,6))), "matrix")
expect_is( simplify2array2(list(col1=c(1:10), col2=seq(0.0,4.5,0.5))), "matrix")
expect_error( simplify2array2(list(a=c(1,2), b=c(3,4), c=c(5,6,7))) )
expect_error( simplify2array2(list(a=c("1","2"), b=c("3","4"), c=c("5","6"))) )