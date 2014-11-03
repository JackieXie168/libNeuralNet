/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   P R O B A B I L I S T I C   L A Y E R   T E S T   C L A S S                                                */
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
#include "../../source/neural_network/neural_network.h"

// Unit testing includes

#include "probabilistic_layer_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR

ProbabilisticLayerTest::ProbabilisticLayerTest(void) : UnitTesting()
{
}


// DESTRUCTOR

ProbabilisticLayerTest::~ProbabilisticLayerTest(void)
{
}


// METHODS

// void test_constructor(void) method

void ProbabilisticLayerTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor

   ProbabilisticLayer pl1;

   assert_true(pl1.get_probabilistic_neurons_number() == 0, LOG);

   // Probabilistic neurons number constructor

   ProbabilisticLayer pl2(3);

   assert_true(pl2.get_probabilistic_neurons_number() == 3, LOG);

   // Copy constructor

   ProbabilisticLayer pl3(pl2);

   assert_true(pl3.get_probabilistic_neurons_number() == 3, LOG);
}


// void test_destructor(void)

void ProbabilisticLayerTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_assignment_operator(void)

void ProbabilisticLayerTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   ProbabilisticLayer pl1;
   ProbabilisticLayer pl2;

   // Test

   pl1.set(2);

   pl2 = pl1;

   assert_true(pl2.get_probabilistic_neurons_number() == 2, LOG);

}


// void test_count_probabilistic_neurons_number(void) method

void ProbabilisticLayerTest::test_count_probabilistic_neurons_number(void)
{
   message += "test_count_probabilistic_neurons_number\n";

   ProbabilisticLayer pl;

   // Test

   pl.set();
   assert_true(pl.get_probabilistic_neurons_number() == 0, LOG);

   // Test

   pl.set(1);
   assert_true(pl.get_probabilistic_neurons_number() == 1, LOG);

}


// void test_set(void) method

void ProbabilisticLayerTest::test_set(void)
{
   message += "test_set\n";
}


// void test_set_default(void) method

void ProbabilisticLayerTest::test_set_default(void)
{
   message += "test_set_default\n";
}


// void test_get_probabilistic_layer_flag(void) method

void ProbabilisticLayerTest::test_get_probabilistic_layer_flag(void)
{
   message += "test_get_probabilistic_layer_flag\n";
}


// void test_get_display(void) method

void ProbabilisticLayerTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_probabilistic_flag(void) method

void ProbabilisticLayerTest::test_set_probabilistic_flag(void)
{
   message += "test_set_probabilistic_flag\n";
}


// void test_set_display(void) method

void ProbabilisticLayerTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_initialize_random(void) method

void ProbabilisticLayerTest::test_initialize_random(void)
{
   message += "test_initialize_random\n";

   ProbabilisticLayer pl;

   // Test

   pl.initialize_random();
}


// void test_calculate_outputs(void) method

void ProbabilisticLayerTest::test_calculate_outputs(void)
{
   message += "test_calculate_outputs\n";

   ProbabilisticLayer pl;
   Vector<double> inputs;
   Vector<double> outputs;

   // Test

   pl.set(1);

   pl.set_probabilistic_method(ProbabilisticLayer::Competitive);

   inputs.set(1, 0.0);
   outputs = pl.calculate_outputs(inputs);

   assert_true(outputs.size() == 1, LOG);
   assert_true(outputs == 1.0, LOG);

   // Test

   pl.set(1);
   pl.set_probabilistic_method(ProbabilisticLayer::Softmax);

   inputs.set(1, 0.0);
   outputs = pl.calculate_outputs(inputs);

   assert_true(outputs.size() == 1, LOG);
   assert_true(outputs == 1.0, LOG);
}


// void test_calculate_Jacobian(void) method

void ProbabilisticLayerTest::test_calculate_Jacobian(void)
{
   message += "test_calculate_Jacobian\n";

   NumericalDifferentiation nd;

   ProbabilisticLayer pl;

   Vector<double> inputs;
   Matrix<double> Jacobian;
   Matrix<double> numerical_Jacobian;

   // Test

   if(numerical_differentiation_tests)
   {
      pl.set_probabilistic_method(ProbabilisticLayer::Softmax);

      pl.set(3);

      inputs.set(3);
      inputs.initialize_normal();

      Jacobian = pl.calculate_Jacobian(inputs);
      numerical_Jacobian = nd.calculate_Jacobian(pl, &ProbabilisticLayer::calculate_outputs, inputs);

      assert_true((Jacobian-numerical_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }
}


// void test_to_XML(void) method

void ProbabilisticLayerTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   ProbabilisticLayer  pl;
   TiXmlElement* ple;

   // Test

   ple = pl.to_XML();

   assert_true(ple != NULL, LOG);
}


// void test_from_XML(void) method

void ProbabilisticLayerTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   ProbabilisticLayer  pl;
   TiXmlElement* ple;

   // Test

   pl.from_XML(NULL);

   // Test

   ple = pl.to_XML();

   pl.from_XML(ple);
}


// void run_test_case(void) method

void ProbabilisticLayerTest::run_test_case(void)
{
   message += "Running probabilistic layer test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   // Layer architecture

   test_count_probabilistic_neurons_number();

   // Output variables probabilistic postprocessing

   test_get_probabilistic_layer_flag();

   // Display messages

   test_get_display();

   // Set methods

   test_set();
   test_set_default();

   // Probabilistic postprocessing

   test_set_probabilistic_flag();

   // Display messages

   test_set_display();

   // Neural network initialization methods

   test_initialize_random();

   // Probabilistic post-processing

   test_calculate_outputs();
   test_calculate_Jacobian();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of probabilistic layer test case\n";
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
