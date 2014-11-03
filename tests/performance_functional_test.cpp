/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   P E R F O R M A N C E   F U N C T I O N A L   T E S T   C L A S S                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

#include "performance_functional_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

PerformanceFunctionalTest::PerformanceFunctionalTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

PerformanceFunctionalTest::~PerformanceFunctionalTest(void)
{
}


// METHODS

void PerformanceFunctionalTest::test_constructor(void)
{
   message += "test_constructor\n";

   PerformanceFunctional pf1;

   assert_true(pf1.has_neural_network() == false, LOG);
   assert_true(pf1.has_data_set() == false, LOG);
   assert_true(pf1.has_mathematical_model() == false, LOG);
}


void PerformanceFunctionalTest::test_destructor(void)
{
   message += "test_destructor\n";
}


void PerformanceFunctionalTest::test_get_neural_network_pointer(void)
{
   message += "test_get_neural_network_pointer\n";

   PerformanceFunctional pf;
   NeuralNetwork nn;

   // Test

   pf.set_neural_network_pointer(&nn);
   assert_true(pf.get_neural_network_pointer() != NULL,	LOG);
}


void PerformanceFunctionalTest::test_get_mathematical_model_pointer(void)
{
   message += "test_get_mathematical_model_pointer\n";
}


void PerformanceFunctionalTest::test_get_data_set_pointer(void)
{
   message += "test_get_data_set_pointer\n";
}


void PerformanceFunctionalTest::test_get_user_objective_pointer(void)
{
   message += "test_get_user_objective_pointer\n";
}


void PerformanceFunctionalTest::test_get_user_regularization_pointer(void)
{
   message += "test_get_user_regularization_pointer\n";
}


void PerformanceFunctionalTest::test_get_user_constraints_pointer(void)
{
   message += "test_get_user_constraints_pointer\n";
}


void PerformanceFunctionalTest::test_get_numerical_differentiation_pointer(void)
{
   message += "test_get_numerical_differentiation_pointer\n";
}


void PerformanceFunctionalTest::test_get_display(void)
{
   message += "test_get_display\n";

   PerformanceFunctional pf;

   // Test

   pf.set_display(true);
   assert_true(pf.get_display() == true, LOG);

   pf.set_display(false);
   assert_true(pf.get_display() == false, LOG);
}


void PerformanceFunctionalTest::test_set_neural_network_pointer(void)
{
   message += "test_set_neural_network_pointer\n";

   PerformanceFunctional pf;
   NeuralNetwork nn;

   // Test

   pf.set_neural_network_pointer(&nn);
   assert_true(pf.get_neural_network_pointer() != NULL, LOG);
}


void PerformanceFunctionalTest::test_set_numerical_differentiation(void)
{
   message += "test_set_numerical_differentiation\n";
}


void PerformanceFunctionalTest::test_set_default(void)
{
   message += "test_set_default\n";

   PerformanceFunctional pf;

   // Test

   pf.set_default();
}


void PerformanceFunctionalTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// @todo Check test

void PerformanceFunctionalTest::test_calculate_performance(void)
{
   message += "test_calculate_performance\n";

   DataSet ds;

   NeuralNetwork nn;

   Vector<double> parameters;

   PerformanceFunctional pf(&nn);

   double performance;

   Vector<double> direction;
   double rate;

   // Test

   pf.destruct_all_terms();
   pf.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

   nn.set(1, 1);

   nn.initialize_parameters(1.0);

   parameters = nn.arrange_parameters();

//   assert_true(fabs(pf.calculate_performance() - sqrt(2.0)) < 1.0e-3, LOG);
   assert_true(fabs(pf.calculate_performance() - pf.calculate_performance(parameters)) < 1.0e-3, LOG);

   // Test

   parameters = nn.arrange_parameters();

   assert_true(pf.calculate_performance() != pf.calculate_performance(parameters*2.0), LOG);

   // Test

   direction.set(2, -0.5);
   rate = 2.0;

   assert_true(pf.calculate_performance(direction, rate) == 0.0, LOG);

   // Test

   parameters = nn.arrange_parameters();

   direction.set(2, -1.5);
   rate = 2.3;

   assert_true(pf.calculate_performance(direction, rate) == pf.calculate_performance(parameters + direction*rate), LOG);

   // Test

   ds.set(1, 1, 1);
   ds.randomize_data_normal();

   pf.set_data_set_pointer(&ds);

   pf.destruct_all_terms();
   pf.set_objective_type(PerformanceFunctional::SUM_SQUARED_ERROR_OBJECTIVE);

   nn.set(1, 1);

   nn.initialize_parameters(1.0);

   parameters = nn.arrange_parameters();

   assert_true(fabs(pf.calculate_performance() - pf.calculate_performance(parameters)) < 1.0e-3, LOG);

   // Test

   parameters = nn.arrange_parameters();

   assert_true(pf.calculate_performance() != pf.calculate_performance(parameters*2.0), LOG);

   // Test

   parameters = nn.arrange_parameters();

   direction.set(2, -1.5);
   rate = 2.3;

   assert_true(pf.calculate_performance(direction, rate) == pf.calculate_performance(parameters + direction*rate), LOG);

   // Test

   nn.initialize_parameters(0.0);

   MockPerformanceTerm* mptp = new MockPerformanceTerm(&nn);

   pf.set_user_objective_pointer(mptp);

   performance = pf.calculate_performance();

   assert_true(performance == 0.0, LOG);
}


void PerformanceFunctionalTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NeuralNetwork nn;

   unsigned parameters_number;
   Vector<double> parameters;

   PerformanceFunctional pf(&nn);

   pf.destruct_all_terms();
   pf.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

   Vector<double> gradient;

   // Test

   nn.set(1, 1, 1);

   nn.initialize_parameters(0.0);

   parameters = nn.arrange_parameters();

   gradient = pf.calculate_gradient(parameters);

   assert_true(gradient == 0.0, LOG);

   // Test

   parameters_number = nn.count_parameters_number();
   nn.initialize_parameters(0.0);

   MockPerformanceTerm* mptp = new MockPerformanceTerm(&nn);

   pf.set_user_objective_pointer(mptp);

   gradient = pf.calculate_gradient();

   assert_true(gradient.size() == parameters_number, LOG);
   assert_true(gradient == 0.0, LOG);
}


void PerformanceFunctionalTest::test_calculate_gradient_norm(void)
{
   message += "test_calculate_gradient_norm\n";
}

// @todo

void PerformanceFunctionalTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";

   NeuralNetwork nn;
   unsigned parameters_number;
   Vector<double> parameters;
   
   PerformanceFunctional pf(&nn);

   pf.destruct_all_terms();
   pf.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

   Matrix<double> Hessian;

   nn.set(1, 1, 1);

   nn.initialize_parameters(0.0);

   parameters_number = nn.count_parameters_number();
   parameters = nn.arrange_parameters();

   Hessian = pf.calculate_Hessian(parameters);

   assert_true(Hessian.get_rows_number() == parameters_number, LOG);
   assert_true(Hessian.get_columns_number() == parameters_number, LOG);

   nn.set();

   nn.initialize_parameters(0.0);

   parameters_number = nn.count_parameters_number();
   parameters = nn.arrange_parameters();

   Hessian = pf.calculate_Hessian(parameters);

   assert_true(Hessian.get_rows_number() == parameters_number, LOG);
   assert_true(Hessian.get_columns_number() == parameters_number, LOG);

   nn.set(1, 1);

   nn.initialize_parameters(0.0);

   parameters_number = nn.count_parameters_number();
   parameters = nn.arrange_parameters();

   Hessian = pf.calculate_Hessian(parameters);

   assert_true(Hessian.get_rows_number() == parameters_number, LOG);
   assert_true(Hessian.get_columns_number() == parameters_number, LOG);

   // Test

   parameters_number = nn.count_parameters_number();
   nn.initialize_parameters(0.0);

   MockPerformanceTerm* mptp = new MockPerformanceTerm(&nn);

   pf.set_user_objective_pointer(mptp);

   Hessian = pf.calculate_Hessian();

   assert_true(Hessian.get_rows_number() == parameters_number, LOG);
   assert_true(Hessian.get_columns_number() == parameters_number, LOG);

}

// @todo

void PerformanceFunctionalTest::test_calculate_inverse_Hessian(void)
{
   message += "test_calculate_inverse_Hessian\n";

//   NeuralNetwork nn(1, 1);

//   PerformanceFunctional pf(&nn);

//   Matrix<double> Hessian = pf.calculate_Hessian();

//   assert_true(pf.calculate_inverse_Hessian() == Hessian.calculate_inverse(), LOG);

}


// @todo

void PerformanceFunctionalTest::test_calculate_vector_dot_Hessian(void)
{
   message += "test_calculate_vector_dot_Hessian\n";

//   NeuralNetwork nn(1, 1);

//   unsigned parameters_number = nn.count_parameters_number();

//   PerformanceFunctional pf(&nn);

//   Vector<double> vector(0.0, 1.0, parameters_number-1.0);

//   Matrix<double> Hessian = pf.calculate_Hessian();

//   assert_true(pf.calculate_vector_dot_Hessian(vector) == vector.dot(Hessian), LOG);
}


void PerformanceFunctionalTest::test_calculate_terms(void)
{
   message += "test_calculate_terms\n";

   DataSet ds;
   NeuralNetwork nn;
   PerformanceFunctional pf(&nn, &ds);

   pf.set_objective_type(PerformanceFunctional::SUM_SQUARED_ERROR_OBJECTIVE);

   Vector<double> terms;

    // Test

   ds.set(1,1,2);
   ds.initialize_data(0.0);

   nn.set(1,1);
   nn.initialize_parameters(0.0);

   terms = pf.calculate_terms();

   assert_true(terms.size() == 2, LOG);
   assert_true(terms == 0.0, LOG);

}


void PerformanceFunctionalTest::test_calculate_terms_Jacobian(void)
{
   message += "test_calculate_terms_Jacobian\n";

   DataSet ds;
   NeuralNetwork nn;
   PerformanceFunctional pf(&nn, &ds);

   pf.set_objective_type(PerformanceFunctional::SUM_SQUARED_ERROR_OBJECTIVE);

   Matrix<double> terms_Jacobian;

    // Test

   ds.set(1,1,3);
   ds.initialize_data(0.0);

   nn.set(1,1);
   nn.initialize_parameters(0.0);

   terms_Jacobian = pf.calculate_terms_Jacobian();

   assert_true(terms_Jacobian.get_rows_number() == 3, LOG);
   assert_true(terms_Jacobian.get_columns_number() == 2, LOG);
   assert_true(terms_Jacobian == 0.0, LOG);

}


void PerformanceFunctionalTest::test_calculate_zero_order_Taylor_approximation(void)
{
   message += "test_calculate_zero_order_Taylor_approximation\n";
}


void PerformanceFunctionalTest::test_calculate_first_order_Taylor_approximation(void)
{
   message += "test_calculate_first_order_Taylor_approximation\n";
}


void PerformanceFunctionalTest::test_calculate_second_order_Taylor_approximation(void)
{
   message += "test_calculate_second_order_Taylor_approximation\n";
}


void PerformanceFunctionalTest::test_calculate_directional_performance(void)
{
   message += "test_calculate_directional_performance\n";

   NeuralNetwork nn;

   Vector<double> direction;
   double rate;

   PerformanceFunctional pf(&nn);

   // Test

   nn.set(1, 1);

   pf.destruct_all_terms();
   pf.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

   direction.set(2, 1.0e3);

   rate = 1.0e3;

   assert_true(pf.calculate_performance(direction, rate) != pf.calculate_performance(), LOG);
}


void PerformanceFunctionalTest::test_calculate_directional_performance_derivative(void)
{
   message += "test_calculate_directional_performance_derivative\n";

   NeuralNetwork nn;

   Vector<double> direction;
   double rate;

   PerformanceFunctional pf(&nn);

   // Test

   nn.set(1, 1);
   nn.initialize_parameters(0.0);

   pf.destruct_all_terms();
   pf.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

   direction.set(2, 0.0);

   rate = 0.0;

   assert_true(pf.calculate_performance_derivative(direction, rate) == 0.0, LOG);
}


void PerformanceFunctionalTest::test_calculate_directional_performance_second_derivative(void)
{
   message += "test_calculate_directional_performance_second_derivative\n";

   NeuralNetwork nn;

   Vector<double> direction;
   double rate;

   PerformanceFunctional pf(&nn);

   // Test

   nn.set(1, 1);
   nn.initialize_parameters(0.0);

   pf.destruct_all_terms();
   pf.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

   direction.set(2, 0.0);

   rate = 0.0;

   assert_true(pf.calculate_performance_second_derivative(direction, rate) == 0.0, LOG);
}


void PerformanceFunctionalTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   PerformanceFunctional pf;

   pf.set_objective_type(PerformanceFunctional::MINKOWSKI_ERROR_OBJECTIVE);
   pf.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

   tinyxml2::XMLDocument* document = pf.to_XML();

   assert_true(document != NULL, LOG);

   delete document;
}


void PerformanceFunctionalTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   PerformanceFunctional pf1;
   PerformanceFunctional pf2;

   pf1.set_objective_type(PerformanceFunctional::MINKOWSKI_ERROR_OBJECTIVE);
   pf1.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

   tinyxml2::XMLDocument* document = pf1.to_XML();

    pf2.from_XML(*document);

   delete document;

    assert_true(pf2.get_objective_type() == PerformanceFunctional::MINKOWSKI_ERROR_OBJECTIVE, LOG);
    assert_true(pf2.get_regularization_type() == PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION, LOG);

}


void PerformanceFunctionalTest::test_print(void)
{
   message += "test_print\n";

   PerformanceFunctional pf;

//   pf.print();
}


void PerformanceFunctionalTest::test_save(void)
{
   message += "test_save\n";

   std::string file_name = "../data/performance_functional.xml";

   PerformanceFunctional pf;

   pf.set_objective_type(PerformanceFunctional::MINKOWSKI_ERROR_OBJECTIVE);
   pf.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

   pf.save(file_name);
}


void PerformanceFunctionalTest::test_load(void)
{
   message += "test_load\n";

   std::string file_name = "../data/performance_functional.xml";

   PerformanceFunctional pf1;
   PerformanceFunctional pf2;

   // Test

   pf1.set_objective_type(PerformanceFunctional::MINKOWSKI_ERROR_OBJECTIVE);
   pf1.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

   pf1.save(file_name);

   pf2.load(file_name);

   assert_true(pf2.get_objective_type() == PerformanceFunctional::MINKOWSKI_ERROR_OBJECTIVE, LOG);
   assert_true(pf2.get_regularization_type() == PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION, LOG);
}


void PerformanceFunctionalTest::test_write_information(void)
{
   message += "test_write_information\n";

   DataSet ds;
   NeuralNetwork nn;

   PerformanceFunctional pf(&nn, &ds);

   std::string information;

   // Test

   ds.set(1, 1, 2);
   ds.randomize_data_normal();
   nn.set(1, 1);

   information = pf.write_information();

   assert_true(!information.empty(), LOG);
}


void PerformanceFunctionalTest::run_test_case(void)
{
   message += "Running performance functional test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_neural_network_pointer();
   test_get_mathematical_model_pointer();
   test_get_data_set_pointer();

   test_get_user_objective_pointer();
   test_get_user_regularization_pointer();
   test_get_user_constraints_pointer();

   test_get_numerical_differentiation_pointer();

   test_get_display();

   // Set methods

   test_set_neural_network_pointer();
   test_set_numerical_differentiation();

   test_set_default();

   test_set_display();

   // Performance methods

   test_calculate_performance();

   test_calculate_gradient();

   test_calculate_gradient_norm();

   test_calculate_Hessian();

   test_calculate_directional_performance();
   test_calculate_directional_performance_derivative();
   test_calculate_directional_performance_second_derivative();

   test_calculate_inverse_Hessian();

   test_calculate_vector_dot_Hessian();

   test_calculate_terms();
   test_calculate_terms_Jacobian();

   // Taylor approximation methods

   test_calculate_zero_order_Taylor_approximation();
   test_calculate_first_order_Taylor_approximation();
   test_calculate_second_order_Taylor_approximation();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   test_print();
   test_save();
   test_load();

   test_write_information();

   message += "End of performance functional test case.\n";
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
