/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   N U M E R I C A L   D I F F E R E N T I A T I O N   T E S T   C L A S S   H E A D E R                      */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __NUMERICALDIFFERENTIATIONTEST_H__
#define __NUMERICALDIFFERENTIATIONTEST_H__

// OpenNN includes

#include "../unit_testing.h"

using namespace OpenNN;

class NumericalDifferentiationTest : public UnitTesting
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit NumericalDifferentiationTest(void);


   // DESTRUCTOR

   virtual ~NumericalDifferentiationTest(void);

   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Derivative methods

   void test_calculate_forward_differences_derivative(void);
   void test_calculate_central_differences_derivative(void);
   void test_calculate_derivative(void);

//   void test_calculate_forward_differences_derivative(void);
//   void test_calculate_central_differences_derivative(void);
//   void test_calculate_derivative(void);

   // Second derivative methods

   void test_calculate_forward_differences_second_derivative(void);
   void test_calculate_central_differences_second_derivative(void);
   void test_calculate_second_derivative(void);

//   void test_calculate_forward_differences_second_derivative(void);
//   void test_calculate_central_differences_second_derivative(void);
//   void test_calculate_second_derivative(void);

   // Gradient methods

   void test_calculate_forward_differences_gradient(void);
   void test_calculate_central_differences_gradient(void);
   void test_calculate_gradient(void);

   // Hessian methods

   void test_calculate_forward_differences_Hessian(void);
   void test_calculate_central_differences_Hessian(void);
   void test_calculate_Hessian(void);

   // Jacobian methods

   void test_calculate_forward_differences_Jacobian(void);
   void test_calculate_central_differences_Jacobian(void);
   void test_calculate_Jacobian(void);

   // Hessian methods

   void test_calculate_forward_differences_Hessian_form(void);
   void test_calculate_central_differences_Hessian_form(void);
   void test_calculate_Hessian_form(void);

   // Unit testing methods

   void run_test_case(void);

private:

   // Constant methods

   double f1(const double&) const ;
   double f2(const Vector<double>&) const;
   Vector<double> f3(const Vector<double>&) const;

   // Non constant methods

   double f4(const double&);
   double f5(const Vector<double>&);
   Vector<double> f6(const Vector<double>&);


};


#endif


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
