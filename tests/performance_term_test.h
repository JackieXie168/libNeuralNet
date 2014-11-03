/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   P E R F O R M A N C E   T E R M   T E S T   C L A S S   H E A D E R                                        */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __PERFORMANCETERMTEST_H__
#define __PERFORMANCETERMTEST_H__

// Unit testing includes

#include "unit_testing.h"

using namespace OpenNN;


class PerformanceTermTest : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit PerformanceTermTest(void);


   // DESTRUCTOR

   virtual ~PerformanceTermTest(void);


   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Operators

   void test_assingment_operator(void);
   void test_equal_to_operator(void);

   // Get methods

   void test_get_neural_network_pointer(void);

   void test_get_mathematical_model_pointer(void);
   void test_get_data_set_pointer(void);

   void test_get_numerical_differentiation_pointer(void);

   // Serialization methods

   void test_get_display(void);

   // Set methods

   void test_set_neural_network_pointer(void);

   void test_set_mathematical_model_pointer(void);
   void test_set_data_set_pointer(void);

   void test_set_numerical_differentiation_pointer(void);
   
   void test_set_default(void);

   // Serialization methods

   void test_set_display(void);

   // delta methods

   void test_calculate_layers_delta(void);
   void test_calculate_interlayers_Delta(void);

   // Point objective function methods

   void test_calculate_point_objective(void);
   void test_calculate_point_gradient(void);
   void test_calculate_point_Hessian(void);

   // Objective methods

   void test_calculate_performance(void);

   void test_calculate_generalization_performance(void);   

   void test_calculate_gradient(void); 
   void test_calculate_Hessian(void); 

   void test_calculate_terms(void);
   void test_calculate_terms_Jacobian(void);


   // Serialization methods

   void test_to_XML(void);   
   void test_from_XML(void);   

   void test_write_information(void);

   // Unit testing methods

   void run_test_case(void);

};


#endif


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2014 Roberto Lopez
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
