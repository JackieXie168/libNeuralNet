/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   P R O B A B I L I S T I C   L A Y E R   T E S T   C L A S S                                                */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

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


void ProbabilisticLayerTest::test_destructor(void)
{
   message += "test_destructor\n";
}


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


void ProbabilisticLayerTest::test_set(void)
{
   message += "test_set\n";
}


void ProbabilisticLayerTest::test_set_default(void)
{
   message += "test_set_default\n";
}


void ProbabilisticLayerTest::test_get_display(void)
{
   message += "test_get_display\n";
}


void ProbabilisticLayerTest::test_set_display(void)
{
   message += "test_set_display\n";
}


void ProbabilisticLayerTest::test_initialize_random(void)
{
   message += "test_initialize_random\n";

   ProbabilisticLayer pl;

   // Test

   pl.initialize_random();
}


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
      inputs.randomize_normal();

      Jacobian = pl.calculate_Jacobian(inputs);
      numerical_Jacobian = nd.calculate_Jacobian(pl, &ProbabilisticLayer::calculate_outputs, inputs);

      assert_true((Jacobian-numerical_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }
}


void ProbabilisticLayerTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   ProbabilisticLayer  pl;
   tinyxml2::XMLDocument* pld;

   // Test

   pl.set();

   pld = pl.to_XML();

   assert_true(pld != NULL, LOG);

   // Test

   pl.set(2);
   pl.set_probabilistic_method(ProbabilisticLayer::Competitive);
   pl.set_display(false);

   pld = pl.to_XML();

   pl.set(0);

   pl.from_XML(*pld);

   assert_true(pl.get_probabilistic_neurons_number() == 2, LOG);
   assert_true(pl.get_probabilistic_method() == ProbabilisticLayer::Competitive, LOG);
   assert_true(pl.get_display() == false, LOG);

   delete pld;
}


void ProbabilisticLayerTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   ProbabilisticLayer  pl;
   tinyxml2::XMLDocument* pld;

   // Test

   pld = pl.to_XML();

   pl.from_XML(*pld);

   delete pld;
}


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

   // Display messages

   test_get_display();

   // Set methods

   test_set();
   test_set_default();

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

   message += "End of probabilistic layer test case.\n";
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
