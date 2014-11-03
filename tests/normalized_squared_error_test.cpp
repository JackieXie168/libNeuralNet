/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   N O R M A L I Z E D   S Q U A R E D   E R R O R   T E S T   C L A S S                                      */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

#include "normalized_squared_error_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR


NormalizedSquaredErrorTest::NormalizedSquaredErrorTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

NormalizedSquaredErrorTest::~NormalizedSquaredErrorTest(void)
{
}


// METHODS

void NormalizedSquaredErrorTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   NormalizedSquaredError nse1;

   assert_true(nse1.has_neural_network() == false, LOG);
   assert_true(nse1.has_data_set() == false, LOG);

   // Neural network

   NeuralNetwork mlp2;
   NormalizedSquaredError nse2(&mlp2);

   assert_true(nse2.has_neural_network() == true, LOG);
   assert_true(nse2.has_data_set() == false, LOG);

   // Neural network and data set

   NeuralNetwork mlp3;
   DataSet ds3;
   NormalizedSquaredError nse3(&mlp3, &ds3);

   assert_true(nse3.has_neural_network() == true, LOG);
   assert_true(nse3.has_data_set() == true, LOG);
}


void NormalizedSquaredErrorTest::test_destructor(void)
{
   message += "test_destructor\n";
}


void NormalizedSquaredErrorTest::test_calculate_performance(void)   
{
   message += "test_calculate_performance\n";

   Vector<double> parameters;

   NeuralNetwork nn(1,1);

   MultilayerPerceptron* mlpp = nn.get_multilayer_perceptron_pointer();

   mlpp->get_layer_pointer(0)->set_activation_function(Perceptron::Linear);

   mlpp->initialize_biases(0.0);
   mlpp->initialize_synaptic_weights(1.0);

   DataSet ds(1,1,2);

   Matrix<double> new_data(2, 2);
   new_data[0][0] = -1.0;
   new_data[0][1] = -1.0;
   new_data[1][0] = 1.0;
   new_data[1][1] = 1.0;

   ds.set_data(new_data);

   NormalizedSquaredError nse(&nn, &ds);

   assert_true(nse.calculate_performance() == 0.0, LOG);

   // Test

   nn.set(1, 1);
   nn.randomize_parameters_normal();

   parameters = nn.arrange_parameters();

   ds.set(1, 1, 2);
   ds.randomize_data_normal();

   assert_true(nse.calculate_performance() == nse.calculate_performance(parameters), LOG);
}


void NormalizedSquaredErrorTest::test_calculate_generalization_performance(void)   
{
   message += "test_calculate_generalization_performance\n";

   NeuralNetwork nn;

   DataSet ds;

   NormalizedSquaredError nse(&nn, &ds);  

   double generalization_performance;

   // Test

   nn.set(2,2,2);

   ds.set(2,2,2);

   ds.get_instances_pointer()->set_generalization();

   ds.randomize_data_normal();

   generalization_performance = nse.calculate_generalization_performance();

   assert_true(generalization_performance != 0.0, LOG);

}


void NormalizedSquaredErrorTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;

   Vector<double> network_parameters;

   DataSet ds;
   Matrix<double> data;

   NormalizedSquaredError nse(&nn, &ds);

   Vector<double> objective_gradient;
   Vector<double> numerical_objective_gradient;

   // Test 

   nn.set(1,1,1);

   nn.initialize_parameters(0.0);

   ds.set(1, 1, 2);

   data.set(2, 2);
   data[0][0] = -1.0;
   data[0][1] = -1.0;
   data[1][0] = 1.0;
   data[1][1] = 1.0;

   ds.set_data(data);

   objective_gradient = nse.calculate_gradient();

   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 5);
   nn.randomize_parameters_normal();

   network_parameters = nn.arrange_parameters();

   ds.set(3, 5, 2);
   ds.randomize_data_normal();

   objective_gradient = nse.calculate_gradient();
   numerical_objective_gradient = nd.calculate_gradient(nse, &NormalizedSquaredError::calculate_performance, network_parameters);

   assert_true((objective_gradient - numerical_objective_gradient).calculate_absolute_value() < 1.0e-3, LOG);
}


void NormalizedSquaredErrorTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";
}


void NormalizedSquaredErrorTest::test_calculate_performance_terms(void)
{
   message += "test_calculate_performance_terms\n";

   NeuralNetwork nn;
   Vector<unsigned> multilayer_perceptron_architecture;
   Vector<double> network_parameters;

   DataSet ds;

   NormalizedSquaredError nse(&nn, &ds);

   double objective;

   Vector<double> evaluation_terms;

   // Test

   nn.set(2, 2);
   nn.randomize_parameters_normal();

   ds.set(2, 2, 3);
   ds.randomize_data_normal();

   objective = nse.calculate_performance();

   evaluation_terms = nse.calculate_terms();

   assert_true(fabs((evaluation_terms*evaluation_terms).calculate_sum() - objective) < 1.0e-3, LOG);

}


void NormalizedSquaredErrorTest::test_calculate_Jacobian_terms(void)
{
   message += "test_calculate_Jacobian_terms\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;
   Vector<int> hidden_layers_size;
   Vector<double> network_parameters;

   DataSet ds;

   NormalizedSquaredError nse(&nn, &ds);

   Vector<double> objective_gradient;

   Vector<double> evaluation_terms;
   Matrix<double> terms_Jacobian;
   Matrix<double> numerical_Jacobian_terms;

   // Test

   nn.set(1, 1);
   nn.randomize_parameters_normal();
   network_parameters = nn.arrange_parameters();

   ds.set(1, 1, 2);
   ds.randomize_data_normal();

   terms_Jacobian = nse.calculate_terms_Jacobian();
   numerical_Jacobian_terms = nd.calculate_Jacobian(nse, &NormalizedSquaredError::calculate_terms, network_parameters);

   assert_true((terms_Jacobian-numerical_Jacobian_terms).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   nn.set(2, 2, 2);
   nn.randomize_parameters_normal();
   network_parameters = nn.arrange_parameters();

   ds.set(2, 2, 2);
   ds.randomize_data_normal();

   terms_Jacobian = nse.calculate_terms_Jacobian();
   numerical_Jacobian_terms = nd.calculate_Jacobian(nse, &NormalizedSquaredError::calculate_terms, network_parameters);

   assert_true((terms_Jacobian-numerical_Jacobian_terms).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   nn.set(2,2,2);
   nn.randomize_parameters_normal();

   ds.set(2,2,2);
   ds.randomize_data_normal();
   
   objective_gradient = nse.calculate_gradient();

   evaluation_terms = nse.calculate_terms();
   terms_Jacobian = nse.calculate_terms_Jacobian();

   assert_true(((terms_Jacobian.calculate_transpose()).dot(evaluation_terms)*2.0 - objective_gradient).calculate_absolute_value() < 1.0e-3, LOG);

}


void NormalizedSquaredErrorTest::test_to_XML(void)
{
   message += "test_to_XML\n";
}


void NormalizedSquaredErrorTest::test_from_XML(void)
{
   message += "test_from_XML\n";
}


void NormalizedSquaredErrorTest::run_test_case(void)
{
   message += "Running normalized squared error test case...\n";

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
   test_calculate_performance_terms();

   test_calculate_Jacobian_terms();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of normalized squared error test case.\n";
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2014 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lenser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lenser General Public License for more details.

// You should have received a copy of the GNU Lenser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
