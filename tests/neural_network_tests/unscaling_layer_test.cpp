/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   U N S C A L I N G   L A Y E R   T E S T   C L A S S                                                        */
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
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>   

// OpenNN incldues

#include "../../source/utilities/numerical_differentiation.h"
#include "../../source/neural_network/unscaling_layer.h"

// Unit testing includes

#include "unscaling_layer_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR

UnscalingLayerTest::UnscalingLayerTest(void) : UnitTesting()
{
}


// DESTRUCTOR

UnscalingLayerTest::~UnscalingLayerTest(void)
{
}


// METHODS

// void test_constructor(void) method

void UnscalingLayerTest::test_constructor(void)
{
   message += "test_constructor\n";

}


// void test_destructor(void)

void UnscalingLayerTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_assignment_operator(void)

void UnscalingLayerTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   UnscalingLayer mlp_1;
   UnscalingLayer mlp_2 = mlp_1;

   assert_true(mlp_2.count_unscaling_neurons_number() == 0, LOG);

}


// void test_count_unscaling_neurons_number(void) method

void UnscalingLayerTest::test_count_unscaling_neurons_number(void)
{
   message += "test_count_unscaling_neurons_number\n";

   UnscalingLayer ul;

   assert_true(ul.count_unscaling_neurons_number() == 0, LOG);
}


// void test_set(void) method

void UnscalingLayerTest::test_set(void)
{
   message += "test_set\n";
}


// void test_set_default(void) method

void UnscalingLayerTest::test_set_default(void)
{
   message += "test_set_default\n";
}


// void test_get_means(void) method

void UnscalingLayerTest::test_get_means(void)
{
   message += "test_get_means\n";

   UnscalingLayer ul;

   assert_true(ul.get_means() == 0, LOG);
}


// void test_get_standard_deviations(void) method

void UnscalingLayerTest::test_get_standard_deviations(void)
{
   message += "test_get_standard_deviations\n";

   UnscalingLayer ul;

   assert_true(ul.get_standard_deviations() == 0, LOG);
}


// void test_get_means_standard_deviations(void) method

void UnscalingLayerTest::test_get_means_standard_deviations(void)
{
   message += "test_get_means_standard_deviations\n";
}


// void test_get_mean(void) method

void UnscalingLayerTest::test_get_mean(void)
{
   message += "test_get_mean\n";
}


// void test_get_standard_deviation(void) method

void UnscalingLayerTest::test_get_standard_deviation(void)
{
   message += "test_get_standard_deviation\n";
}


// void test_get_minimums(void) method

void UnscalingLayerTest::test_get_minimums(void)
{
   message += "test_get_minimums\n";
}


// void test_get_maximums(void) method

void UnscalingLayerTest::test_get_maximums(void)
{
   message += "test_get_maximums\n";
}


// void test_get_minimums_maximums(void) method

void UnscalingLayerTest::test_get_minimums_maximums(void)
{
   message += "test_get_minimums_maximums\n";
}


// void test_get_minimum(void) method

void UnscalingLayerTest::test_get_minimum(void)
{
   message += "test_get_minimum\n";
}


// void test_get_maximum(void) method

void UnscalingLayerTest::test_get_maximum(void)
{
   message += "test_get_maximum\n";
}


// void test_get_statistics(void) method

void UnscalingLayerTest::test_get_statistics(void)
{
   message += "test_get_statistics\n";

   UnscalingLayer ul;

   Vector< Vector<double>* > statistics;

   // Test

   statistics = ul.get_statistics();

   assert_true(statistics.size() == 4, LOG);
}


// void test_get_display(void) method

void UnscalingLayerTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_unscaling_method(void) method

void UnscalingLayerTest::test_set_unscaling_method(void)
{
   message += "test_set_unscaling_method\n";
}


// void test_set_means(void) method

void UnscalingLayerTest::test_set_means(void)
{
   message += "test_set_means\n";
}


// void test_set_standard_deviations(void) method

void UnscalingLayerTest::test_set_standard_deviations(void)
{
   message += "test_set_standard_deviations\n";
}


// void test_set_means_standard_deviations(void) method

void UnscalingLayerTest::test_set_means_standard_deviations(void)
{
   message += "test_set_means_standard_deviation\n";
}


// void test_set_mean(void) method

void UnscalingLayerTest::test_set_mean(void)
{
   message += "test_set_mean\n";
}


// void test_set_standard_deviation(void) method

void UnscalingLayerTest::test_set_standard_deviation(void)
{
   message += "test_set_standard_deviation\n";
}


// void test_set_minimums(void) method

void UnscalingLayerTest::test_set_minimums(void)
{
   message += "test_set_minimums\n";
}


// void test_set_maximums(void) method

void UnscalingLayerTest::test_set_maximums(void)
{
   message += "test_set_outputs_maximum\n";
}


// void test_set_minimums_maximums(void) method

void UnscalingLayerTest::test_set_minimums_maximums(void)
{
   message += "test_set_minimums_maximums\n";
}


// void test_set_minimum(void) method

void UnscalingLayerTest::test_set_minimum(void)
{
   message += "test_set_minimum\n";
}


// void test_set_maximum(void) method

void UnscalingLayerTest::test_set_maximum(void)
{
   message += "test_set_maximum\n";
}


// void test_set_statistics(void) method

void UnscalingLayerTest::test_set_statistics(void)
{
   message += "test_set_statistics\n";
}


// void test_set_display(void) method

void UnscalingLayerTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_initialize_random(void) method

void UnscalingLayerTest::test_initialize_random(void)
{
   message += "test_initialize_random\n";

   UnscalingLayer ul;

   // Test

   ul.initialize_random();
}


// void test_calculate_outputs(void) method

void UnscalingLayerTest::test_calculate_outputs(void)
{
   message += "test_calculate_outputs\n";

   UnscalingLayer ul(1);

   Vector<double> inputs(1);

   ul.set_display(false);

   // Test

   ul.set_unscaling_method(UnscalingLayer::MinimumMaximum);

   ul.set_minimum(0, -1.0);
   ul.set_maximum(0,  1.0);

   inputs[0] = 0.0;

   assert_true(ul.calculate_outputs(inputs) == inputs, LOG);

   // Test

   ul.set_unscaling_method(UnscalingLayer::MeanStandardDeviation);

   ul.set_mean(0, 0.0);
   ul.set_standard_deviation(0, 1.0);

   inputs[0] = 0.0;

   assert_true(ul.calculate_outputs(inputs) == inputs, LOG);
}


// void test_calculate_derivative(void) method

void UnscalingLayerTest::test_calculate_derivative(void)
{
   message += "test_calculate_derivative\n";

   NumericalDifferentiation nd;

   UnscalingLayer ul;

   Vector<double> maximums;
   Vector<double> minimums;

   Vector<double> means;
   Vector<double> standard_deviations;

   ul.set_display(false);

   Vector<double> inputs;
   Vector<double> derivative;
   Vector<double> numerical_derivative;

   // Test

   ul.set(1);

   ul.set_unscaling_method(UnscalingLayer::MinimumMaximum);

   ul.set_minimum(0, -1.0);
   ul.set_maximum(0,  1.0);

   inputs.set(1, 0.0);

   derivative = ul.calculate_derivative(inputs);

   assert_true(derivative == 1.0, LOG);

   // Test

   ul.set(1);

   ul.set_unscaling_method(UnscalingLayer::MeanStandardDeviation);

   ul.set_mean(0, 0.0);
   ul.set_standard_deviation(0, 1.0);

   inputs.set(1, 0.0);

   derivative = ul.calculate_derivative(inputs);

   assert_true(derivative == 1.0, LOG);

   // Test

   if(numerical_differentiation_tests)
   {
      ul.set(3);

      ul.set_unscaling_method(UnscalingLayer::MinimumMaximum);

      minimums.set(3);
      minimums.initialize_uniform(-2.0, -1.0);
      ul.set_minimums(minimums);

      maximums.set(3);
      maximums.initialize_uniform(1.0, 2.0);
      ul.set_maximums(maximums);

      inputs.set(3);
      inputs.initialize_normal();

      derivative = ul.calculate_derivative(inputs);
      numerical_derivative = nd.calculate_derivative(ul, &UnscalingLayer::calculate_outputs, inputs);

      assert_true((derivative-numerical_derivative).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   if(numerical_differentiation_tests)
   {
      ul.set(3);

      ul.set_unscaling_method(UnscalingLayer::MeanStandardDeviation);

      means.set(3);
      means.initialize_uniform(-2.0, -1.0);
      ul.set_means(means);

      standard_deviations.set(3);
      standard_deviations.initialize_uniform(1.0, 2.0);
      ul.set_standard_deviations(standard_deviations);

      inputs.set(3);
      inputs.initialize_normal();

      derivative = ul.calculate_derivative(inputs);
      numerical_derivative = nd.calculate_derivative(ul, &UnscalingLayer::calculate_outputs, inputs);

      assert_true((derivative-numerical_derivative).calculate_absolute_value() < 1.0e-3, LOG);
   }
   
}


// void test_calculate_second_derivative(void) method

void UnscalingLayerTest::test_calculate_second_derivative(void)
{
   message += "test_calculate_second_derivative\n";
}


// void test_write_expression(void) method
// @todo

void UnscalingLayerTest::test_write_expression(void)
{
   message += "test_write_expression\n";
}


// void test_get_unscaling_method(void) method

void UnscalingLayerTest::test_get_unscaling_method(void)
{
   message += "test_get_unscaling_method\n";

   UnscalingLayer ul;

   // Test

   ul.set_unscaling_method(UnscalingLayer::MeanStandardDeviation);

   assert_true(ul.get_unscaling_method() == UnscalingLayer::MeanStandardDeviation, LOG);

   // Test

   ul.set_unscaling_method(UnscalingLayer::MinimumMaximum);

   assert_true(ul.get_unscaling_method() == UnscalingLayer::MinimumMaximum, LOG);
}


// void test_get_unscaling_method_name(void) method

void UnscalingLayerTest::test_get_unscaling_method_name(void)
{
   message += "test_get_outputs_method_name\n";
}


// void test_to_XML(void) method

void UnscalingLayerTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   UnscalingLayer  ul;

   TiXmlElement* ule;
   
   // Test

   ule = ul.to_XML();

   assert_true(ule != NULL, LOG);
}


// void test_from_XML(void) method

void UnscalingLayerTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   UnscalingLayer  ul;

   TiXmlElement* ule;
   
   // Test

   ul.from_XML(NULL);

   // Test

   ule = ul.to_XML();

   ul.from_XML(ule);
}


// void run_test_case(void) method

void UnscalingLayerTest::run_test_case(void)
{
   message += "Running unscaling layer test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   // Unscaling layer architecture

   test_count_unscaling_neurons_number();

   // Output variables statistics

   test_get_minimums();
   test_get_minimum();

   test_get_maximums();
   test_get_maximum();

   test_get_means();
   test_get_mean();

   test_get_standard_deviations();
   test_get_standard_deviation();

   test_get_minimums_maximums();
   test_get_means_standard_deviations();

   // Variables statistics

   test_get_statistics();

   // Variables scaling and unscaling

   test_get_unscaling_method();
   test_get_unscaling_method_name();

   // Display messages

   test_get_display();

   // Set methods

   test_set();
   test_set_default();

   // Output variables statistics

   test_set_minimums();
   test_set_minimum();

   test_set_maximums();
   test_set_maximum();

   test_set_means();
   test_set_mean();

   test_set_standard_deviations();
   test_set_standard_deviation();

   test_set_minimums_maximums();
   test_set_means_standard_deviations();

   // Variables statistics

   test_set_statistics();

   // Display messages

   test_set_display();

   // Initialization methods

   test_initialize_random();

   // Scaling and unscaling

   test_calculate_outputs();
   test_calculate_derivative();
   test_calculate_second_derivative();

   // Expression methods

   test_write_expression();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of unscaling layer test case\n";
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
