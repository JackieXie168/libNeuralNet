/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   C O N J U G A T E   G R A D I E N T   T E S T   C L A S S                                                  */
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

// OpenNN includes

#include "../../source/neural_network/neural_network.h"
#include "../../source/training_strategy/conjugate_gradient.h"

// Unit testing includes

#include "conjugate_gradient_test.h"


using namespace OpenNN;

// GENERAL CONSTRUCTOR

ConjugateGradientTest::ConjugateGradientTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

ConjugateGradientTest::~ConjugateGradientTest(void)
{
}


// METHODS

// void test_constructor(void) method

void ConjugateGradientTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   PerformanceFunctional pf;

   // Default constructor

   ConjugateGradient cg1; 
   assert_true(cg1.get_performance_functional_pointer() == NULL, LOG);   

   // Performance functional constructor

   ConjugateGradient cg2(&pf); 
   assert_true(cg2.get_performance_functional_pointer() != NULL, LOG);   

}


// void test_destructor(void) method

void ConjugateGradientTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_training_direction_method(void) method

void ConjugateGradientTest::test_get_training_direction_method(void)
{
   message += "test_get_training_direction_method\n";

   ConjugateGradient cg;

   cg.set_training_direction_method(ConjugateGradient::PR);

   ConjugateGradient::TrainingDirectionMethod training_direction_method = cg.get_training_direction_method();

   assert_true(training_direction_method == ConjugateGradient::PR, LOG);
}


// void test_get_training_direction_method_name(void)

void ConjugateGradientTest::test_get_training_direction_method_name(void)
{
   message += "test_get_training_direction_method_name\n";
}


// void test_set_training_direction_method(void) method

void ConjugateGradientTest::test_set_training_direction_method(void)
{
   message += "test_set_training_direction_method\n";

   ConjugateGradient cg;

   cg.set_training_direction_method(ConjugateGradient::FR);
   assert_true(cg.get_training_direction_method() == ConjugateGradient::FR, LOG);

   cg.set_training_direction_method(ConjugateGradient::PR);
   assert_true(cg.get_training_direction_method() == ConjugateGradient::PR, LOG);
}


// void test_set_reserve_all_training_history(void) method

void ConjugateGradientTest::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   ConjugateGradient cg;
   cg.set_reserve_all_training_history(true);

   assert_true(cg.get_reserve_parameters_history() == true, LOG);
   assert_true(cg.get_reserve_parameters_norm_history() == true, LOG);

   assert_true(cg.get_reserve_evaluation_history() == true, LOG);
   assert_true(cg.get_reserve_gradient_history() == true, LOG);
   assert_true(cg.get_reserve_gradient_norm_history() == true, LOG);

   assert_true(cg.get_reserve_training_direction_history() == true, LOG);
   assert_true(cg.get_reserve_training_rate_history() == true, LOG);
   assert_true(cg.get_reserve_elapsed_time_history() == true, LOG);
   assert_true(cg.get_reserve_generalization_evaluation_history() == true, LOG);
}


// void test_calculate_PR_parameter(void) method
// @todo

void ConjugateGradientTest::test_calculate_PR_parameter(void)
{
   message += "test_calculate_PR_parameter\n";

   DataSet ds(2, 1, 1);
   ds.initialize_data_normal();
   NeuralNetwork nn(1 ,1);
   PerformanceFunctional pf(&nn, &ds);
   ConjugateGradient cg(&pf);

   nn.initialize_parameters(2.0);
   Vector<double> old_gradient = pf.calculate_gradient();

   nn.initialize_parameters(1.0);
   Vector<double> gradient = pf.calculate_gradient();

//   double PR_parameter = cg.calculate_PR_parameter(old_gradient, gradient);

//   assert_true(PR_parameter == 0.0, LOG);
}


// void test_calculate_FR_parameter(void) method
// @todo

void ConjugateGradientTest::test_calculate_FR_parameter(void)
{
   message += "test_calculate_FR_parameter\n";

   DataSet ds(2, 1, 1);
   ds.initialize_data_normal();
   NeuralNetwork nn(1 ,1);
   PerformanceFunctional pf(&nn, &ds);
   ConjugateGradient cg(&pf);

   nn.initialize_parameters(2.0);
   Vector<double> old_gradient = pf.calculate_gradient();

   nn.initialize_parameters(1.0);
   Vector<double> gradient = pf.calculate_gradient();

//   double FR_parameter = cg.calculate_FR_parameter(old_gradient, gradient);

//   assert_true(FR_parameter == 0.25, LOG);
}


// void test_calculate_PR_training_direction(void) method

void ConjugateGradientTest::test_calculate_PR_training_direction(void)
{
   message += "test_calculate_PR_training_direction\n";

   DataSet ds(2, 1, 1);
   ds.initialize_data_normal();
   NeuralNetwork nn(1 ,1);
   PerformanceFunctional pf(&nn, &ds);
   ConjugateGradient cg(&pf);

   nn.initialize_parameters(2.0);
   Vector<double> old_gradient = pf.calculate_gradient();
   Vector<double> old_training_direction = old_gradient;   

   nn.initialize_parameters(1.0);
   Vector<double> gradient = pf.calculate_gradient();

   Vector<double> PR_training_direction 
   = cg.calculate_PR_training_direction(old_gradient, gradient, old_training_direction);

}


// void test_calculate_FR_training_direction(void) method

void ConjugateGradientTest::test_calculate_FR_training_direction(void)
{
   message += "test_calculate_FR_training_direction\n";

   DataSet ds(2, 1, 1);
   ds.initialize_data_normal();
   NeuralNetwork nn(1 ,1);
   PerformanceFunctional pf(&nn, &ds);
   ConjugateGradient cg(&pf);

   nn.initialize_parameters(2.0);
   Vector<double> old_gradient = pf.calculate_gradient();
   Vector<double> old_training_direction = old_gradient;   

   nn.initialize_parameters(1.0);
   Vector<double> gradient = pf.calculate_gradient();
	
   Vector<double> FR_training_direction 
   = cg.calculate_FR_training_direction(old_gradient, gradient, old_training_direction);
}


// void test_calculate_training_direction(void) method

void ConjugateGradientTest::test_calculate_training_direction(void)
{
   message += "test_calculate_training_direction\n";

}


// void test_perform_training(void) method
// @todo

void ConjugateGradientTest::test_perform_training(void)
{
   message += "test_perform_training\n";

   DataSet ds(6, 1, 1);
   ds.initialize_data_normal();

   NeuralNetwork nn(1, 1);

   PerformanceFunctional pf(&nn, &ds);

   ConjugateGradient cg(&pf);

   nn.initialize_parameters(-1.0);

//   double old_performance = pf.calculate_evaluation();

   cg.set_display(false);
   cg.set_maximum_epochs_number(1);

//   cg.perform_training();

//   double performance = pf.calculate_evaluation();

//   assert_true(performance < old_performance, LOG);

   // Minimum parameters increment norm

   nn.initialize_parameters(-1.0);

   double minimum_parameters_increment_norm = 0.1;

   cg.set_minimum_parameters_increment_norm(minimum_parameters_increment_norm);
   cg.set_performance_goal(0.0);
   cg.set_minimum_performance_increase(0.0);
   cg.set_gradient_norm_goal(0.0);
   cg.set_maximum_epochs_number(1000);
   cg.set_maximum_time(1000.0);

//   cg.perform_training();

   // Performance goal

   nn.initialize_parameters(-1.0);

   double performance_goal = 0.1;

   cg.set_minimum_parameters_increment_norm(0.0);
   cg.set_performance_goal(performance_goal);
   cg.set_minimum_performance_increase(0.0);
   cg.set_gradient_norm_goal(0.0);
   cg.set_maximum_epochs_number(1000);
   cg.set_maximum_time(1000.0);

//   cg.perform_training();

//   performance = pf.calculate_evaluation();

//   assert_true(performance < performance_goal, LOG);

   // Minimum evaluation improvement

   nn.initialize_parameters(-1.0);

   double minimum_performance_increase = 0.1;

   cg.set_minimum_parameters_increment_norm(0.0);
   cg.set_performance_goal(0.0);
   cg.set_minimum_performance_increase(minimum_performance_increase);
   cg.set_gradient_norm_goal(0.0);
   cg.set_maximum_epochs_number(1000);
   cg.set_maximum_time(1000.0);

//   cg.perform_training();

   // Gradient norm goal 

   nn.initialize_parameters(-1.0);

   double gradient_norm_goal = 0.1;

   cg.set_minimum_parameters_increment_norm(0.0);
   cg.set_performance_goal(0.0);
   cg.set_minimum_performance_increase(0.0);
   cg.set_gradient_norm_goal(gradient_norm_goal);
   cg.set_maximum_epochs_number(1000);
   cg.set_maximum_time(1000.0);

//   cg.perform_training();

//   double gradient_norm = pf.calculate_gradient().calculate_norm();

//   assert_true(gradient_norm < gradient_norm_goal, LOG);

}


// void test_to_XML(void) method   

void ConjugateGradientTest::test_to_XML(void)   
{
   message += "test_to_XML\n";

   ConjugateGradient cg;

   TiXmlElement* cge = cg.to_XML();
   assert_true(cge != NULL, LOG);
}


// void test_from_XML(void) method

void ConjugateGradientTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   ConjugateGradient cg;

   TiXmlElement* cge = cg.to_XML();
   cg.from_XML(cge);
}


// void run_test_case(void) method

void ConjugateGradientTest::run_test_case(void)
{
   message += "Running conjugate gradient test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_training_direction_method();
   test_get_training_direction_method_name();

   // Set methods

   test_set_training_direction_method();

   // Training methods

   test_calculate_PR_parameter();
   test_calculate_FR_parameter();

   test_calculate_FR_training_direction();
   test_calculate_PR_training_direction();

   test_calculate_training_direction();

   test_perform_training();

   // Training history methods

   test_set_reserve_all_training_history();

   // Serialization methods

   test_to_XML();   
   test_from_XML();

   message += "End of conjugate gradient test case\n";
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
