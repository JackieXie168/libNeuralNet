/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   N E W T O N   M E T H O D   T E S T   C L A S S                                                            */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "../../source/neural_network/neural_network.h"
#include "../../source/training_strategy/newton_method.h"

// Unit testing includes

#include "newton_method_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

NewtonMethodTest::NewtonMethodTest(void) : UnitTesting() 
{   
}


// DESTRUCTOR

NewtonMethodTest::~NewtonMethodTest(void)
{
}


// void test_constructor(void) method

void NewtonMethodTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   PerformanceFunctional mof;

   // Default constructor

   NewtonMethod nm1; 
   assert_true(nm1.get_performance_functional_pointer() == NULL, LOG);   

   // Objective functional constructor

   NewtonMethod nm2(&mof); 
   assert_true(nm2.get_performance_functional_pointer() != NULL, LOG);   
}


// void test_destructor(void) method

void NewtonMethodTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_calculate_gradient_descent_training_direction(void) method

void NewtonMethodTest::test_calculate_gradient_descent_training_direction(void)
{
   message += "test_calculate_gradient_descent_training_direction\n";

   DataSet ds(2, 1, 1);

   NeuralNetwork nn(1, 1);
   
   PerformanceFunctional pf(&nn);
   
   NewtonMethod nm(&pf);

   Vector<double> gradient(1, 1.0);

   Vector<double> gradient_descent_training_direction = nm.calculate_gradient_descent_training_direction(gradient);

   assert_true(gradient_descent_training_direction.size() == 1, LOG);
   assert_true(gradient_descent_training_direction == -1.0, LOG);

}


// void test_calculate_training_direction(void) method

void NewtonMethodTest::test_calculate_training_direction(void)
{
   message += "test_calculate_training_direction\n";

}

// void test_perform_training(void) method

/// @todo

void NewtonMethodTest::test_perform_training(void)
{
   message += "test_perform_training\n";

   DataSet ds(2, 1, 1);
   ds.initialize_data_normal();

   NeuralNetwork nn(1, 1);
   PerformanceFunctional pf(&nn, &ds);
   NewtonMethod nm(&pf);

   nn.initialize_parameters(0.1);

//   double old_performance = pf.calculate_evaluation();

   nm.set_display(false);
   nm.set_maximum_epochs_number(1);
//   nm.perform_training();

//   double performance = pf.calculate_evaluation();
   
//   assert_true(evaluation < old_performance, LOG);

   // Minimum parameters increment norm

   nn.initialize_parameters(1.0);

   double minimum_parameters_increment_norm = 0.1;

   nm.set_minimum_parameters_increment_norm(minimum_parameters_increment_norm);
   nm.set_performance_goal(0.0);
   nm.set_minimum_performance_increase(0.0);
   nm.set_gradient_norm_goal(0.0);
   nm.set_maximum_epochs_number(1000);
   nm.set_maximum_time(1000.0);

//   nm.perform_training();

   // Performance goal

   nn.initialize_parameters(1.0);

   double performance_goal = 0.1;

   nm.set_minimum_parameters_increment_norm(0.0);
   nm.set_performance_goal(performance_goal);
   nm.set_minimum_performance_increase(0.0);
   nm.set_gradient_norm_goal(0.0);
   nm.set_maximum_epochs_number(1000);
   nm.set_maximum_time(1000.0);

//   nm.perform_training();

//   performance = pf.calculate_evaluation();

//   assert_true(performance < performance_goal, LOG);

   // Minimum evaluation improvement

   nn.initialize_parameters(1.0);

   double minimum_performance_increase = 0.1;

   nm.set_minimum_parameters_increment_norm(0.0);
   nm.set_performance_goal(0.0);
   nm.set_minimum_performance_increase(minimum_performance_increase);
   nm.set_gradient_norm_goal(0.0);
   nm.set_maximum_epochs_number(1000);
   nm.set_maximum_time(1000.0);

//   nm.perform_training();

   // Gradient norm goal 

   nn.initialize_parameters(1.0);

   double gradient_norm_goal = 0.1;

   nm.set_minimum_parameters_increment_norm(0.0);
   nm.set_performance_goal(0.0);
   nm.set_minimum_performance_increase(0.0);
   nm.set_gradient_norm_goal(gradient_norm_goal);
   nm.set_maximum_epochs_number(1000);
   nm.set_maximum_time(1000.0);

//   nm.perform_training();

//   double gradient_norm = pf.calculate_gradient_norm();

//   assert_true(gradient_norm < gradient_norm_goal, LOG);

}


// void test_to_XML(void) method

void NewtonMethodTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   NewtonMethod nm;

   TiXmlElement* nme = nm.to_XML();

   assert_true(nme != 0, LOG);
}


// void test_from_XML(void) method

void NewtonMethodTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   NewtonMethod nm;

   TiXmlElement* nme = nm.to_XML();

   nm.from_XML(nme);
}


// void test_resize_training_history(void) method

void NewtonMethodTest::test_resize_training_history(void)
{
   message += "test_resize_training_history\n";

   NewtonMethod nm;

   nm.set_reserve_all_training_history(true);

   NewtonMethod::NewtonMethodResults nmtr;

   nmtr.resize_training_history(1);

   assert_true(nmtr.parameters_history.size() == 1, LOG);
   assert_true(nmtr.parameters_norm_history.size() == 1, LOG);

   assert_true(nmtr.evaluation_history.size() == 1, LOG);
   assert_true(nmtr.gradient_history.size() == 1, LOG);
   assert_true(nmtr.gradient_norm_history.size() == 1, LOG);
   assert_true(nmtr.inverse_Hessian_history.size() == 1, LOG);
   assert_true(nmtr.generalization_evaluation_history.size() == 1, LOG);  

   assert_true(nmtr.training_direction_history.size() == 1, LOG);
   assert_true(nmtr.training_rate_history.size() == 1, LOG);
   assert_true(nmtr.elapsed_time_history.size() == 1, LOG);
}


// void test_set_reserve_all_training_history(void) method

void NewtonMethodTest::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   NewtonMethod nm;
   nm.set_reserve_all_training_history(true);

   assert_true(nm.get_reserve_parameters_history() == true, LOG);
   assert_true(nm.get_reserve_parameters_norm_history() == true, LOG);

   assert_true(nm.get_reserve_evaluation_history() == true, LOG);
   assert_true(nm.get_reserve_gradient_history() == true, LOG);
   assert_true(nm.get_reserve_gradient_norm_history() == true, LOG);
   assert_true(nm.get_reserve_inverse_Hessian_history() == true, LOG);

   assert_true(nm.get_reserve_training_direction_history() == true, LOG);
   assert_true(nm.get_reserve_training_rate_history() == true, LOG);
   assert_true(nm.get_reserve_elapsed_time_history() == true, LOG);
   assert_true(nm.get_reserve_generalization_evaluation_history() == true, LOG);
}


// void run_test_case(void) method

void NewtonMethodTest::run_test_case(void)
{
   message += "Running Newton method test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Training methods

   test_calculate_gradient_descent_training_direction();
   test_calculate_training_direction();

   test_perform_training();

   // Training history methods

   test_resize_training_history();
   test_set_reserve_all_training_history();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of Newton method test case...\n";
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
