# File: roottest/python/function/PyROOT_functiontests.py
# Author: Wim Lavrijsen (LBNL, WLavrijsen@lbl.gov)
# Created: 11/24/04
# Last: 05/10/06

"""Unit tests for PyROOT python/TF1 function interactions."""

import os, sys, unittest
from math import exp
from ROOT import *

__all__ = [
   'CallFunctionTestCase',
   'FitFunctionTestCase',
   'GlobalCppFunctionTestCase'
]


### helpers ------------------------------------------------------------------
def identity( x ):
   return x[0]

class Linear:
   def __call__( self, x, par ):
      return par[0] + x[0]*par[1]

def pygaus( x, par ):
    arg1 = 0
    arg2 =0
    scale1 =0
    scale2 =0
    ddx = 0.01

    if (par[2] != 0.0):
        arg1 = (x[0]-par[1])/par[2]
        arg2 = (x[0]-par[1]-0.045)/par[2]
        scale1 = (ddx*0.39894228)/par[2]
        h1 = par[0]/(1+par[3])
        h2 = h1*par[3]

        gauss = h1*scale1*exp(-0.5*arg1*arg1) + h2*scale1*exp(-0.5*arg2*arg2)
    else:
        gauss = 0.
    return gauss


### basic function test cases ================================================
class CallFunctionTestCase( unittest.TestCase ):
   def test1GlobalFunction( self ):
      """Test calling of a python global function"""

      f = TF1( "pyf1", identity, -1., 1., 0 )

      self.assertEqual( f.Eval(  0.5 ),   0.5 )
      self.assertEqual( f.Eval( -10. ), -10.  )
      self.assertEqual( f.Eval(  1.  ),   1.  )

    # check proper propagation of default value
      f = TF1( "pyf1d", identity, -1., 1. )

      self.assertEqual( f.Eval(  0.5 ),   0.5 )

   def test2CallableObject( self ):
      """Test calling of a python callable object"""

      f = TF1( "pyf2", Linear(), -1., 1., 2 )
      f.SetParameters( 5., 2. )

      self.assertEqual( f.Eval( -0.1 ), 4.8 )
      self.assertEqual( f.Eval(  1.3 ), 7.6 )


### fitting with functions ===================================================
class FitFunctionTestCase( unittest.TestCase ):
   def test1FitGaussian( self ):
      """Test fitting with a python global function"""

      f = TF1( 'pygaus', pygaus, -4, 4, 4 )
      f.SetParameters( 600, 0.43, 0.35, 600 )

      h = TH1F( "h"," test", 100, -4, 4 )
      h.FillRandom( "gaus", 200000 )
      h.Fit( f, "0Q" )

      self.assertEqual( f.GetNDF(), 96 )
      result = f.GetParameters()
      self.assertEqual( round( result[1] - 0., 0), 0 )  # mean
      self.assertEqual( round( result[2] - 1., 1), 0 )  # s.d.


### calling a global function ================================================
class GlobalCppFunctionTestCase( unittest.TestCase ):
   def test1CallGlobalCppFunction( self ):
      """Test calling of a C++ global function."""

      gROOT.LoadMacro( "GlobalFunction.C" )

      self.assertEqual( round( Divide( 4. ) - 4./2., 8), 0 )
      self.assertEqual( round( Divide( 7. ) - 7./2., 8), 0 )


## actual test run
if __name__ == '__main__':
   sys.path.append( os.path.join( os.getcwd(), os.pardir ) )
   from MyTextTestRunner import MyTextTestRunner

   loader = unittest.TestLoader()
   testSuite = loader.loadTestsFromModule( sys.modules[ __name__ ] )

   runner = MyTextTestRunner( verbosity = 2 )
   result = not runner.run( testSuite ).wasSuccessful()

   sys.exit( result )
