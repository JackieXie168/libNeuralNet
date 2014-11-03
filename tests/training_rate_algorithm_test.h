/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   T R A I N I N G   R A T E   A L G O R I T H M   T E S T   C L A S S   H E A D E R                          */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TRAININGRATEALGORITHMTEST_H__
#define __TRAININGRATEALGORITHMTEST_H__

// Unit testing includes

#include "unit_testing.h"

using namespace OpenNN;


class TrainingRateAlgorithmTest : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit TrainingRateAlgorithmTest(void); 


   // DESTRUCTOR

   virtual ~TrainingRateAlgorithmTest(void);


   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Get methods

   void test_get_performance_functional_pointer(void);

   // Training operators

   void test_get_training_rate_method(void);
   void test_get_training_rate_method_name(void);

   // Training parameters

   void test_get_bracketing_factor(void);   
   void test_get_training_rate_tolerance(void);

   void test_get_warning_training_rate(void);

   void test_get_error_training_rate(void);

   // Stopping criteria

   // Reserve training history

   // Training history

   // Utilities

   void test_get_display(void);

   // Set methods

   void test_set(void);
   void test_set_default(void);

   void test_set_performance_functional_pointer(void);

   // Training operators

   void test_set_training_rate_method(void);

   // Training parameters

   void test_set_training_rate_tolerance(void);

   void test_set_warning_training_rate(void);

   void test_set_error_training_rate(void);

    // Utilities

   void test_set_display(void);

   // Training methods

   void test_calculate_directional_point(void);

   void test_calculate_bracketing_triplet(void);

   void test_calculate_fixed_directional_point(void);
   void test_calculate_golden_section_directional_point(void);
   void test_calculate_Brent_method_directional_point(void);
   
   // Serialization methods

   void test_to_XML(void);
   void test_from_XML(void);

   // Unit testing methods

   void run_test_case(void);
};


#endif


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

