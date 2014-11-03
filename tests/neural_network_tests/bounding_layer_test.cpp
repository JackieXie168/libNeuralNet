/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   B O U N D I N G   L A Y E R   T E S T   C L A S S                                                          */
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

#include "../../source/opennn.h"

// Unit testing includes

#include "bounding_layer_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR

BoundingLayerTest::BoundingLayerTest(void) : UnitTesting()
{
}


// DESTRUCTOR

BoundingLayerTest::~BoundingLayerTest(void)
{
}


// METHODS

// void test_constructor(void) method

void BoundingLayerTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor

   BoundingLayer bl1;

   assert_true(bl1.count_bounding_neurons_number() == 0, LOG);

   // Copy constructor

}


// void test_destructor(void)

void BoundingLayerTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_assignment_operator(void)

void BoundingLayerTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   BoundingLayer bl_1;
   BoundingLayer bl_2 = bl_1;

   assert_true(bl_2.count_bounding_neurons_number() == 0, LOG);
}


// void test_get_bounding_neurons_number(void) method

void BoundingLayerTest::test_get_bounding_neurons_number(void)
{
   message += "test_get_bounding_neurons_number\n";

   BoundingLayer bl;

   // Test

   bl.set();
   assert_true(bl.count_bounding_neurons_number() == 0, LOG);

   // Test

   bl.set(1);
   assert_true(bl.count_bounding_neurons_number() == 1, LOG);
}


// void test_set(void) method

void BoundingLayerTest::test_set(void)
{
   message += "test_set\n";
}


// void test_set_default(void) method

void BoundingLayerTest::test_set_default(void)
{
   message += "test_set_default\n";
}


// void test_get_lower_bounds(void) method

void BoundingLayerTest::test_get_lower_bounds(void)
{
   message += "test_get_lower_bounds\n";
}


// void test_get_upper_bounds(void) method

void BoundingLayerTest::test_get_upper_bounds(void)
{
   message += "test_get_upper_bounds\n";
}


// void test_get_lower_bound(void) method

void BoundingLayerTest::test_get_lower_bound(void)
{
   message += "test_get_lower_bound\n";
}


// void test_get_upper_bound(void) method

void BoundingLayerTest::test_get_upper_bound(void)
{
   message += "test_get_upper_bound\n";
}


// void test_get_bounds(void) method

void BoundingLayerTest::test_get_bounds(void)
{
   message += "test_get_bounds\n";
}


// void test_get_display(void) method

void BoundingLayerTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_lower_bounds(void) method

void BoundingLayerTest::test_set_lower_bounds(void)
{
   message += "test_set_lower_bounds\n";
}


// void test_set_upper_bounds(void) method

void BoundingLayerTest::test_set_upper_bounds(void)
{
   message += "test_set_upper_bounds\n";
}


// void test_set_lower_bound(void) method

void BoundingLayerTest::test_set_lower_bound(void)
{
   message += "test_set_lower_bound\n";
}


// void test_set_upper_bound(void) method

void BoundingLayerTest::test_set_upper_bound(void)
{
   message += "test_set_upper_bound\n";
}


// void test_set_bounds(void) method

void BoundingLayerTest::test_set_bounds(void)
{
   message += "test_set_bounds\n";
}


// void test_set_display(void) method

void BoundingLayerTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_initialize_random(void) method

void BoundingLayerTest::test_initialize_random(void)
{
   message += "test_initialize_random\n";

   BoundingLayer bl;

   // Test

   bl.initialize_random();
}


// void test_calculate_outputs(void) method

void BoundingLayerTest::test_calculate_outputs(void)
{
   message += "test_calculate_outputs\n";

   BoundingLayer bl(1);
   bl.set_lower_bound(0, -1.0);
   bl.set_upper_bound(0,  1.0);
   Vector<double> inputs(1);

   // Test

   Vector<double> outputs(1);
   inputs[0] = -2.0; 
   outputs = bl.calculate_outputs(inputs);
   assert_true(outputs.size() == 1, LOG);
   assert_true(outputs == -1.0, LOG);

   // Test

   inputs[0] = 2.0;
   outputs = bl.calculate_outputs(inputs);
   assert_true(outputs.size() == 1, LOG);
   assert_true(outputs == 1.0, LOG);
}


// void test_to_XML(void) method

void BoundingLayerTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   BoundingLayer bl;

   TiXmlElement* blep;

   // Test

   blep = bl.to_XML();

   assert_true(blep != NULL, LOG);
}


// void test_from_XML(void) method

void BoundingLayerTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   BoundingLayer bl;

   TiXmlElement* blep;

   // Test

   bl.from_XML(NULL);

   // Test

   blep = bl.to_XML();

   bl.from_XML(blep);
}


// void test_write_expression(void) method

void BoundingLayerTest::test_write_expression(void)
{
   message += "test_write_expression\n";


}


// void run_test_case(void) method

void BoundingLayerTest::run_test_case(void)
{
   message += "Running bounding layer test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   // Bounding layer architecture

   test_get_bounding_neurons_number();

   // Variables bounds

   test_get_lower_bounds();
   test_get_lower_bound();

   test_get_upper_bounds();
   test_get_upper_bound();

   test_get_bounds();

   // Display messages

   test_get_display();

   // Set methods

   test_set();
   test_set_default();

   // Variables bounds

   test_set_lower_bounds();
   test_set_lower_bound();

   test_set_upper_bounds();
   test_set_upper_bound();

   test_set_bounds();

   // Display messages

   test_set_display();

   // Initialization methods

   test_initialize_random();

   // Lower and upper bounds

   test_calculate_outputs();

   // Expression methods

   test_write_expression();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of bounding layer test case\n";
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
