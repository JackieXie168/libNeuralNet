/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   M E A N   S Q U A R E D   E R R O R   T E S T   C L A S S                                                  */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

#include "mean_squared_error_test.h"

using namespace OpenNN;

// GENERAL CONSTRUCTOR

MeanSquaredErrorTest::MeanSquaredErrorTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

MeanSquaredErrorTest::~MeanSquaredErrorTest(void)
{
}


// METHODS


void MeanSquaredErrorTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   MeanSquaredError mse1;

   assert_true(mse1.has_neural_network() == false, LOG);
   assert_true(mse1.has_data_set() == false, LOG);

   // Neural network

   NeuralNetwork nn2;
   MeanSquaredError mse2(&nn2);

   assert_true(mse2.has_neural_network() == true, LOG);
   assert_true(mse2.has_data_set() == false, LOG);

   // Neural network and data set

   NeuralNetwork nn3;
   DataSet ds3;
   MeanSquaredError mse3(&nn3, &ds3);

   assert_true(mse3.has_neural_network() == true, LOG);
   assert_true(mse3.has_data_set() == true, LOG);

}


void MeanSquaredErrorTest::test_destructor(void)
{
}


void MeanSquaredErrorTest::test_calculate_performance(void)   
{
   message += "test_calculate_performance\n";

   Vector<double> parameters;

   NeuralNetwork nn(1, 1, 1);
   nn.initialize_parameters(0.0);

   DataSet ds(1, 1, 1);
   ds.initialize_data(0.0);

   MeanSquaredError mse(&nn, &ds);

   assert_true(mse.calculate_performance() == 0.0, LOG);

   // Test

   nn.set(1, 1);
   nn.randomize_parameters_normal();

   parameters = nn.arrange_parameters();

   ds.set(1, 1, 1);
   ds.randomize_data_normal();

   assert_true(mse.calculate_performance() == mse.calculate_performance(parameters), LOG);

}


void MeanSquaredErrorTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;
   Vector<unsigned> multilayer_perceptron_architecture;

   Vector<double> parameters;

   DataSet ds;

   MeanSquaredError mse(&nn, &ds);

   Vector<double> objective_gradient;
   Vector<double> numerical_objective_gradient;
   Vector<double> numerical_differentiation_error;

   // Test

   nn.set(1, 1, 1);

   nn.initialize_parameters(0.0);

   ds.set(1, 1, 1);

   ds.initialize_data(0.0);

   objective_gradient = mse.calculate_gradient();

   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   ds.set(3, 2, 5);
   mse.set(&nn, &ds);
   ds.initialize_data(0.0);

   objective_gradient = mse.calculate_gradient();

   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test

   multilayer_perceptron_architecture.set(3);
   multilayer_perceptron_architecture[0] = 2;
   multilayer_perceptron_architecture[1] = 1;
   multilayer_perceptron_architecture[2] = 3;

   nn.set(multilayer_perceptron_architecture);
   nn.initialize_parameters(0.0);

   ds.set(2, 3, 5);
   mse.set(&nn, &ds);
   ds.initialize_data(0.0);

   objective_gradient = mse.calculate_gradient();

   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);

   nn.initialize_parameters(0.0);

   ds.set(1, 1, 1);

   ds.initialize_data(0.0);

   objective_gradient = mse.calculate_gradient();

   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   ds.set(3, 2, 5);
   mse.set(&nn, &ds);
   ds.initialize_data(0.0);

   objective_gradient = mse.calculate_gradient();

   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test

   nn.set(1, 1);
   nn.initialize_parameters(1.0);
   parameters = nn.arrange_parameters();

   ds.set(1, 1, 2);
   ds.initialize_data(1.0);

   objective_gradient = mse.calculate_gradient();
   numerical_objective_gradient = nd.calculate_gradient(mse, &MeanSquaredError::calculate_performance, parameters);   
   assert_true((objective_gradient - numerical_objective_gradient).calculate_absolute_value() < 1.0e-3, LOG);
}


void MeanSquaredErrorTest::test_calculate_generalization_performance(void)   
{
   message += "test_calculate_generalization_performance\n";

   NeuralNetwork nn(1, 1, 1);

   nn.initialize_parameters(0.0);

   DataSet ds(1, 1, 1);

   ds.get_instances_pointer()->set_generalization();

   ds.initialize_data(0.0);

   MeanSquaredError mse(&nn, &ds);  

   double generalization_objective = mse.calculate_generalization_performance();

   assert_true(generalization_objective == 0.0, LOG);
}


void MeanSquaredErrorTest::test_calculate_performance_terms(void)
{
   message += "test_calculate_performance_terms\n";

   NeuralNetwork nn;
   Vector<unsigned> hidden_layers_size;
   Vector<double> parameters;

   DataSet ds;
   
   MeanSquaredError mse(&nn, &ds);

   double objective;

   Vector<double> evaluation_terms;

   // Test

   nn.set(2, 2);
   nn.randomize_parameters_normal();

   ds.set(2, 2, 3);
   ds.randomize_data_normal();

   objective = mse.calculate_performance();

   evaluation_terms = mse.calculate_terms();

   assert_true(fabs((evaluation_terms*evaluation_terms).calculate_sum() - objective) < 1.0e-3, LOG);
}


void MeanSquaredErrorTest::test_calculate_Jacobian_terms(void)
{
   message += "test_calculate_Jacobian_terms\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;
   Vector<unsigned> multilayer_perceptron_architecture;
   Vector<double> parameters;

   DataSet ds;

   MeanSquaredError mse(&nn, &ds);

   Vector<double> objective_gradient;

   Vector<double> evaluation_terms;
   Matrix<double> terms_Jacobian;
   Matrix<double> numerical_Jacobian_terms;

   // Test

   nn.set(1, 1);

   nn.initialize_parameters(0.0);

   ds.set(1, 1, 1);

   ds.initialize_data(0.0);

   terms_Jacobian = mse.calculate_terms_Jacobian();

   assert_true(terms_Jacobian.get_rows_number() == ds.get_instances().count_training_instances_number(), LOG);
   assert_true(terms_Jacobian.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(terms_Jacobian == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   ds.set(3, 2, 5);
   mse.set(&nn, &ds);
   ds.initialize_data(0.0);

   terms_Jacobian = mse.calculate_terms_Jacobian();

   assert_true(terms_Jacobian.get_rows_number() == ds.get_instances().count_training_instances_number(), LOG);
   assert_true(terms_Jacobian.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(terms_Jacobian == 0.0, LOG);

   // Test

   multilayer_perceptron_architecture.set(3);
   multilayer_perceptron_architecture[0] = 2;
   multilayer_perceptron_architecture[1] = 1;
   multilayer_perceptron_architecture[2] = 2;

   nn.set(multilayer_perceptron_architecture);
   nn.initialize_parameters(0.0);

   ds.set(2, 2, 5);
   mse.set(&nn, &ds);
   ds.initialize_data(0.0);

   terms_Jacobian = mse.calculate_terms_Jacobian();

   assert_true(terms_Jacobian.get_rows_number() == ds.get_instances().count_training_instances_number(), LOG);
   assert_true(terms_Jacobian.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(terms_Jacobian == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);
   nn.randomize_parameters_normal();
   parameters = nn.arrange_parameters();

   ds.set(1, 1, 1);
   ds.randomize_data_normal();

   terms_Jacobian = mse.calculate_terms_Jacobian();
   numerical_Jacobian_terms = nd.calculate_Jacobian(mse, &MeanSquaredError::calculate_terms, parameters);

   assert_true((terms_Jacobian-numerical_Jacobian_terms).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   nn.set(2, 2, 2);
   nn.randomize_parameters_normal();
   parameters = nn.arrange_parameters();

   ds.set(2, 2, 2);
   ds.randomize_data_normal();

   terms_Jacobian = mse.calculate_terms_Jacobian();
   numerical_Jacobian_terms = nd.calculate_Jacobian(mse, &MeanSquaredError::calculate_terms, parameters);

   assert_true((terms_Jacobian-numerical_Jacobian_terms).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   nn.set(2, 2, 2);
   nn.randomize_parameters_normal();

   ds.set(2, 2, 2);
   ds.randomize_data_normal();
   
   objective_gradient = mse.calculate_gradient();

   evaluation_terms = mse.calculate_terms();
   terms_Jacobian = mse.calculate_terms_Jacobian();

   assert_true(((terms_Jacobian.calculate_transpose()).dot(evaluation_terms)*2.0 - objective_gradient).calculate_absolute_value() < 1.0e-3, LOG);
}


void MeanSquaredErrorTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";
}


void MeanSquaredErrorTest::test_to_XML(void)
{
   message += "test_to_XML\n";
}


void MeanSquaredErrorTest::test_from_XML(void)
{
   message += "test_from_XML\n";
}


void MeanSquaredErrorTest::run_test_case(void)
{
   message += "Running mean squared error test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   // Set methods

   // Objective methods

   test_calculate_performance();   
   test_calculate_generalization_performance();

   test_calculate_gradient();

   // Objective terms methods

   test_calculate_performance_terms();
   test_calculate_Jacobian_terms();

   // Objective Hessian methods

   test_calculate_Hessian();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of mean squared error test case.\n";
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2014 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lemser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lemser General Public License for more details.

// You should have received a copy of the GNU Lemser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
