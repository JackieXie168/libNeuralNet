/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   P E R C E P T R O N   T E S T   C L A S S                                                                  */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <iostream>
#include <cstdlib>
#include <ctime>

// OpenNN includes

#include "../unit_testing.h"
#include "../../source/utilities/numerical_differentiation.h"
#include "../../source/neural_network/perceptron.h"

// Unit testing includes

#include "perceptron_test.h"


using namespace OpenNN;


// CONSTRUCTOR 

PerceptronTest::PerceptronTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

PerceptronTest::~PerceptronTest(void)
{
}


// METHODS

// void test_constructor(void) method

void PerceptronTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor

   Perceptron p1;

   assert_true(p1.count_inputs_number() == 0, LOG);

   // Inputs number constructor 

   Perceptron p2(1);

   assert_true(p2.count_inputs_number() == 1, LOG);

   // Inputs number and initialization constructor
   
   Perceptron p3(5, 0.0);

   assert_true(p3.count_inputs_number() == 5, LOG);
   assert_true(p3.arrange_parameters() == 0.0, LOG);

   // Copy constructor

   Perceptron p6(10, 2.0);

   Perceptron p7(p6);

   assert_true(p7.count_inputs_number() == 10, LOG);
   assert_true(p7.arrange_parameters() == 2.0, LOG);
}


// void test_destructor(void) method

void PerceptronTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_assignment_operator(void) method

void PerceptronTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   Perceptron p_1;

   p_1.set_activation_function(Perceptron::Threshold);

   Perceptron p_2 = p_1;

   assert_true(p_2.get_activation_function() == Perceptron::Threshold, LOG);
}


// void test_get_activation_function(void) method

void PerceptronTest::test_get_activation_function(void)
{
   message += "test_get_activation_function\n";

   Perceptron p;

   p.set_activation_function(Perceptron::SymmetricThreshold);

   assert_true(p.get_activation_function() == Perceptron::SymmetricThreshold, LOG);
}


// void test_count_inputs_number(void) method

void PerceptronTest::test_count_inputs_number(void)
{
   message += "test_count_inputs_number\n";

   Perceptron p;

   assert_true(p.count_inputs_number() == 0, LOG);
}


// void test_get_bias(void) method   

void PerceptronTest::test_get_bias(void)   
{
   message += "test_count_inputs_number\n";

   Perceptron p;
   p.initialize_parameters(0.0);

   assert_true(p.get_bias() == 0.0, LOG);
}


// void test_arrange_synaptic_weights(void) method

void PerceptronTest::test_arrange_synaptic_weights(void)
{
   message += "test_arrange_synaptic_weights\n";

   Perceptron p;

   Vector<double> synaptic_weights = p.arrange_synaptic_weights();

   assert_true(synaptic_weights.size() == 0, LOG);
}


// void test_get_synaptic_weight(void) method

void PerceptronTest::test_get_synaptic_weight(void)
{
   message += "test_arrange_synaptic_weights\n";

   Perceptron p(1);
   p.initialize_parameters(0.0);

   assert_true(p.get_synaptic_weight(0) == 0.0, LOG);
}


// void test_count_parameters_number(void) method

void PerceptronTest::test_count_parameters_number(void)
{
   message += "test_count_parameters_number\n";

   Perceptron p(1);

   const unsigned int parameters_number = p.count_parameters_number();

   assert_true(parameters_number == 2, LOG);
}


// void test_arrange_parameters(void) method

void PerceptronTest::test_arrange_parameters(void)
{
   message += "test_arrange_parameters\n";
   
   Perceptron p(1);

   Vector<double> parameters = p.arrange_parameters();

   unsigned int size = parameters.size();

   assert_true(size == 2, LOG);
}


// void test_get_display(void) method

void PerceptronTest::test_get_display(void)
{
   message += "test_get_display\n";
   
   Perceptron p;

   p.set_display(true);

   assert_true(p.get_display() == true, LOG);
}


// void test_set(void) method

void PerceptronTest::test_set(void)
{
   message += "test_set\n";
}


// void test_set_activation_function(void) method

void PerceptronTest::test_set_activation_function(void)
{
   message += "test_set_activation_function\n";

   Perceptron p;

   p.set_activation_function(Perceptron::Linear);

   assert_true(p.get_activation_function() == Perceptron::Linear, LOG);
}


// void test_set_inputs_number(void) method

void PerceptronTest::test_set_inputs_number(void)
{
   message += "test_set_inputs_number\n";

   Perceptron p;

   p.set_inputs_number(0);

   assert_true(p.count_inputs_number() == 0, LOG);
}


// void test_set_bias(void) method

void PerceptronTest::test_set_bias(void)
{
   message += "test_set_bias\n";

   Perceptron p;

   p.set_bias(0.0);

   assert_true(p.get_bias() == 0.0, LOG);   
}


// void test_set_synaptic_weights(void) method

void PerceptronTest::test_set_synaptic_weights(void)
{
   message += "test_set_synaptic_weights\n";

   Perceptron p;

   Vector<double> synaptic_weights;

   p.set_synaptic_weights(synaptic_weights);

   synaptic_weights = p.arrange_synaptic_weights();

   assert_true(synaptic_weights.size() == 0, LOG);   
}


// void test_set_synaptic_weight(void) method

void PerceptronTest::test_set_synaptic_weight(void)
{
   message += "test_set_synaptic_weight\n";

   Perceptron p(2);

   p.set_synaptic_weight(1, 1.0);

   assert_true(p.get_synaptic_weight(1) == 1.0, LOG);   
}


// void test_set_parameters(void) method

void PerceptronTest::test_set_parameters(void)
{
   message += "test_set_parameters\n";

   Perceptron p;

   Vector<double> parameters(1);

   p.set_parameters(parameters);

   parameters = p.arrange_parameters();

   assert_true(parameters.size() == 1, LOG);   
}


// void test_set_display(void) method

void PerceptronTest::test_set_display(void)
{
   message += "test_set_display\n";

   Perceptron p;

   p.set_display(false);

   assert_true(p.get_display() == false, LOG);   
}


// void test_initialize_parameters(void) method

void PerceptronTest::test_initialize_parameters(void)
{
   message += "test_initialize_parameters\n";

   Perceptron p(1);

   p.initialize_parameters(0.0);

   assert_true(p.arrange_parameters() == 0.0, LOG);   
}


// void test_initialize_bias_uniform(void) method

void PerceptronTest::test_initialize_bias_uniform(void)
{
   message += "test_initialize_bias_uniform\n";

   Perceptron p;

   p.initialize_bias_uniform(0.0, 0.0);

   assert_true(p.get_bias() == 0.0, LOG);   
}


// void test_initialize_bias_normal(void) method

void PerceptronTest::test_initialize_bias_normal(void)
{
   message += "test_initialize_bias_normal\n";

   Perceptron p;

   p.initialize_bias_normal(0.0, 0.0);

   assert_true(p.get_bias() == 0.0, LOG);   
}


// void test_initialize_synaptic_weights_uniform(void) method

void PerceptronTest::test_initialize_synaptic_weights_uniform(void)
{
   message += "test_initialize_synaptic_weights_uniform\n";

   Perceptron p(1);

   p.initialize_synaptic_weights_uniform(0.0, 0.0);

   assert_true(p.get_synaptic_weight(0) == 0.0, LOG);   
}


// void test_initialize_synaptic_weights_normal(void) method

void PerceptronTest::test_initialize_synaptic_weights_normal(void)
{
   message += "test_initialize_synaptic_weights_normal\n";

   Perceptron p(1);

   p.initialize_synaptic_weights_normal(0.0, 0.0);

   assert_true(p.get_synaptic_weight(0) == 0.0, LOG);   
}


// void test_calculate_combination(void) method

void PerceptronTest::test_calculate_combination(void)
{
   message += "test_calculate_combination\n";

   unsigned int inputs_number = 3;

   Perceptron p(inputs_number);

   double bias = 0.0;
   Vector<double> synaptic_weights(inputs_number, 0.0);

   p.set_bias(bias);
   p.set_synaptic_weights(synaptic_weights);

   Vector<double> inputs(inputs_number, 0.0);
   
   double combination = p.calculate_combination(inputs);

   assert_true(combination == 0.0, LOG);

   p.set(3);

   inputs.set(3);
   inputs[0] = -0.8;
   inputs[1] =  0.2;
   inputs[2] = -0.4;

   p.set_bias(-0.5);

   synaptic_weights.set(3);
   synaptic_weights[0] =  1.0;
   synaptic_weights[1] = -0.75;
   synaptic_weights[2] =  0.25;

   p.set_synaptic_weights(synaptic_weights);

   combination = p.calculate_combination(inputs);

   assert_true(combination == -1.55, LOG);
}


// void test_calculate_combination_gradient(void) method

void PerceptronTest::test_calculate_combination_gradient(void)
{
   message += "test_calculate_combination_gradient\n";

   Perceptron p;

   Vector<double> inputs;
   Vector<double> combination_gradient;   

   NumericalDifferentiation nd;

   Vector<double> numerical_combination_gradient;

   // Test

   p.set(3);

   inputs.set(3, 0.75);

   combination_gradient = p.calculate_combination_gradient(inputs);
     
   numerical_combination_gradient = nd.calculate_gradient(p, &Perceptron::calculate_combination, inputs);
   
   assert_true((combination_gradient-numerical_combination_gradient).calculate_absolute_value() < 1.0e-3, LOG);
}


// void test_calculate_combination_Hessian(void)

void PerceptronTest::test_calculate_combination_Hessian(void)
{
   message += "test_calculate_combination_Hessian\n";

   Perceptron p;

   Vector<double> inputs;
   Matrix<double> combination_Hessian;   

   NumericalDifferentiation nd;

   Matrix<double> numerical_combination_Hessian;

   // Test

   p.set(3);

   inputs.set(3, 0.75);

   combination_Hessian = p.calculate_combination_Hessian(inputs);
     
   numerical_combination_Hessian = nd.calculate_Hessian(p, &Perceptron::calculate_combination, inputs);

   assert_true((combination_Hessian-numerical_combination_Hessian).calculate_absolute_value() < 1.0e-3, LOG);
}


// void test_calculate_combination_parameters_gradient(void) method

void PerceptronTest::test_calculate_combination_parameters_gradient(void)
{
   message += "test_calculate_combination_parameters_gradient\n";

   NumericalDifferentiation nd;

   Perceptron p;

   Vector<double> inputs;
   Vector<double> parameters;   

   Vector<double> combination_parameters_gradient;

   Vector<double> numerical_combination_parameters_gradient;

   // Test
   
   p.set_inputs_number(2);

   inputs.set(2, 0.53);

   parameters.set(3, -0.07);

   p.set_parameters(parameters);

   combination_parameters_gradient = p.calculate_combination_parameters_gradient(inputs);

   numerical_combination_parameters_gradient = nd.calculate_gradient(p, &Perceptron::calculate_combination_parameters, inputs, parameters);
   
   assert_true(combination_parameters_gradient.size() == p.count_parameters_number(), LOG);
   assert_true((combination_parameters_gradient-numerical_combination_parameters_gradient).calculate_absolute_value() < 1.0e-3, LOG);
}


// void test_calculate_combination_parameters_Hessian(void)

void PerceptronTest::test_calculate_combination_parameters_Hessian(void)
{
   message += "test_calculate_combination_parameters_Hessian\n";

   NumericalDifferentiation nd;

   Perceptron p;

   Vector<double> inputs;
   Vector<double> parameters;   

   Matrix<double> combination_parameters_Hessian;

   Matrix<double> numerical_combination_parameters_Hessian;

   // Test
   
   p.set_inputs_number(2);

   inputs.set(2, 0.53);

   parameters.set(3, -0.07);

   p.set_parameters(parameters);

   combination_parameters_Hessian = p.calculate_combination_parameters_Hessian(inputs);

   numerical_combination_parameters_Hessian = nd.calculate_Hessian(p, &Perceptron::calculate_combination_parameters, inputs, parameters);
   
   assert_true(combination_parameters_Hessian.get_rows_number() == p.count_parameters_number(), LOG);
   assert_true(combination_parameters_Hessian.get_columns_number() == p.count_parameters_number(), LOG);
   assert_true((combination_parameters_Hessian-numerical_combination_parameters_Hessian).calculate_absolute_value() < 1.0e-3, LOG);
}


// void test_calculate_activation(void) method

void PerceptronTest::test_calculate_activation(void)
{
   message += "test_calculate_activation\n";

   double activation;   

   Perceptron p;

   double combination;
   
   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 0.5, LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 0.0, LOG);

   // Threshold activation function 
   
   p.set_activation_function(Perceptron::Threshold);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 1.0, LOG);

   // Symmetric threshold activation function 
   
   p.set_activation_function(Perceptron::SymmetricThreshold);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 1.0, LOG);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(combination == 0.0, LOG);

   // Threshold activation function 
   
   p.set_activation_function(Perceptron::Threshold);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 1.0, LOG);

   // SymmetricThreshold activation function 
   
   p.set_activation_function(Perceptron::SymmetricThreshold);

   combination = 0.0;
   activation = p.calculate_activation(combination);
   assert_true(activation == 1.0, LOG);

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   combination = 0.0;
   activation = p.calculate_activation(combination);

   assert_true(fabs(activation - 1.0/(1.0+exp(-combination))) < 1.0e-12, LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   activation = p.calculate_activation(combination);
   assert_true(fabs(activation - tanh(combination)) < 1.0e-12, LOG);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   activation = p.calculate_activation(combination);
   assert_true(combination == activation, LOG);
}


// void test_calculate_activation_derivative(void) method

void PerceptronTest::test_calculate_activation_derivative(void)
{
   message += "test_calculate_activation_derivative\n";

   Perceptron p;

   double combination;
   double activation_derivative;   

   NumericalDifferentiation nd;

   double numerical_derivative;

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   // Test

   combination = 0.0;
   activation_derivative = p.calculate_activation_derivative(combination);
   
   assert_true(activation_derivative == 0.25, LOG);

   // Test

   combination = -1.55;
   activation_derivative = p.calculate_activation_derivative(combination);
   
   numerical_derivative = nd.calculate_derivative(p, &Perceptron::calculate_activation, combination);
   
   assert_true(fabs(activation_derivative-numerical_derivative) < 1.0e-3, LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   // Test

   combination = 0.0;
   activation_derivative = p.calculate_activation_derivative(combination);
   assert_true(activation_derivative == 1.0, LOG);
  
   // Test

   combination = -1.55;
   activation_derivative = p.calculate_activation_derivative(combination);

   numerical_derivative = nd.calculate_derivative(p, &Perceptron::calculate_activation, combination);
   
   assert_true(fabs(activation_derivative-numerical_derivative) < 1.0e-3, LOG);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   // Test

   combination = 0.0;
   activation_derivative = p.calculate_activation_derivative(combination);
   assert_true(activation_derivative == 1.0, LOG);

   numerical_derivative = nd.calculate_derivative(p, &Perceptron::calculate_activation, combination);
   
   assert_true(fabs(activation_derivative-numerical_derivative) < 1.0e-3, LOG);
}

  
// void test_calculate_activation_second_derivative(void) method

void PerceptronTest::test_calculate_activation_second_derivative(void)
{
   message += "test_calculate_activation_second_derivative\n";

   Perceptron p;

   double combination;   
   double activation_second_derivative;   

   NumericalDifferentiation nd;

   double activation_numerical_second_derivative;

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   // Test

   combination = 0.0;
   activation_second_derivative = p.calculate_activation_second_derivative(combination);
   assert_true(activation_second_derivative == 0.0, LOG);

   // Test

   combination = -1.55;
   activation_second_derivative = p.calculate_activation_second_derivative(combination);

   activation_numerical_second_derivative = nd.calculate_second_derivative(p, &Perceptron::calculate_activation, combination);
   
   assert_true(fabs(activation_second_derivative-activation_numerical_second_derivative) < 1.0e-3, LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   // Test

   combination = 0.0;
   activation_second_derivative = p.calculate_activation_second_derivative(combination);
   assert_true(activation_second_derivative == 0.0, LOG);

   // Test

   combination = -1.55;
   activation_second_derivative = p.calculate_activation_second_derivative(combination);

   activation_numerical_second_derivative = nd.calculate_second_derivative(p, &Perceptron::calculate_activation, combination);
   
   assert_true(fabs(activation_second_derivative-activation_numerical_second_derivative) < 1.0e-3, LOG); 

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   // Test

   combination = 0.0;
   activation_second_derivative = p.calculate_activation_second_derivative(combination);
   assert_true(activation_second_derivative == 0.0, LOG);

   // Test

   combination = -1.55;
   activation_second_derivative = p.calculate_activation_second_derivative(combination);

   activation_numerical_second_derivative = nd.calculate_second_derivative(p, &Perceptron::calculate_activation, combination);
   
   assert_true(fabs(activation_second_derivative-activation_numerical_second_derivative) < 1.0e-3, LOG);
}


// void test_calculate_output(void) method

void PerceptronTest::test_calculate_output(void)
{
   message += "test_calculate_outputs\n";

   double outputs;   

   unsigned int inputs_number = 3;

   Perceptron p(inputs_number);

   double bias = 0.0;
   Vector<double> synaptic_weights(inputs_number, 0.0);

   p.set_bias(bias);
   p.set_synaptic_weights(synaptic_weights);

   Vector<double> inputs(inputs_number, 0.0);

   double combination = p.calculate_combination(inputs);

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   outputs = p.calculate_outputs(inputs);
   assert_true(outputs == 0.5, LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   outputs = p.calculate_outputs(inputs);
   assert_true(outputs == 0.0, LOG);

   // Threshold activation function 
   
   p.set_activation_function(Perceptron::Threshold);

   outputs = p.calculate_outputs(inputs);
   assert_true(outputs == 1.0, LOG);

   // SymmetricThreshold activation function 
   
   p.set_activation_function(Perceptron::SymmetricThreshold);

   outputs = p.calculate_outputs(inputs);
   assert_true(outputs == 1.0, LOG);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   outputs = p.calculate_outputs(inputs);
   assert_true(outputs == 0.0, LOG);


   // New test

   p.set(2);

   p.set_activation_function(Perceptron::Logistic);

   inputs.set(2);
   inputs[0] = -0.2;
   inputs[1] =  0.5;

   p.set_bias(-0.5);

   synaptic_weights.set(2);
   synaptic_weights[0] = 1.0;
   synaptic_weights[1] = 0.25;

   p.set_synaptic_weights(synaptic_weights);

   outputs = p.calculate_outputs(inputs);

   // New test

   p.set(3);

   inputs.set(3);
   inputs[0] = -0.8;
   inputs[1] =  0.2;
   inputs[2] = -0.4;

   p.set_bias(-0.5);

   synaptic_weights.set(3);
   synaptic_weights[0] =  1.0;
   synaptic_weights[1] = -0.75;
   synaptic_weights[2] =  0.25;

   p.set_synaptic_weights(synaptic_weights);

   outputs = p.calculate_outputs(inputs);

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   combination = p.calculate_combination(inputs);
   outputs = p.calculate_outputs(inputs);
   assert_true(fabs(outputs - 1.0/(1.0 + exp(-combination))) < 1.0e-12, LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   combination = p.calculate_combination(inputs);
   outputs = p.calculate_outputs(inputs);
   assert_true(fabs(outputs - tanh(combination)) < 1.0e-12, LOG);

   // Threshold activation function 
   
   p.set_activation_function(Perceptron::Threshold);

   outputs = p.calculate_outputs(inputs);
   assert_true(outputs == 0.0, LOG);

   // Symmetric threshold activation function 
   
   p.set_activation_function(Perceptron::SymmetricThreshold);

   outputs = p.calculate_outputs(inputs);
   assert_true(outputs == -1.0, LOG);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   combination = p.calculate_combination(inputs);
   outputs = p.calculate_outputs(inputs);
   assert_true(fabs(outputs - combination) < 1.0e-12, LOG);   
}


// void test_calculate_parameters_output(void) method

void PerceptronTest::test_calculate_parameters_output(void)
{
   message += "test_calculate_parameters_output\n";
}


// void test_calculate_gradient(void) method

void PerceptronTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   Perceptron p;

   Vector<double> inputs;
   Vector<double> gradient;   

   NumericalDifferentiation nd;

   Vector<double> numerical_gradient;

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   // Test

   p.set(3);

   inputs.set(3, 0.75);

   gradient = p.calculate_gradient(inputs);
     
   numerical_gradient = nd.calculate_gradient(p, &Perceptron::calculate_outputs, inputs);
   
   assert_true((gradient-numerical_gradient).calculate_absolute_value() < 1.0e-3, LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   // Test

   p.set(3);

   inputs.set(3, 0.75);

   gradient = p.calculate_gradient(inputs);
     
   numerical_gradient = nd.calculate_gradient(p, &Perceptron::calculate_outputs, inputs);
   
   assert_true((gradient-numerical_gradient).calculate_absolute_value() < 1.0e-3, LOG);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   // Test

   p.set(3);

   inputs.set(3, 0.75);

   gradient = p.calculate_gradient(inputs);
     
   numerical_gradient = nd.calculate_gradient(p, &Perceptron::calculate_outputs, inputs);
   
   assert_true((gradient-numerical_gradient).calculate_absolute_value() < 1.0e-3, LOG);
}


// void test_calculate_Hessian(void) method

void PerceptronTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";

   Perceptron p;

   Vector<double> inputs;
   Matrix<double> Hessian;   

   NumericalDifferentiation nd;

   Matrix<double> numerical_Hessian;

   // Logistic activation function 
   
   p.set_activation_function(Perceptron::Logistic);

   // Test

   p.set(3);

   inputs.set(3, 0.75);

   Hessian = p.calculate_Hessian(inputs);
     
   numerical_Hessian = nd.calculate_Hessian(p, &Perceptron::calculate_outputs, inputs);

   assert_true((Hessian-numerical_Hessian).calculate_absolute_value() < 1.0e-3, LOG);
   assert_true(Hessian.is_symmetric(), LOG);

   // Hyperbolic tangent activation function 

   p.set_activation_function(Perceptron::HyperbolicTangent);

   // Test

   p.set(3);

   inputs.set(3, 0.75);

   Hessian = p.calculate_Hessian(inputs);
     
   numerical_Hessian = nd.calculate_Hessian(p, &Perceptron::calculate_outputs, inputs);
   
   assert_true((Hessian-numerical_Hessian).calculate_absolute_value() < 1.0e-3, LOG);
   assert_true(Hessian.is_symmetric(), LOG);

   // Linear activation function
   
   p.set_activation_function(Perceptron::Linear);

   // Test

   p.set(3);

   inputs.set(3, 0.75);

   Hessian = p.calculate_Hessian(inputs);
     
   numerical_Hessian = nd.calculate_Hessian(p, &Perceptron::calculate_outputs, inputs);
   
   assert_true((Hessian-numerical_Hessian).calculate_absolute_value() < 1.0e-3, LOG);
   assert_true(Hessian.is_symmetric(), LOG);
}


// void test_calculate_parameters_gradient(void) method

void PerceptronTest::test_calculate_parameters_gradient(void)
{
   message += "test_calculate_parameters_gradient\n";

   NumericalDifferentiation nd;

   Perceptron p;

   Vector<double> inputs;
   Vector<double> parameters;   

   Vector<double> parameters_gradient;
   Vector<double> numerical_parameters_gradient;

   // Test
   
   p.set_inputs_number(2);

   inputs.set(2, 0.82);
   parameters.set(3, -0.93);

   p.set_parameters(parameters);

   parameters_gradient = p.calculate_parameters_gradient(inputs);

   numerical_parameters_gradient = nd.calculate_gradient(p, &Perceptron::calculate_parameters_output, inputs, parameters);
   
   assert_true(parameters_gradient.size() == p.count_parameters_number(), LOG);
   assert_true((parameters_gradient-numerical_parameters_gradient).calculate_absolute_value() < 1.0e-3, LOG);
}


// void test_calculate_parameters_Hessian(void) method

void PerceptronTest::test_calculate_parameters_Hessian(void)
{
   message += "test_calculate_parameters_Hessian\n";

   NumericalDifferentiation nd;

   Perceptron p;

   Vector<double> inputs;
   Vector<double> parameters;   

   Matrix<double> parameters_Hessian;
   Matrix<double> numerical_parameters_Hessian;

   // Test
   
   p.set_inputs_number(2);

   inputs.set(2, 0.82);
   parameters.set(3, -0.93);

   p.set_parameters(parameters);

   parameters_Hessian = p.calculate_parameters_Hessian(inputs);

   numerical_parameters_Hessian = nd.calculate_Hessian(p, &Perceptron::calculate_parameters_output, inputs, parameters);
   
   assert_true((parameters_Hessian-numerical_parameters_Hessian).calculate_absolute_value() < 1.0e-3, LOG);
   assert_true(parameters_Hessian.is_symmetric(), LOG);

   // Test
   
   p.set_inputs_number(3);

   inputs.set(3);
   inputs[0] = -0.8;
   inputs[1] =  0.2;
   inputs[2] = -0.4;

   parameters.set(4);
   parameters[0] = -0.5;
   parameters[1] = 1.0;
   parameters[2] = -0.75;
   parameters[3] = 0.25;

   p.set_parameters(parameters);

   parameters_Hessian = p.calculate_parameters_Hessian(inputs);

   numerical_parameters_Hessian = nd.calculate_Hessian(p, &Perceptron::calculate_parameters_output, inputs, parameters);
   
   assert_true((parameters_Hessian-numerical_parameters_Hessian).calculate_absolute_value() < 1.0e-3, LOG);
   assert_true(parameters_Hessian.is_symmetric(), LOG);
}


// void test_to_XML(void) method

void PerceptronTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   Perceptron p;

//   std::string object = p.to_XML();
}


// void run_test_case(void) method

void PerceptronTest::run_test_case(void)
{
   message += "Running perceptron test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor(); 

   // Assignment operator 

   test_assignment_operator();

   // Get methods

   test_count_inputs_number();
   test_get_activation_function();
   test_get_bias();   
   test_arrange_synaptic_weights();
   test_get_synaptic_weight();
   test_count_parameters_number();
   test_arrange_parameters();
   test_get_display();

   // Set methods

   test_set();

   test_set_inputs_number();
   test_set_activation_function();
   test_set_bias();
   test_set_synaptic_weights();
   test_set_synaptic_weight();
   test_set_parameters();
   test_set_display();

   // Initialization methods

   test_initialize_bias_uniform();
   test_initialize_bias_normal();

   test_initialize_synaptic_weights_uniform();
   test_initialize_synaptic_weights_normal();

   test_initialize_parameters();

   // Combination methods

   test_calculate_combination();

   // Activation methods

   test_calculate_activation();
   test_calculate_activation_derivative();
   test_calculate_activation_second_derivative();

   // Output methods

   test_calculate_output();

   // Gradient methods

   test_calculate_gradient();
   test_calculate_parameters_gradient();

   test_calculate_combination_gradient();
   test_calculate_combination_parameters_gradient();

   // Hessian methods

   test_calculate_Hessian();
   test_calculate_Hessian();
   test_calculate_parameters_Hessian();
   test_calculate_combination_Hessian();
   test_calculate_combination_parameters_Hessian();

   message += "End of perceptron test case...\n";
}


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

