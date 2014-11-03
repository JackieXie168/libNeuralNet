/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   B O U N D I N G   L A Y E R   T E S T   C L A S S   H E A D E R                                            */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __BOUNDINGLAYERTEST_H__
#define __BOUNDINGLAYERTEST_H__

// OpenNN includes

#include "../unit_testing.h"

#include "../../source/utilities/vector.h"
#include "../../source/utilities/matrix.h"

using namespace OpenNN;

class BoundingLayerTest : public UnitTesting
{

#define STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit BoundingLayerTest(void);


   // DESTRUCTOR

   virtual ~BoundingLayerTest(void);

   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Assignment operators methods

   void test_assignment_operator(void);

   // Get methods

   // PerceptronLayer architecture 

   void test_get_bounding_neurons_number(void);
   
   // Variables bounds

   void test_get_lower_bounds(void);
   void test_get_lower_bound(void);

   void test_get_upper_bounds(void);
   void test_get_upper_bound(void);

   void test_get_bounds(void);

   // Display messages

   void test_get_display(void);

   // SET METHODS

   void test_set(void);
   void test_set_default(void);

   // Variables bounds

   void test_set_lower_bounds(void);
   void test_set_lower_bound(void);

   void test_set_upper_bounds(void);
   void test_set_upper_bound(void);

   void test_set_bounds(void);

   // Display messages

   void test_set_display(void);

   // Initialization methods

   void test_initialize_random(void);

   // Output methods

   void test_calculate_outputs(void);
   void test_calculate_derivative(void);
   void test_calculate_second_derivative(void);


   // Expression methods

   void test_write_expression(void);

   // Serialization methods

   void test_to_XML(void);
   void test_from_XML(void);

   // Unit testing methods

   void run_test_case(void);
};


#endif



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
