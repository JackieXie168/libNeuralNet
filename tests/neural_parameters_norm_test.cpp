/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   N E U R A L   P A R A M E T E R S   N O R M   T E R M   C L A S S                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

#include "neural_parameters_norm_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

NeuralParametersNormTest::NeuralParametersNormTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

NeuralParametersNormTest::~NeuralParametersNormTest(void) 
{
}


// METHODS

void NeuralParametersNormTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   NeuralParametersNorm npn1;

   assert_true(npn1.has_neural_network() == false, LOG);

   // Neural network 

   NeuralNetwork nn;
   NeuralParametersNorm npn2(&nn);

   assert_true(npn2.has_neural_network() == true, LOG);
}


void NeuralParametersNormTest::test_destructor(void)
{
   message += "test_destructor\n";
}


void NeuralParametersNormTest::test_calculate_performance(void)   
{
   message += "test_calculate_performance\n";

   NeuralNetwork nn;
   Vector<double> neural_parameters;

   NeuralParametersNorm npn(&nn);

   Vector<double> parameters;

   double performance;

   // Test

   nn.set(1, 1);
   nn.initialize_parameters(0.0);

   performance = npn.calculate_performance();

   assert_true(performance == 0.0, LOG);

   // Test

   nn.set(1, 1);
   nn.initialize_parameters(3.1415927);

   parameters = nn.arrange_parameters();

   assert_true(npn.calculate_performance() == npn.calculate_performance(parameters), LOG);
}

/*
void NeuralParametersNormTest::test_calculate_generalization_performance(void)
{
   message += "test_calculate_generalization_performance\n";

   NeuralNetwork nn;

   NeuralParametersNorm npn(&nn);

   double generalization_performance;

   // Test

   nn.set(1, 1);

   nn.initialize_parameters(0.0);

   generalization_performance = npn.calculate_generalization_performance();
   
   assert_true(generalization_performance == 0.0, LOG);
}
*/

void NeuralParametersNormTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;
   NeuralNetwork nn;
   NeuralParametersNorm npn(&nn);

   Vector<unsigned> architecture;

   Vector<double> parameters;
   Vector<double> gradient;
   Vector<double> numerical_gradient;
   Vector<double> error;

   // Test 

   nn.set(1, 1, 1);
   nn.initialize_parameters(0.0);

   gradient = npn.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   gradient = npn.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 5;
   architecture[1] = 1;
   architecture[2] = 2;

   nn.set(architecture);
   nn.initialize_parameters(0.0);

   npn.set_neural_network_pointer(&nn);

   gradient = npn.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   npn.set_neural_network_pointer(&nn);

   gradient = npn.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);


   // Test

   nn.initialize_parameters(1.0);
   parameters = nn.arrange_parameters();

   gradient = npn.calculate_gradient();
   numerical_gradient = nd.calculate_gradient(npn, &NeuralParametersNorm::calculate_performance, parameters);
   error = (gradient - numerical_gradient).calculate_absolute_value();

   assert_true(error < 1.0e-3, LOG);
}


// @todo

void NeuralParametersNormTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";

   NumericalDifferentiation nd;
   NeuralNetwork nn;
   NeuralParametersNorm npn(&nn);

   Vector<unsigned> architecture;

   Vector<double> parameters;
   Matrix<double> Hessian;
   Matrix<double> numerical_Hessian;
   Matrix<double> error;

   // Test

   nn.set(1, 1, 1);
   nn.initialize_parameters(0.0);

   Hessian = npn.calculate_Hessian();

   assert_true(Hessian.get_rows_number() == nn.count_parameters_number(), LOG);
   assert_true(Hessian.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(Hessian == 0.0, LOG);

   // Test

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   Hessian = npn.calculate_Hessian();

   assert_true(Hessian.get_rows_number() == nn.count_parameters_number(), LOG);
   assert_true(Hessian.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(Hessian == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 5;
   architecture[1] = 1;
   architecture[2] = 2;

   nn.set(architecture);
   nn.initialize_parameters(0.0);

   npn.set_neural_network_pointer(&nn);

   Hessian = npn.calculate_Hessian();

   assert_true(Hessian.get_rows_number() == nn.count_parameters_number(), LOG);
   assert_true(Hessian.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(Hessian == 0.0, LOG);

   // Test

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   npn.set_neural_network_pointer(&nn);

   Hessian = npn.calculate_Hessian();

   assert_true(Hessian.get_rows_number() == nn.count_parameters_number(), LOG);
   assert_true(Hessian.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(Hessian == 0.0, LOG);

   // Test

//   nn.set(1, 1);

//   nn.randomize_parameters_normal();
//   parameters = nn.arrange_parameters();

//   Hessian = npn.calculate_Hessian();
//   numerical_Hessian = nd.calculate_Hessian(npn, &NeuralParametersNorm::calculate_performance, parameters);
//   error = (Hessian - numerical_Hessian).calculate_absolute_value();

//   std::cout << Hessian << std::endl;
//   std::cout << numerical_Hessian << std::endl;
//   system("pause");

//   assert_true(error < 1.0e-3, LOG);

}


void NeuralParametersNormTest::test_to_XML(void)   
{
	message += "test_to_XML\n"; 

    NeuralParametersNorm npn;

    tinyxml2::XMLDocument* document;

    // Test

    document = npn.to_XML();

    assert_true(document != NULL, LOG);

    delete document;

}


void NeuralParametersNormTest::test_from_XML(void)
{
	message += "test_from_XML\n"; 

    NeuralParametersNorm npn;

   tinyxml2::XMLDocument* document;

   // Test

   npn.set_display(false);

   document = npn.to_XML();

   npn.from_XML(*document);

   delete document;

   assert_true(npn.get_display() == false, LOG);

}


void NeuralParametersNormTest::run_test_case(void)
{
   message += "Running neural parameters norm test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   // Set methods

   // Objective methods

   test_calculate_performance();   
//   test_calculate_generalization_performance();

   test_calculate_gradient();

   test_calculate_Hessian();

   // Serialization methods

   test_to_XML();   
   test_from_XML();

   message += "End of neural parameters norm test case.\n";
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
