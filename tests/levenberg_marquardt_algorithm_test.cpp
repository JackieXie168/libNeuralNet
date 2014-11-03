/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   L E V E N B E R G   M A R Q U A R D T   A L G O R I T H M   T E S T   C L A S S                            */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

#include "levenberg_marquardt_algorithm_test.h"

using namespace OpenNN;

// GENERAL CONSTRUCTOR

LevenbergMarquardtAlgorithmTest::LevenbergMarquardtAlgorithmTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

LevenbergMarquardtAlgorithmTest::~LevenbergMarquardtAlgorithmTest(void)
{
}


// METHODS

void LevenbergMarquardtAlgorithmTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   PerformanceFunctional pf;

   // Default constructor

   LevenbergMarquardtAlgorithm lma1; 
   assert_true(lma1.has_performance_functional() == false, LOG);

   // Performance functional constructor

   LevenbergMarquardtAlgorithm lma2(&pf); 
   assert_true(lma2.has_performance_functional() == true, LOG);
}


void LevenbergMarquardtAlgorithmTest::test_destructor(void)
{
   message += "test_destructor\n";
}


void LevenbergMarquardtAlgorithmTest::test_get_damping_parameter(void)
{
   message += "test_get_damping_parameter\n";
}


void LevenbergMarquardtAlgorithmTest::test_get_damping_parameter_factor(void)
{
   message += "test_get_damping_parameter_factor\n";
}


void LevenbergMarquardtAlgorithmTest::test_get_minimum_damping_parameter(void)
{
   message += "test_get_minimum_damping_parameter\n";
}


void LevenbergMarquardtAlgorithmTest::test_get_maximum_damping_parameter(void)
{
   message += "test_get_maximum_damping_parameter\n";
}


void LevenbergMarquardtAlgorithmTest::test_set_damping_parameter(void)
{
   message += "test_set_damping_parameter\n";
}


void LevenbergMarquardtAlgorithmTest::test_set_damping_parameter_factor(void)
{
   message += "test_set_damping_parameter_factor\n";
}


void LevenbergMarquardtAlgorithmTest::test_set_minimum_damping_parameter(void)
{
   message += "test_set_minimum_damping_parameter\n";
}


void LevenbergMarquardtAlgorithmTest::test_set_maximum_damping_parameter(void)
{
   message += "test_set_maximum_damping_parameter\n";
}


void LevenbergMarquardtAlgorithmTest::test_calculate_performance(void)
{
    message += "test_calculate_performance";

    DataSet ds;

    NeuralNetwork nn;

    PerformanceFunctional pf(&nn, &ds);

    Vector<double> terms;

    double performance;

    LevenbergMarquardtAlgorithm lma(&pf);

    // Test

    ds.set(2, 2, 2);
    ds.randomize_data_normal();

    nn.set(2, 2);
    nn.randomize_parameters_normal();

    terms = pf.calculate_terms();

    performance = lma.calculate_performance(terms);

    assert_true(fabs(performance-pf.calculate_performance()) < 1.0e-3, LOG);
}


void LevenbergMarquardtAlgorithmTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   DataSet ds;

   NeuralNetwork nn;

   PerformanceFunctional pf(&nn, &ds);

   Vector<double> terms;
   Matrix<double> terms_Jacobian;

   Vector<double> gradient;

   LevenbergMarquardtAlgorithm lma(&pf);

   // Test

   ds.set(1, 1, 2);
   ds.randomize_data_normal();

   nn.set(1, 1);
   nn.randomize_parameters_normal();

   terms = pf.calculate_terms();

   terms_Jacobian = pf.calculate_terms_Jacobian();

   gradient = lma.calculate_gradient(terms, terms_Jacobian);

   assert_true((gradient-pf.calculate_gradient()).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   nn.set(1, 1);

   nn.randomize_parameters_normal();

   MockPerformanceTerm* mptp = new MockPerformanceTerm(&nn);

   pf.set_user_objective_pointer(mptp);

   terms= pf.calculate_terms();

   terms_Jacobian = pf.calculate_terms_Jacobian();

   gradient = lma.calculate_gradient(terms, terms_Jacobian);

   assert_true(gradient == pf.calculate_gradient(), LOG);

}


void LevenbergMarquardtAlgorithmTest::test_calculate_Hessian_approximation(void)
{
   message += "test_calculate_Hessian_approximation\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;

   unsigned parameters_number;

   Vector<double> parameters;

   DataSet ds;

   PerformanceFunctional pf(&nn, &ds);

   pf.set_objective_type(PerformanceFunctional::SUM_SQUARED_ERROR_OBJECTIVE);

   Matrix<double> terms_Jacobian;
   Matrix<double> Hessian;
   Matrix<double> numerical_Hessian;
   Matrix<double> Hessian_approximation;

   LevenbergMarquardtAlgorithm lma(&pf);
   
   // Test

   nn.set(1, 2);
   nn.initialize_parameters(0.0);

   parameters_number = nn.count_parameters_number();

   ds.set(1,2,2);
   ds.initialize_data(0.0);

   terms_Jacobian = pf.calculate_terms_Jacobian();

   Hessian_approximation = lma.calculate_Hessian_approximation(terms_Jacobian);

   assert_true(Hessian_approximation.get_rows_number() == parameters_number, LOG);
   assert_true(Hessian_approximation.get_columns_number() == parameters_number, LOG);
   assert_true(Hessian_approximation.is_symmetric(), LOG);

   // Test

   pf.set_objective_type(PerformanceFunctional::NORMALIZED_SQUARED_ERROR_OBJECTIVE);

   nn.set(1,1,2);
   nn.randomize_parameters_normal();

   parameters_number = nn.count_parameters_number();

   ds.set(1,2,3);
   ds.randomize_data_normal();

   terms_Jacobian = pf.calculate_terms_Jacobian();

   Hessian_approximation = lma.calculate_Hessian_approximation(terms_Jacobian);

   assert_true(Hessian_approximation.get_rows_number() == parameters_number, LOG);
   assert_true(Hessian_approximation.get_columns_number() == parameters_number, LOG);
   assert_true(Hessian_approximation.is_symmetric(), LOG);

   // Test

   nn.set(2);

   nn.randomize_parameters_normal();

   MockPerformanceTerm* mptp = new MockPerformanceTerm(&nn);

   pf.set_user_objective_pointer(mptp);

   terms_Jacobian = pf.calculate_terms_Jacobian();

   Hessian = pf.calculate_Hessian();

   lma.set_damping_parameter(0.0);

   assert_true((lma.calculate_Hessian_approximation(terms_Jacobian) - Hessian).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   pf.set_objective_type(PerformanceFunctional::SUM_SQUARED_ERROR_OBJECTIVE);

   ds.set(1, 1, 1);

   ds.randomize_data_normal();

   nn.set(1, 1);

   parameters = nn.arrange_parameters();

   nn.randomize_parameters_normal();

   numerical_Hessian = nd.calculate_Hessian(pf, &PerformanceFunctional::calculate_performance, parameters);

   terms_Jacobian = pf.calculate_terms_Jacobian();

   Hessian_approximation = lma.calculate_Hessian_approximation(terms_Jacobian);

   assert_true((numerical_Hessian - Hessian_approximation).calculate_absolute_value() >= 0.0, LOG);


}


void LevenbergMarquardtAlgorithmTest::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   LevenbergMarquardtAlgorithm lma;
   lma.set_reserve_all_training_history(true);

   assert_true(lma.get_reserve_parameters_history() == true, LOG);
   assert_true(lma.get_reserve_parameters_norm_history() == true, LOG);

   assert_true(lma.get_reserve_performance_history() == true, LOG);
   assert_true(lma.get_reserve_generalization_performance_history() == true, LOG);
   assert_true(lma.get_reserve_gradient_history() == true, LOG);
   assert_true(lma.get_reserve_gradient_norm_history() == true, LOG);
   assert_true(lma.get_reserve_Hessian_approximation_history() == true, LOG);

   assert_true(lma.get_reserve_damping_parameter_history() == true, LOG);
   assert_true(lma.get_reserve_elapsed_time_history() == true, LOG);
}


void LevenbergMarquardtAlgorithmTest::test_perform_training(void)
{
   message += "test_perform_training\n";

   NeuralNetwork nn;
   
   DataSet ds;
   
   PerformanceFunctional pf(&nn, &ds);
   Vector<double> gradient;

   LevenbergMarquardtAlgorithm lma(&pf);
   lma.set_display(false);

   double old_performance;
   double performance;
   double minimum_parameters_increment_norm;
   double performance_goal;
   double minimum_performance_increase;
   double gradient_norm_goal;
   double gradient_norm;

   // Test

   nn.set(1, 1, 1);
   nn.randomize_parameters_normal(0.0, 1.0e-3);

   ds.set(1, 1, 2);
   ds.randomize_data_normal(0.0, 1.0e-3);

   old_performance = pf.calculate_performance();

   lma.perform_training();

   performance = pf.calculate_performance();

   assert_true(performance < old_performance, LOG);

   // Minimum parameters increment norm

   nn.randomize_parameters_normal(0.0, 1.0e-3);

   minimum_parameters_increment_norm = 100.0;

   lma.set_minimum_parameters_increment_norm(minimum_parameters_increment_norm);
   lma.set_performance_goal(0.0);
   lma.set_minimum_performance_increase(0.0);
   lma.set_gradient_norm_goal(0.0);
   lma.set_maximum_iterations_number(10);
   lma.set_maximum_time(10.0);

   lma.perform_training();

   // Performance goal

   nn.randomize_parameters_normal(0.0, 1.0e-3);

   performance_goal = 100.0;

   lma.set_minimum_parameters_increment_norm(0.0);
   lma.set_performance_goal(performance_goal);
   lma.set_minimum_performance_increase(0.0);
   lma.set_gradient_norm_goal(0.0);
   lma.set_maximum_iterations_number(10);
   lma.set_maximum_time(10.0);

   lma.perform_training();

   performance = pf.calculate_performance();

   assert_true(performance < performance_goal, LOG);

   // Minimum performance increas

   nn.randomize_parameters_normal(0.0, 1.0e-3);

   minimum_performance_increase = 100.0;

   lma.set_minimum_parameters_increment_norm(0.0);
   lma.set_performance_goal(0.0);
   lma.set_minimum_performance_increase(minimum_performance_increase);
   lma.set_gradient_norm_goal(0.0);
   lma.set_maximum_iterations_number(10);
   lma.set_maximum_time(10.0);

   lma.perform_training();

   // Gradient norm goal 

   nn.randomize_parameters_normal(0.0, 1.0e-3);

   gradient_norm_goal = 1.0e6;

   lma.set_minimum_parameters_increment_norm(0.0);
   lma.set_performance_goal(0.0);
   lma.set_minimum_performance_increase(0.0);
   lma.set_gradient_norm_goal(gradient_norm_goal);
   lma.set_maximum_iterations_number(10);
   lma.set_maximum_time(10.0);

   lma.perform_training();

   gradient = pf.calculate_gradient();
   gradient_norm = gradient.calculate_norm();

   assert_true(gradient_norm < gradient_norm_goal, LOG);
}


void LevenbergMarquardtAlgorithmTest::test_resize_training_history(void)
{
   message += "test_resize_training_history\n";

   LevenbergMarquardtAlgorithm lma;

   lma.set_reserve_all_training_history(true);

   LevenbergMarquardtAlgorithm::LevenbergMarquardtAlgorithmResults lmatr(&lma);

   lmatr.resize_training_history(1);

   assert_true(lmatr.parameters_history.size() == 1, LOG);
   assert_true(lmatr.parameters_norm_history.size() == 1, LOG);

   assert_true(lmatr.performance_history.size() == 1, LOG);
   assert_true(lmatr.generalization_performance_history.size() == 1, LOG);
   assert_true(lmatr.gradient_history.size() == 1, LOG);
   assert_true(lmatr.gradient_norm_history.size() == 1, LOG);
   assert_true(lmatr.Hessian_approximation_history.size() == 1, LOG);

   assert_true(lmatr.damping_parameter_history.size() == 1, LOG);
   assert_true(lmatr.elapsed_time_history.size() == 1, LOG);

}


void LevenbergMarquardtAlgorithmTest::test_to_XML(void)   
{
   message += "test_to_XML\n";

   LevenbergMarquardtAlgorithm lma;

   tinyxml2::XMLDocument* lmad = lma.to_XML();
   
   assert_true(lmad != NULL, LOG);
}


void LevenbergMarquardtAlgorithmTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   LevenbergMarquardtAlgorithm lma;
}


void LevenbergMarquardtAlgorithmTest::run_test_case(void)
{
   message += "Running Levenberg-Marquardt algorithm test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_damping_parameter();

   test_get_damping_parameter_factor();

   test_get_minimum_damping_parameter();
   test_get_maximum_damping_parameter();

   // Set methods

   test_set_damping_parameter();

   test_set_damping_parameter_factor();

   test_set_minimum_damping_parameter();
   test_set_maximum_damping_parameter();

   // Training methods

   test_calculate_performance();
   test_calculate_gradient();
   test_calculate_Hessian_approximation();

   test_perform_training();

   // Training history methods

   test_set_reserve_all_training_history();
   test_resize_training_history();

   // Serialization methods

   test_to_XML();   
   test_from_XML();

   message += "End of Levenberg-Marquardt algorithm test case.\n";
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
