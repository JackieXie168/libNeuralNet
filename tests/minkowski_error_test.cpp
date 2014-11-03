/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   M I N K O W S K I   E R R O R   T E S T   C L A S S                                                        */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

#include "minkowski_error_test.h"

using namespace OpenNN;

// GENERAL CONSTRUCTOR

MinkowskiErrorTest::MinkowskiErrorTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

MinkowskiErrorTest::~MinkowskiErrorTest(void) 
{
}


// METHODS


void MinkowskiErrorTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   MinkowskiError me1;

   assert_true(me1.has_neural_network() == false, LOG);
   assert_true(me1.has_data_set() == false, LOG);

   // Neural network

   NeuralNetwork nn2;
   MinkowskiError me2(&nn2);

   assert_true(me2.has_neural_network() == true, LOG);
   assert_true(me2.has_data_set() == false, LOG);

   // Neural network and data set

   NeuralNetwork nn3;
   DataSet ds3;
   MinkowskiError me3(&nn3, &ds3);

   assert_true(me3.has_neural_network() == true, LOG);
   assert_true(me3.has_data_set() == true, LOG);

}


void MinkowskiErrorTest::test_destructor(void)
{
   message += "test_destructor\n";
}


void MinkowskiErrorTest::test_get_Minkowski_parameter(void)
{
   message += "test_get_Minkowski_parameter\n";

   MinkowskiError me;

   me.set_Minkowski_parameter(1.0);
   
   assert_true(me.get_Minkowski_parameter() == 1.0, LOG);
}


void MinkowskiErrorTest::test_set_Minkowski_parameter(void)
{
   message += "test_set_Minkowski_parameter\n";
}


void MinkowskiErrorTest::test_calculate_performance(void)
{
   message += "test_calculate_performance\n";

   Vector<double> parameters;

   NeuralNetwork nn(1,1,1);
   nn.initialize_parameters(0.0);

   DataSet ds(1,1,1);
   ds.initialize_data(0.0);

   MinkowskiError me(&nn, &ds);

   assert_true(me.calculate_performance() == 0.0, LOG);

   // Test

   nn.set(1, 1);
   nn.randomize_parameters_normal();

   parameters = nn.arrange_parameters();

   ds.set(1, 1, 2);
   ds.randomize_data_normal();

   assert_true(me.calculate_performance() == me.calculate_performance(parameters), LOG);     

//   std::cout << me.calculate_performance() << std::endl;
//   std::cout << me.calculate_performance(parameters) << std::endl;
}


void MinkowskiErrorTest::test_calculate_generalization_performance(void)
{
   message += "test_calculate_generalization_performance\n";  
}


void MinkowskiErrorTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;
   Vector<unsigned> architecture;

   Vector<double> parameters;

   DataSet ds;

   MinkowskiError me(&nn, &ds);

   Vector<double> gradient;
   Vector<double> numerical_gradient;

   // Test

   nn.set(1,1,1);

   nn.initialize_parameters(0.0);

   ds.set(1,1,1);

   ds.initialize_data(0.0);

   gradient = me.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3,4,2);
   nn.initialize_parameters(0.0);

   ds.set(3, 2, 5);
   me.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = me.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 2;
   architecture[1] = 1;
   architecture[2] = 3;

   nn.set(architecture);
   nn.initialize_parameters(0.0);

   ds.set(2, 3, 5);
   me.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = me.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   nn.set(1,1,1);

   nn.initialize_parameters(0.0);

   ds.set(1,1,1);

   ds.initialize_data(0.0);

   gradient = me.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3,4,2);
   nn.initialize_parameters(0.0);

   ds.set(3,2,5);
   me.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = me.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 2;
   architecture[1] = 1;
   architecture[2] = 2;

   nn.set(architecture);
   nn.initialize_parameters(0.0);

   ds.set(2,2,3);
   me.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = me.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   architecture.set(4, 1);

   nn.set(architecture);
   nn.randomize_parameters_normal();

   parameters = nn.arrange_parameters();

   ds.set(1,1,1);
   ds.randomize_data_normal();

   gradient = me.calculate_gradient();
   numerical_gradient = nd.calculate_gradient(me, &MinkowskiError::calculate_performance, parameters);

   assert_true((gradient - numerical_gradient).calculate_absolute_value() < 1.0e-3, LOG);

   // Test 

   nn.set(5,4,3);
   nn.randomize_parameters_normal();

   parameters = nn.arrange_parameters();

   ds.set(5,3,2);
   ds.randomize_data_normal();

   me.set_Minkowski_parameter(1.75);

   gradient = me.calculate_gradient();
   numerical_gradient = nd.calculate_gradient(me, &MinkowskiError::calculate_performance, parameters);
   assert_true((gradient - numerical_gradient).calculate_absolute_value() < 1.0e-3, LOG);

}


void MinkowskiErrorTest::test_to_XML(void)   
{
   message += "test_to_XML\n";  

   MinkowskiError me;

   tinyxml2::XMLDocument* document;

   // Test

   document = me.to_XML();

   assert_true(document != NULL, LOG);

   delete document;

}


void MinkowskiErrorTest::test_from_XML(void)   
{
   message += "test_from_XML\n";

   MinkowskiError me1;
   MinkowskiError me2;

  tinyxml2::XMLDocument* document;

  // Test

  me1.set_Minkowski_parameter(1.33);
  me1.set_display(false);

  document = me1.to_XML();

  me2.from_XML(*document);

  delete document;

  assert_true(me2.get_Minkowski_parameter() == 1.33, LOG);
  assert_true(me2.get_display() == false, LOG);
}


void MinkowskiErrorTest::run_test_case(void)
{
   message += "Running Minkowski error test case...\n";  

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_Minkowski_parameter();

   // Set methods

   test_set_Minkowski_parameter();

   // Objective methods

   test_calculate_performance();   
   test_calculate_generalization_performance();
   test_calculate_gradient();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of Minkowski error test case.\n";
}


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
