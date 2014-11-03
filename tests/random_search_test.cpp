/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   R A N D O M   S E A R C H   T E S T   C L A S S                                                            */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// Unit testing includes

#include "random_search_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR 

RandomSearchTest::RandomSearchTest(void) : UnitTesting()
{
}


// DESTRUCTOR

/// Destructor.

RandomSearchTest::~RandomSearchTest(void)
{
}

// METHODS

void RandomSearchTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   PerformanceFunctional pf;

   // Default constructor

   RandomSearch rs1; 
   assert_true(rs1.has_performance_functional() == false, LOG);

   // Performance functional constructor

   RandomSearch rs2(&pf); 
   assert_true(rs2.has_performance_functional() == true, LOG);
}


void RandomSearchTest::test_destructor(void)
{
   message += "test_destructor\n";
}


void RandomSearchTest::test_get_training_rate_reduction_factor(void)
{
   message += "test_get_training_rate_reduction_factor\n";
}


void RandomSearchTest::test_get_reserve_parameters_history(void)
{
   message += "test_get_reserve_parameters_history\n";
}


void RandomSearchTest::test_get_reserve_parameters_norm_history(void)
{
   message += "test_get_reserve_parameters_norm_history\n";
}


void RandomSearchTest::test_get_reserve_performance_history(void)
{
   message += "test_get_reserve_performance_history\n";
}


void RandomSearchTest::test_set_training_rate_reduction_factor(void)
{
   message += "test_set_training_rate_reduction_factor\n";
}


void RandomSearchTest::test_set_reserve_parameters_history(void)
{
   message += "test_set_reserve_parameters_history\n";
}


void RandomSearchTest::test_set_reserve_parameters_norm_history(void)
{
   message += "test_set_reserve_parameters_norm_history\n";
}


void RandomSearchTest::test_set_reserve_performance_history(void)
{
   message += "test_set_reserve_performance_history\n";
}


void RandomSearchTest::test_calculate_training_direction(void)
{
   message += "test_calculate_training_direction\n";
}


void RandomSearchTest::test_perform_training(void)
{
   message += "test_perform_training\n";

   NeuralNetwork nn;

   PerformanceFunctional pf(&nn);

   RandomSearch rs(&pf);

   RandomSearch::RandomSearchResults* rstr;

   // Test 

   nn.set(1, 1);
   
   pf.destruct_all_terms();
   pf.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

   rs.set_display(false);
   rs.set_maximum_iterations_number(1),

   rs.set_reserve_all_training_history(true);

   rs.set_display_period(1);
   
   rstr = rs.perform_training();

   assert_true(rstr != NULL, LOG);   

   delete rstr;
}


void RandomSearchTest::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   RandomSearch rs;
   rs.set_reserve_all_training_history(true);
}


void RandomSearchTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   RandomSearch rs;

   tinyxml2::XMLDocument* document = rs.to_XML();

   // Test

   document = rs.to_XML();

   assert_true(document != NULL, LOG);

   delete document;
}


void RandomSearchTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   RandomSearch rs1;
   RandomSearch rs2;

   tinyxml2::XMLDocument* document;

   // Test

   rs1.initialize_random();

   document = rs1.to_XML();

   rs2.from_XML(*document);

   delete document;

   assert_true(rs2 == rs1, LOG);
}


void RandomSearchTest::run_test_case(void)
{
   message += "Running random search test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor(); 

   // Get methods

   test_get_training_rate_reduction_factor();

   test_get_reserve_parameters_history();
   test_get_reserve_parameters_norm_history();

   test_get_reserve_performance_history();

   // Set methods

   test_set_training_rate_reduction_factor();

   test_set_reserve_parameters_history();
   test_set_reserve_parameters_norm_history();

   test_set_reserve_performance_history();

   // Training methods

   test_calculate_training_direction();

   test_perform_training();

   // Training history methods

   test_set_reserve_all_training_history();

   // Utiltity methods

   test_to_XML();
   test_from_XML();

   message += "End of random search test case.\n";
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
