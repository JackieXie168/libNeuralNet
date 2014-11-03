/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   S U M   S Q U A R E D   E R R O R   T E S T   C L A S S                                                    */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/


// Unit testing includes

#include "sum_squared_error_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

SumSquaredErrorTest::SumSquaredErrorTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

SumSquaredErrorTest::~SumSquaredErrorTest(void) 
{
}


// METHODS

void SumSquaredErrorTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   SumSquaredError sse1;

   assert_true(sse1.has_neural_network() == false, LOG);
   assert_true(sse1.has_data_set() == false, LOG);

   // Neural network

   NeuralNetwork nn2;
   SumSquaredError sse2(&nn2);

   assert_true(sse2.has_neural_network() == true, LOG);
   assert_true(sse2.has_data_set() == false, LOG);

   // Neural network and data set

   NeuralNetwork nn3;
   DataSet ds3;
   SumSquaredError sse3(&nn3, &ds3);

   assert_true(sse3.has_neural_network() == true, LOG);
   assert_true(sse3.has_data_set() == true, LOG);
}


void SumSquaredErrorTest::test_destructor(void)
{
   message += "test_destructor\n";
}


void SumSquaredErrorTest::test_calculate_performance(void)   
{
   message += "test_calculate_performance\n";

   NeuralNetwork nn;
   Vector<double> parameters;

   DataSet ds;
   Matrix<double> data;

   SumSquaredError sse(&nn, &ds);

   double performance;

   // Test

   nn.set(1, 1);
   nn.initialize_parameters(0.0);

   ds.set(1, 1, 1);
   ds.initialize_data(0.0);

   performance = sse.calculate_performance();

   assert_true(performance == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);
   nn.initialize_parameters(0.0);

   ds.set(1, 1, 1);
   ds.initialize_data(1.0);

   performance = sse.calculate_performance();

   assert_true(performance == 1.0, LOG);

   // Test

   nn.set(1, 1);
   nn.randomize_parameters_normal();

   parameters = nn.arrange_parameters();

   ds.set(1, 1, 1);
   ds.randomize_data_normal();

   assert_true(sse.calculate_performance() == sse.calculate_performance(parameters), LOG);

   // Test

   nn.set(1, 1);
   nn.randomize_parameters_normal();

   parameters = nn.arrange_parameters();

   ds.set(1, 1, 1);
   ds.randomize_data_normal();

   assert_true(sse.calculate_performance() != sse.calculate_performance(parameters*2.0), LOG);

}


void SumSquaredErrorTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;
   DataSet ds;
   NeuralNetwork nn;
   SumSquaredError sse(&nn, &ds);

   Vector<unsigned> architecture;

   Vector<double> parameters;
   Vector<double> gradient;
   Vector<double> numerical_gradient;
   Vector<double> error;

   // Test 

   nn.set(1, 1, 1);
   nn.initialize_parameters(0.0);

   ds.set(1, 1, 1);
   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   ds.set(3, 2, 5);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 5;
   architecture[1] = 1;
   architecture[2] = 2;

   nn.set(architecture);
   nn.initialize_parameters(0.0);

   ds.set(5, 2, 1);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);

   nn.initialize_parameters(0.0);

   ds.set(1, 1, 1);

   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   ds.set(3, 2, 5);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   nn.set(2, 3, 4);
   nn.initialize_parameters(0.0);

   ds.set(2, 4, 5);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   ds.initialize_data(1.0);

   nn.initialize_parameters(1.0);
   parameters = nn.arrange_parameters();

   gradient = sse.calculate_gradient();
   numerical_gradient = nd.calculate_gradient(sse, &SumSquaredError::calculate_performance, parameters);
   error = (gradient - numerical_gradient).calculate_absolute_value();
   assert_true(error < 1.0e-3, LOG);

   // Test

   nn.set(1, 1, 1);
   nn.initialize_parameters(1.0);
   parameters = nn.arrange_parameters();

   ds.set(1, 1, 1);

   ds.initialize_data(1.0);

   gradient = sse.calculate_gradient();
   numerical_gradient = nd.calculate_gradient(sse, &SumSquaredError::calculate_performance, parameters);
   assert_true((gradient - numerical_gradient).calculate_absolute_value() < 1.0e-3, LOG);

}


// @todo

void SumSquaredErrorTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";
/*
   NumericalDifferentiation nd;
   DataSet ds;
   NeuralNetwork nn;
   SumSquaredError sse(&nn, &ds);

   Vector<double> parameters;
   Matrix<double> Hessian;
   Matrix<double> numerical_Hessian;

   // Test 

   nn.set();
   nn.construct_multilayer_perceptron();

   ds.set();

   Hessian = sse.calculate_Hessian();
   
   assert_true(Hessian.get_rows_number() == 0, LOG);
   assert_true(Hessian.get_columns_number() == 0, LOG);

   // Test

   ds.set(1, 1, 1);
   ds.randomize_data_normal();

   nn.set(1,1),

   nn.randomize_parameters_normal();
   parameters = nn.arrange_parameters();

   Hessian = sse.calculate_Hessian();
   numerical_Hessian = nd.calculate_Hessian(sse, &SumSquaredError::calculate_performance, parameters);
//   assert_true((Hessian - numerical_Hessian).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   ds.set(2, 1, 1);
   ds.randomize_data_normal();

   nn.set(2,1),
   nn.randomize_parameters_normal();
   parameters = nn.arrange_parameters();

   Hessian = sse.calculate_Hessian();
   numerical_Hessian = nd.calculate_Hessian(sse, &SumSquaredError::calculate_performance, parameters);
//   assert_true((Hessian - numerical_Hessian).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   ds.set(1, 2, 1);
   ds.randomize_data_normal();

   nn.set(1,2),
   nn.randomize_parameters_normal();
   parameters = nn.arrange_parameters();

   Hessian = sse.calculate_Hessian();
   numerical_Hessian = nd.calculate_Hessian(sse, &SumSquaredError::calculate_performance, parameters);
//   assert_true((objective_Hessian - numerical_objective_Hessian).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   ds.set(2, 2, 1);
   ds.randomize_data_normal();

   nn.set(2, 2);
   nn.randomize_parameters_normal();
   parameters = nn.arrange_parameters();

   Hessian = sse.calculate_Hessian();
   numerical_Hessian = nd.calculate_Hessian(sse, &SumSquaredError::calculate_performance, parameters);
//   assert_true((objective_Hessian - numerical_objective_Hessian).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   ds.set(1, 1, 1);
   ds.randomize_data_normal();

   nn.set(1, 1, 1);
   nn.randomize_parameters_normal();
   parameters = nn.arrange_parameters();

   Hessian = sse.calculate_Hessian();
   numerical_Hessian = nd.calculate_Hessian(sse, &SumSquaredError::calculate_performance, parameters);
//   assert_true((objective_Hessian - numerical_objective_Hessian).calculate_absolute_value() < 1.0e-3, LOG);
*/
}


void SumSquaredErrorTest::test_calculate_performance_terms(void)
{
   message += "test_calculate_performance_terms\n";
}


void SumSquaredErrorTest::test_calculate_Jacobian_terms(void)
{   
   message += "test_calculate_Jacobian_terms\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;
   Vector<unsigned> architecture;
   Vector<double> parameters;

   DataSet ds;

   SumSquaredError sse(&nn, &ds);

   Vector<double> gradient;

   Vector<double> terms;
   Matrix<double> terms_Jacobian;
   Matrix<double> numerical_Jacobian_terms;

   // Test

   nn.set(1, 1);

   nn.initialize_parameters(0.0);

   ds.set(1, 1, 1);

   ds.initialize_data(0.0);

   terms_Jacobian = sse.calculate_terms_Jacobian();

   assert_true(terms_Jacobian.get_rows_number() == ds.get_instances().get_instances_number(), LOG);
   assert_true(terms_Jacobian.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(terms_Jacobian == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   ds.set(3, 2, 5);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   terms_Jacobian = sse.calculate_terms_Jacobian();

   assert_true(terms_Jacobian.get_rows_number() == ds.get_instances().count_training_instances_number(), LOG);
   assert_true(terms_Jacobian.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(terms_Jacobian == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 5;
   architecture[1] = 1;
   architecture[2] = 2;

   nn.set(architecture);
   nn.initialize_parameters(0.0);

   ds.set(5, 2, 3);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   terms_Jacobian = sse.calculate_terms_Jacobian();

   assert_true(terms_Jacobian.get_rows_number() == ds.get_instances().get_instances_number(), LOG);
   assert_true(terms_Jacobian.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(terms_Jacobian == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);
   nn.randomize_parameters_normal();
   parameters = nn.arrange_parameters();

   ds.set(1, 1, 1);
   ds.randomize_data_normal();

   terms_Jacobian = sse.calculate_terms_Jacobian();
   numerical_Jacobian_terms = nd.calculate_Jacobian(sse, &SumSquaredError::calculate_terms, parameters);

   assert_true((terms_Jacobian-numerical_Jacobian_terms).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   nn.set(2, 2, 2);
   nn.randomize_parameters_normal();
   parameters = nn.arrange_parameters();

   ds.set(2, 2, 2);
   ds.randomize_data_normal();

   terms_Jacobian = sse.calculate_terms_Jacobian();
   numerical_Jacobian_terms = nd.calculate_Jacobian(sse, &SumSquaredError::calculate_terms, parameters);

   assert_true((terms_Jacobian-numerical_Jacobian_terms).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   nn.set(2, 2, 2);
   nn.randomize_parameters_normal();

   ds.set(2, 2, 2);
   ds.randomize_data_normal();
   
   gradient = sse.calculate_gradient();

   terms = sse.calculate_terms();
   terms_Jacobian = sse.calculate_terms_Jacobian();

   assert_true(((terms_Jacobian.calculate_transpose()).dot(terms)*2.0 - gradient).calculate_absolute_value() < 1.0e-3, LOG);
}


void SumSquaredErrorTest::test_calculate_generalization_performance(void)
{
   message += "test_calculate_generalization_performance\n";

   NeuralNetwork nn;
   DataSet ds;
   SumSquaredError sse(&nn, &ds);

   double generalization_objective;

   // Test

   nn.set();

   nn.construct_multilayer_perceptron();

   ds.set();

   generalization_objective = sse.calculate_generalization_performance();
   
   assert_true(generalization_objective == 0.0, LOG);

}


void SumSquaredErrorTest::test_calculate_squared_errors(void)
{
   message += "test_calculate_squared_errors\n";

   NeuralNetwork nn;

   DataSet ds;

   SumSquaredError sse(&nn, &ds);

   Vector<double> squared_errors;

   double objective;

   // Test 

   nn.set(1,1,1);

   nn.initialize_parameters(0.0);

   ds.set(1,1,1);

   ds.initialize_data(0.0);

   squared_errors = sse.calculate_squared_errors();

   assert_true(squared_errors.size() == 1, LOG);
   assert_true(squared_errors == 0.0, LOG);   

   // Test

   nn.set(2,2,2);

   nn.randomize_parameters_normal();

   ds.set(2,2,2);

   ds.randomize_data_normal();

   squared_errors = sse.calculate_squared_errors();

   objective = sse.calculate_performance();

   assert_true(fabs(squared_errors.calculate_sum() - objective) < 1.0e-12, LOG);

}


void SumSquaredErrorTest::test_to_XML(void)   
{
    message += "test_to_XML\n";

    SumSquaredError sse;

    tinyxml2::XMLDocument* document;

    // Test

    document = sse.to_XML();

    assert_true(document != NULL, LOG);

    delete document;
}


void SumSquaredErrorTest::test_from_XML(void)
{
    message += "test_from_XML\n";

    SumSquaredError sse1;
    SumSquaredError sse2;

   tinyxml2::XMLDocument* document;

   // Test

   sse1.set_display(false);

   document = sse1.to_XML();

   sse2.from_XML(*document);

   delete document;

   assert_true(sse2.get_display() == false, LOG);
}


void SumSquaredErrorTest::run_test_case(void)
{
   message += "Running sum squared error test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   // Set methods

   // Objective methods

   test_calculate_performance();   
   test_calculate_generalization_performance();

   test_calculate_gradient();

   test_calculate_Hessian();

   // Objective terms methods

   test_calculate_performance_terms();

   test_calculate_Jacobian_terms();

   // Serialization methods

   test_to_XML();   
   test_from_XML();

   message += "End of sum squared error test case.\n";
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
