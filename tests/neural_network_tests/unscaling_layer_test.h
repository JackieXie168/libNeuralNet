/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   U N S C A L I N G   L A Y E R   T E S T   C L A S S   H E A D E R                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __UNSCALINGLAYERTEST_H__
#define __UNSCALINGLAYERTEST_H__

// OpenNN includes

#include "../unit_testing.h"

#include "../../source/utilities/matrix.h"
#include "../../source/utilities/matrix.h"

using namespace OpenNN;


class UnscalingLayerTest : public UnitTesting
{

#define STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit UnscalingLayerTest(void);


   // DESTRUCTOR

   virtual ~UnscalingLayerTest(void);

   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Assignment operators methods

   void test_assignment_operator(void);

   // Get methods

   // MultilayerPerceptron architecture 

   void test_count_unscaling_neurons_number(void);

   // Statistics

   void test_get_minimums(void);
   void test_get_minimum(void);

   void test_get_maximums(void);
   void test_get_maximum(void);

   void test_get_means(void);
   void test_get_mean(void);

   void test_get_standard_deviations(void);
   void test_get_standard_deviation(void);

   void test_get_means_standard_deviations(void);
   void test_get_minimums_maximums(void);

   void test_get_statistics(void);

   // Variables scaling and unscaling

   void test_get_unscaling_method(void);
   void test_get_unscaling_method_name(void);

   // Display warning 

   void test_get_display_warning(void);

   // Display messages

   void test_get_display(void);

   // SET METHODS

   void test_set(void);
   void test_set_default(void);

   // Output variables statistics

   void test_set_means(void);
   void test_set_mean(void);

   void test_set_standard_deviations(void);
   void test_set_standard_deviation(void);

   void test_set_minimums(void);
   void test_set_minimum(void);

   void test_set_maximums(void);
   void test_set_maximum(void);

   void test_set_means_standard_deviations(void);
   void test_set_minimums_maximums(void);

   // Statistics

   void test_set_statistics(void);

   // Variables scaling and unscaling

   void test_set_unscaling_method(void);

   // Display messages

   void test_set_display_outputs_warning(void);
   void test_set_display(void);

   // Initialization methods

   void test_initialize_random(void);

   // Input range

   void test_check_outputs_range(void);

   // Outputs unscaling

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
