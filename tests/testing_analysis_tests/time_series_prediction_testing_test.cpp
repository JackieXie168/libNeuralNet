/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: An Open Source Neural Networks C++ Library                                                          */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   T I M E   S E R I E S   P R E D I C T I O N   T E S T I N G   T E S T   C L A S S                          */
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

#include "../../source/utilities/vector.h"
#include "../../source/utilities/matrix.h"

#include "../../source/neural_network/neural_network.h"
#include "../../source/data_set/data_set.h"
#include "../../source/testing_analysis/time_series_prediction_testing.h"

// Unit testing includes

#include "time_series_prediction_testing_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

TimeSeriesPredictionTestingTest::TimeSeriesPredictionTestingTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

TimeSeriesPredictionTestingTest::~TimeSeriesPredictionTestingTest(void)
{
}


// METHODS

// void test_constructor(void) method

void TimeSeriesPredictionTestingTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor

   TimeSeriesPredictionTesting tspt1;

   assert_true(tspt1.get_neural_network_pointer() == NULL, LOG);
   assert_true(tspt1.get_data_set_pointer() == NULL, LOG);

   // Neural network constructor

   NeuralNetwork nn2;
   TimeSeriesPredictionTesting tsptu2(&nn2);

   assert_true(tsptu2.get_neural_network_pointer() != NULL, LOG);
   assert_true(tsptu2.get_data_set_pointer() == NULL, LOG);

   // Data set constructor

   DataSet ds3;
   TimeSeriesPredictionTesting tspt3(&ds3);

   assert_true(tspt3.get_neural_network_pointer() == NULL, LOG);
   assert_true(tspt3.get_data_set_pointer() != NULL, LOG);

   // Neural network and data set constructor

   NeuralNetwork nn4;
   DataSet ds4;

   TimeSeriesPredictionTesting tspt4(&nn4, &ds4);

   assert_true(tspt4.get_neural_network_pointer() != NULL, LOG);
   assert_true(tspt4.get_data_set_pointer() != NULL, LOG);

}


// void test_destructor(void) method

void TimeSeriesPredictionTestingTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// Get methods

// void test_get_neural_network_pointer(void) method

void TimeSeriesPredictionTestingTest::test_get_neural_network_pointer(void)
{
   message += "test_get_neural_network_pointer\n";

   TimeSeriesPredictionTesting mu;

   assert_true(mu.get_neural_network_pointer() == NULL, LOG);

   NeuralNetwork nn;

   mu.set_neural_network_pointer(&nn);
   
   assert_true(mu.get_neural_network_pointer() != NULL, LOG);

}


// void test_get_data_set_pointer(void) method

void TimeSeriesPredictionTestingTest::test_get_data_set_pointer(void)
{
   message += "test_get_data_set_pointer\n";

   TimeSeriesPredictionTesting mu;

   assert_true(mu.get_data_set_pointer() == NULL, LOG);

   DataSet ds;

   mu.set_data_set_pointer(&ds);
   
   assert_true(mu.get_data_set_pointer() != NULL, LOG);

}


// void test_get_display(void) method

void TimeSeriesPredictionTestingTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_neural_network_pointer(void) method

void TimeSeriesPredictionTestingTest::test_set_neural_network_pointer(void)
{
   message += "test_set_neural_network_pointer\n";
}


// void test_set_data_set_pointer(void) method

void TimeSeriesPredictionTestingTest::test_set_data_set_pointer(void)
{
   message += "test_set_data_set_pointer\n";
}


// void test_set_display(void) method

void TimeSeriesPredictionTestingTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void run_test_case(void) method

void TimeSeriesPredictionTestingTest::run_test_case(void)
{
   message += "Running time series prediction testing test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_neural_network_pointer();
   test_get_data_set_pointer();
   
   test_get_display();

   // Set methods

   test_set_neural_network_pointer();
   test_set_data_set_pointer();

   test_set_display();

   message += "End of time series prediction testing test case\n";
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the s of the GNU Lesser General Public
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
